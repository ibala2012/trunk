import graph as gr


def main():
    a = gr.Graph.create_graph_from_file('../test_data/abc.txt')
    print a.bfs_dfs_method("bfs")
    print a.bfs_dfs_method("dfs")
    print "test"
if __name__ == '__main__':
    main()
