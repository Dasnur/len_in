# "lem_in" Ant farm manager (Algorithm for finding non-intersecting paths)
* [Описание алгоритма](#Описание_алгоритма)
* [Как запустить](#Старт)

**Задача:**
Перевести N муравьев от комнаты начала к конечной комнате, за минимальное количество ходов.

**Условия:**
* В одной комнате не может находится одновременно несколько муравьев, кроме комнат начала и конца.
* В каждый ход муравей может передвигаться из одной комнаты в другую, соединенную с ней.

**Входные данные:**
Карта в формате:
* number_of_ants
* the_rooms
* the_links

**Формат комнат:**
* №room x y

x, y - координаты для отрисовки

**Формат связей комнат:**
* room1-room2
* \# - символ после, после которого идет комментарий
* \## - после идут команты типа "start", "end", наличие данной метки перед комнатой определяет ее как вход или выход

**Выходные данные:**
* Исходная карта
* Описание положение муравьев на каждом шаге в формате:
  * Lx-y Lz-w Lr-o, где x, z, r - номер муравья, y, w, o - имена комнат, в которых находится соответсвующий муравей по оканчании хода
_____
<a name="Описание_алгоритма"></a> 
**Описание алгоритма**
В основе алгоритма лежит поиск пути на основе алгоритма Беллмана-Форда, получение ребер с отрицательным весом, и прогон Беллмана-Форда в цикле на том же графе, для поиска следующего кратчайшего пути.
На выходе получается группа непересекайшихся путей, после чего, на основе количества имеющихся муравьев, принмается решение о том, сколько путей использовать.

Для 3 муравьев используется один кратчайший путь длины 3
![doPgjojmai](https://user-images.githubusercontent.com/45533581/102256885-04ad4d80-3f1d-11eb-8c93-af2ba20ccc70.gif)

Для 6 муравьев используется два непересекающихся пути длины 4
![1UCt3E4OKF](https://user-images.githubusercontent.com/45533581/102263949-07607080-3f26-11eb-9296-ecfcc42eb25e.gif)

Визуализация выполнена на Python в папке lemin42visual запустить visualize.py с параметрами:
1. описание карты.
2. решение в виде ходов муравьев, которое выдает программа.
__________
<a name="Старт"></a>
**Старт**
* Выполните make в склоненной папке
* Имя исполняемого файла lem-in
* Запуск просиходит в виде ./lem-in < "name_of_map"
