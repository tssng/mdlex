#include "graph.h"

namespace nsgraph {

Graph::Graph(const size_t num_nodes) {
    nodes.reserve(num_nodes);
    vector<vector<uint32_t>> link_pool_per_layer.resize(5); // start with 5 layers
}

Graph::~Graph() {}

const Node& Graph::getNode(const uint32_t node_id) {
    return nodes[node_id];
}

void addNode Graph::addNode(const Node& node, const uint32_t layer_num) {
    link_pool_per_layer[layer_num].push_back(node.node_id);
    nodes.push_back(std::move(node));
}

std::span<uint32_t> Graph::getNeighbours(const uint32_t node_id, const uint32_t layer_num) {
    LinkInfo cur_link = nodes[node_id].layer_link_info[layer_num]
    std::span<const uint32_t> full_span(link_pool_per_layer[layer_num]);

    return full_span.subspan(cur_link.offset, cur_link.link_count);
}

void Graph::addLink(const uint32_t frst_id, const uint32_t scnd_id, const uint32_t layer_num) {

}






} // nsgraph