/* Intranet
 *
 * A distributed internet where data and data transfer is not centralized,
 * removing a single corporation or government's control on the internet.
 * A worldwide intranet.
 */

/* Blockchain
 *
 * A table of data with a listing of websites and the nodes that each 
 * website belongs to.
 */

/* Site
 * 
 * An entire webpage or website that is compressed and striped accross
 * the intranet.
 */

/* Block
 *
 * A piece of the compressed data that makes up said website
 */

/* Server ?
 * 
 * Contains a blockchain, blockchain might be too large for everyone to own
 */

/* Client
 *
 * Queries the blockchain, then 'torrents' the website from the appropriate
 * and available nodes.
 */

/* Problems
 *
 * Participation (Recycle old computers ?)
 * Blockchain location? (Centralized server, against idea)
 * Website scraping
 */

#include <map>
#include <list>
#include <string>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

class Blockchain;
class Site;
class Node;
class ThreadManager;
class Thread;
class Gatherer;
class Distributor;

class Thread
{
public:
      void run()
      {
            pthread_create(thread, NULL, work, args);
            running = true;
      };
      void join()
      {
            if (running)
                  pthread_join(*thread, NULL);
            running = false;
      }
      virtual void *work(void *);
protected:
      pthread_t *thread;
      bool running;
      void *args;
      void *ret;
};

class ThreadManager
{
public:
      ThreadManager() {};
      ~ThreadManager() {};
      void add(Thread *thread)
      {
            threads.push_back(thread);
            thread->run();
      };
      void wait()
      {
            for (std::list<Thread *>::iterator iter = threads.begin(); iter != threads.end(); ++iter)
            {
                  Thread *thread = *iter;
                  thread->join();
            }
      };
private:
      std::list<Thread *> threads;
};


class Gatherer : public Thread
{
public:
      Gatherer(Node &node, void *data) {};
      ~Gatherer() {};
      void *work(void *args)
      {
            assert(args != NULL);
            return NULL;
      };
      
};

class Distributor : public Thread
{
public:
      Distributor(Node &node) {};
      ~Distributor() {};
      void *work(void *args)
      {
            assert(args != NULL);
            return NULL;
      };
      
};

class Node
{
public:
      Node(void *data, size_t offset, size_t size)
      {
            this->data = (char*)data + offset; // All private vars, consider constructor
            this->size = size;
            this->offset = offset;
            this->writeable = true;
            this->readable = true;
      };
      ~Node()
      {
            if (data != NULL)
                  free(data);
      };
private:
      uint64_t id;
      // Some ip address, how to contact said Node
      void *data;
      size_t size;
      size_t offset;
      bool writeable; // Only writeable when malloc'd space for data (Distributor phase) ?? Maybe not needed
      bool readable;  // Only readable when malloc'd space and data written (Gatherer phase)
};

class Site
{
public:
      Site(void *data, size_t size)
      {
            this->data = data;
            this->size = size;
      };
      ~Site()
      {
            if (blockids != NULL)
                  free(blockids);
            if (data != NULL)
                  free(data);
            for (std::map<uint64_t, std::list<Node *> >::iterator iter = nodes.begin(); iter != nodes.end(); ++iter)
            {
                  std::list<Node *> node_list = iter->second;
                  for (std::list<Node *>::iterator iter2 = node_list.begin(); iter2 != node_list.end(); ++iter2)
					  delete iter2->second;
            }
      };
      void *gather()
      {
            ThreadManager thread_manager();
            data = malloc(size);
            for (int i = 0; i < num_blockids; ++i)
            {
                  std::list<Node *>::iterator node = nodes.find(blockids[i])->second; // We have a real problem if its not found in this map
                  thread_manager.add(new Gatherer(*node, &data));
            }
            thread_manager.wait();
            return data;
      };
      void distribute()
      {
            ThreadManager thread_manager();
            size_t chunk_size = 4; // Should be a weighted calculation somehow
            this->size = size;
            for (uint64_t wptr = 0; wptr < size; ++wptr)
            {
                  size_t offset = wptr * chunk_size; // TODO: Make sure this doesn't run off the end
                  size_t write_size = chunk_size; // TODO: ^^^^
                  Node *node = new Node(data, offset, size);
                  thread_manager.add(new Distributor(node));
            }
            thread_manager.wait();
      };
private:
      uint64_t  id;
      uint64_t *blockids;
      int       num_blockids;
      void     *data;
      size_t    size;
      std::map<uint64_t, std::list<Node *> > nodes;
};

class Blockchain
{
public:
      Blockchain() {};
      ~Blockchain() 
      {
            for (std::map<std::string, Site *>::iterator iter = sites.begin(); iter != sites.end(); ++iter)
            {
                  Site *site = iter->second;
                  delete site;
            }
      };
      void *lookup(std::string query)
      {
            std::map<std::string, Site *>::iterator *iter = sites.find(query);
            if (iter == sites.end())
                  return NULL; // Wasn't found in database
            Site *site = iter->second;
            return site->gather();
      };
      void insert(std::string query, void *data, size_t size)
      {
            Site *site = new Site(data, size);
            site->distribute();
            sites[query] = site;
      };
private:
      std::map<std::string, Site *> sites;
};

int main(void)
{
      // Start SSH session
      return 0;
}
