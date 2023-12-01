from random import shuffle

max_sportsmen = 100000

numbers = [x for x in range(max_sportsmen)]

shuffle(numbers)

with open('../cmake-build-release/input.txt', 'w') as file:
    for i in range(1, max_sportsmen):
        file.write(f'{numbers[i - 1]} {numbers[i]}\n')

    number_out_of_scope = max_sportsmen + 1
    file.write(f'{numbers[i]} {number_out_of_scope}\n')
