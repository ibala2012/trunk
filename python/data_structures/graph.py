class Node(object):
    def __init__(self, data):
        self.name = data
        self.children = {}

    def add_child(self, name, weight):
        self.children[name] = weight

    def get_children_names(self):
        return self.children.keys()

    def get_child(self, name):
        if name in self.children:
            return (name, self.children[name])
        return None

    def has_child(self, name):
        return (name in self.children)

    def get_name(self):
        return self.name


class Graph(object):

    def __init__(self, nodes, adjacency_matrix):
        self.nodes = nodes
        self.graph_nodes = {}
        self.root_node = self.add_node_details(self.nodes[0], adjacency_matrix[0][1:])
        temp = adjacency_matrix[1:]
        temp_nodes = self.nodes[1:]
        for i in xrange(0, len(temp)):
            self.add_node_details(temp_nodes[i], temp[i][1:])

    @classmethod
    def create_graph_from_file(cls, file_name):
        with open(file_name, 'r') as f:
            # reading the adjancency file and loading the content in the variable data
            data = f.readlines()
            adj_matrix = [d.replace('\n', '') for d in data[1:]]
            return cls(data[0].split('\n')[0].split(' '), adj_matrix)

    def add_node_details(self, name, data):
        current_node = Node(name)
        data = data.split(' ')
        data = [d for d in data if len(d.strip()) > 0]
        for i in xrange(0, len(data)):
            if int(data[i]) > 0:
                current_node.add_child(self.nodes[i], data[i])
        self.graph_nodes[name] = current_node
        return current_node

    def bfs_dfs_method(self, traversal_method="bfs"):
        visited_nodes = {}
        process_nodes = []
        process_sequence = []
        current_node = self.root_node
        process_nodes.append(self.root_node.get_name())
        i = 0
        while(i < len(process_nodes)):
            print process_nodes[i]
            current_node = self.graph_nodes[process_nodes[i]]
            if current_node.get_name() not in visited_nodes:
                visited_nodes[current_node.get_name()] = True
                process_sequence.append(current_node.get_name())
            i = i + 1
            for d in current_node.get_children_names():
                if d not in visited_nodes and d not in process_nodes:
                    # Queue is effectively FIFO, so simple append should be enough here
                    if traversal_method == "bfs":
                        process_nodes.append(d)
                    elif traversal_method == "dfs":
                        process_nodes.insert(i, d)
        return process_sequence

    def dijkstra_shortes_path(self):
        return 1
