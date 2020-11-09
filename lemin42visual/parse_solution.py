from parse_farm import parse_map_from_file
import re


def parse_solution_from_file(filename, ants_count, farma):
    start_room_name = farma.start_room.name
    end_room_name = farma.finish_room.name
    with open(filename, 'r') as file:
        lines = file.readlines()
    ants_pathes = {}
    for ant_number in range(1, ants_count + 1):
        ants_pathes[str(ant_number)] = [start_room_name]
    for ant_number in range(1, ants_count + 1):
        regexp = re.compile(fr"L{ant_number}-([\d\w]+)")
        was_end = False
        for line in lines:
            room = regexp.findall(line)
            if room:
                ants_pathes[str(ant_number)].append(room[0])
                if room[0] == end_room_name:
                    was_end = True
            else:
                if was_end:
                    ants_pathes[str(ant_number)].append(end_room_name)
                else:
                    ants_pathes[str(ant_number)].append(start_room_name)

    return ants_pathes
