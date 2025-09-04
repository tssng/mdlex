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
		std::vector<vector<uint32_t>> link_pool_per_layer; // pool of links per layer

	public:
        Graph(const size_t num_nodes);
        ~Graph();
		const Node& getNode(const uint32_t node_id);
		void addNode(const uint, const uint32_t layer_num);
		std::span<uint32_t> getNeighbours(const uint32_t node_id, const uint32_t layer_num);
		void addLink(const uint32_t frst_id, const uint32_t scnd_id, const uint32_t layer_num);

		// void deleteNode(uint32_t node_id) //TODO: implement later with tombstones
		// maybe if you are adding a link, first check if there is an existing neighbour with a tombstone
		// then, the insertion is equivalent to a value swap with that "dead" node
};

/*
	LinkInfo is a basic wrapper for the offset into the link pool + the degree of a node in a given layer
*/
struct LinkInfo {
	uint32_t offset;
	uint32_t link_count;
};

/*
	Node provides basic structure for nodes/data -> does not store the vector/embedding data directly
*/
struct Node {
    uint32_t id;
	std::vector<LinkInfo> layer_link_info;
};

} // nsgraph

#endif //GRAPH_H
