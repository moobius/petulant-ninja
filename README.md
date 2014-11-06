petulant-ninja
==============
Cirrus Distributed Cloud

# Client side

// Maybe this should be split up into two seperate data structures, one part
// is associated to the cloud and the other local.
Nodechain - contains a list of all nodes in the cloud

Nodetable - a string table that maps local files to a list of ip addresses (Nodelist)
       |
        \ - Nodelist - a list of ip addresses
      
Gatherer - A worker thread manager for collecting the right data from the cloud, takes a nodelist

Distributor - A worker thread manager for distributing the right data to the cloud, makes a nodelist and inserts it into the Nodetable

### ### ### ### ### ### ### ### ### ### ### ###
### ### ### ### ### ### ### ### ### ### ### ###

# Server side

Server - Accepts requests and spawns a thread to fufill the request
       - Spawns thread to ping requestor for updated Nodechain
