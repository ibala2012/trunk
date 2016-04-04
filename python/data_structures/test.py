import graph as gr


def main():
    a = gr.Graph.create_graph_from_file('../test_data/abc.txt')
    print a.breadth_first_search()
    print a.depth_first_search()


if __name__ == '__main__':
    main()
