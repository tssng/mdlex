#include <cstdint.h>


#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>

namespace nsgraph {

/*
	Graph provides a way to create a hierarchy of layers of nodes + simple methods for adding links/nodes
*/

class Graph {
	private:
		std::vector<Node> nodes; // pool of nodes to avoid storage amp across layers
		std::vector<std::vector<uint32_t>> link_pool_per_layer; // pool of links per layer
	public:
		void getNode(const uint32_t node_id);
		void addNode(const Node& node, const uint32_t layer_num);

		// void deleteNode(uint32_t node_id) //TODO: implement later with tombstones
};

/*
	LinkInfo is a basic wrapper for the offset into the vector data container + the degree of a node in a given layer
*/
struct LinkInfo {
	uint32_t offset;
	uint32_t link_count;
};

/*
	Node provides basic structure for nodes/data -> does not store the vector/embedding data directly
*/
struct Node {
	std::vector<LinkInfo> links;
};

} // nsgraph

#endif //GRAPH_H
