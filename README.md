Cirrus Distributed Cloud
==============

#Coding Style
    For some CDC class, CDCExample, every function definition must follow:
	    CDCExample_nameOfFunction(args)
	Camel Case function name starting lowercase, underscore = scope
	The only exception to this rule is the constructors and desctructors:
		new_CDCExample()
		delete_CDCExample(CDCExample *)
	
	CDCError should be returned where appropriate.

#Client side

##Nodechain
	contains a list of all nodes in the cloud

##Nodetable
	a string table that maps local files to a list of ip addresses (Nodelist)
       |
        \ - Nodelist - a list of ip addresses
      
##Gatherer
	  A worker thread manager for collecting the right data from the cloud, takes a nodelist

##Distributor
	A worker thread manager for distributing the right data to the cloud, makes a nodelist and inserts it into the Nodetable

#Server side

#Server
	Accepts requests and spawns a thread to fufill the request
    Spawns thread to ping requestor for updated Nodechain

