#ifndef NODE_HPP
#define NODE_HPP
#include "Nokta.hpp"


class Node{
		public:
			Nokta item;
			Node *next;
			Node( Nokta item,Node *nx=NULL);
};


#endif