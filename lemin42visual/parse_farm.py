from dataclasses import dataclass

@dataclass
class Room:
    name: str
    x: int
    y: int


@dataclass
class Edge:
    begin: Room
    end: Room


@dataclass
class Map:
    rooms: list
    edges: list
    start_room: Room = None
    finish_room: Room = None


def is_comment(line):
    if line[0] == '#':
        if len(line) == 1:  # line with only comment symbol
            return True
        else:
            if line[1] != '#':  # not command line
                return True
    return False


def is_edge(line):
    return ' ' not in line and '-' in line


def parse_room_line(line):
    room_lines = line.split()
    return Room(name=room_lines[0], x=int(room_lines[1]), y=(int(room_lines[2])))


def find_room_in_list(room_name, room_list):
    for i in range(len(room_list)):
        if room_list[i].name == room_name:
            return i


def parse_edge(line, room_list):
    edge_lines = line.split('-')
    begin_room_name = edge_lines[0]
    end_room_name = edge_lines[1][:-1]
    begin_room_index = find_room_in_list(begin_room_name, room_list)
    end_room_index = find_room_in_list(end_room_name, room_list)
    return Edge(begin=room_list[begin_room_index], end=room_list[end_room_index])


def parse_map_from_file(filename: str) -> (Map, int):
    with open(filename, 'r') as file:
        lines = file.readlines()
    ants_count = int(lines[0])
    rooms = []
    edges = []
    lines = lines[1:]
    is_start = False
    is_finish = False
    start_room = None
    finish_room = None
    for i, line in enumerate(lines):
        if line == "##start\n":
            is_start = True
            continue
        if line == "##end\n":
            is_finish = True
            continue
        if is_comment(line):
            continue
        if not is_edge(line):
            room = parse_room_line(line)
            if is_start:
                start_room = room
                is_start = False
            if is_finish:
                finish_room = room
                is_finish = False
            rooms.append(room)
        else:
            edge = parse_edge(line, rooms)
            edges.append(edge)
    return Map(rooms, edges, start_room, finish_room), ants_count


