import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import networkx as nx
from parse_farm import parse_map_from_file, Map, Room, Edge
from parse_solution import parse_solution_from_file
import numpy as np
import sys

base_room_fill_color = '#b5b8bd'
base_edge_color = '#82868c'
bg_color = '#110026'
start_room_color = '#2bffce'
finish_room_color = '#ffab03'
room_size = 500
speed = 10
ant_colors = ['#ff00dd', '#ff007b', '#ff0048', '#2400c4', '#8f63db', '#026e04']


def create_rooms_edges(farm_map):
    rooms = {room.name: (room.x, room.y) for room in farm_map.rooms}
    edges = {(edge.begin.name, edge.end.name) for edge in farm_map.edges}
    start_room_name = farm_map.start_room.name
    finish_room_name = farm_map.finish_room.name
    return rooms, edges, start_room_name, finish_room_name


def create_nx_graph(rooms_dict, edges_dict):
    graph_ = nx.Graph()
    graph_.add_nodes_from(rooms_dict.keys())
    graph_.add_edges_from(edges_dict)
    return graph_


def create_ants_colors(ant_paths, ant_colors_):
    ants_colors_ = {}
    for i, ant in enumerate(ant_paths.keys()):
        color = ant_colors[i % len(ant_colors_)]
        ants_colors_[ant] = color
    return ants_colors_


def create_movements(ants_paths):
    ants_moves = {}
    n_frames = 0
    for ant_name in ants_paths.keys():
        ant_movements = []
        for i in range(len(ant_paths[ant_name]) - 1):
            from_x = rooms[ant_paths[ant_name][i]][0]
            from_y = rooms[ant_paths[ant_name][i]][1]
            to_x = rooms[ant_paths[ant_name][i + 1]][0]
            to_y = rooms[ant_paths[ant_name][i + 1]][1]
            move_x = np.linspace(from_x, to_x, speed)
            move_y = np.linspace(from_y, to_y, speed)
            move_x = np.hstack([from_x * np.ones(int(speed / 2)), move_x])
            move_y = np.hstack([from_y * np.ones(int(speed / 2)), move_y])
            ant_movements.append((move_x, move_y))
        ants_moves[ant_name] = ant_movements
    for ant_name in ants_paths.keys():
        move_x = ants_moves[ant_name][0][0]
        move_y = ants_moves[ant_name][0][1]
        for i in range(1, len(ants_moves[ant_name])):
            move_x = np.hstack([move_x, ants_moves[ant_name][i][0]])
            move_y = np.hstack([move_y, ants_moves[ant_name][i][1]])
        ants_moves[ant_name] = (move_x, move_y)
        n_frames = len(move_x)
    return ants_moves, n_frames


def update(num, farm_graph, ants_movements, start_room_name_, finish_room_name_, ants_colors):
    fig.clear()
    nx.draw_networkx_nodes(farm_graph, rooms, nodelist=[room_name for room_name in rooms.keys()
                                                        if room_name not in [start_room_name_, finish_room_name_]],
                           node_color=base_room_fill_color, node_size=room_size)
    nx.draw_networkx_nodes(farm_graph, rooms, nodelist=[start_room_name_], node_color=start_room_color,
                           node_size=room_size * 2.5)
    nx.draw_networkx_nodes(farm_graph, rooms, nodelist=[finish_room_name_], node_color=finish_room_color,
                           node_size=room_size * 2.5)
    nx.draw_networkx_edges(farm_graph, rooms, edge_color=base_edge_color)
    fig.set_facecolor(bg_color)
    plt.axis('off')
    for ant_name in ants_movements.keys():
        a_color = ants_colors[ant_name]
        plt.plot([ants_movements[ant_name][0][num]], [ants_movements[ant_name][1][num]], markersize=20.0, marker='.',
                 color=a_color)


plt.show()

if __name__ == '__main__':
    map_file_name, solution_file_name = sys.argv[1], sys.argv[2]
    farm_map, ants_count = parse_map_from_file(map_file_name)
    ant_paths = parse_solution_from_file(solution_file_name, ants_count, farm_map)
    rooms, edges, start_room_name, finish_room_name = create_rooms_edges(farm_map)
    nx_graph = create_nx_graph(rooms, edges)
    ants_colors_dict = create_ants_colors(ant_paths, ant_colors)
    movements, frames_number = create_movements(ant_paths)
    fig = plt.figure(figsize=(15, 7))
    ani = FuncAnimation(fig,
                        update,
                        frames=frames_number,
                        fargs=[nx_graph,
                               movements,
                               start_room_name,
                               finish_room_name,
                               ants_colors_dict
                               ], interval=1)
    plt.show()
