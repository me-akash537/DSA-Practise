#pragma once
void print_dist_matrix(int count, std::vector<std::vector<double>> &dist);

void obtain_sorted_pairs(int count, std::vector<std::pair<double, std::pair<int, int>>> &edges, std::vector<std::vector<double>> &dist);

void print_edge_pairs(std::vector<std::pair<double, std::pair<int, int>>> &edges);
