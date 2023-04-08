project(DoubleLinkedList)

add_library(DoubleLinkedList)
target_sources(DoubleLinkedList PRIVATE src/double_linked_list.c)
target_include_directories(DoubleLinkedList PUBLIC inc)


add_executable(TestDoubleLinkedList)
target_sources(TestDoubleLinkedList PRIVATE main.c)
target_link_libraries(TestDoubleLinkedList PRIVATE DoubleLinkedList)
