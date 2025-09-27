cmake_minimum_required(VERSION 3.23)
project(Dictionary)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

find_package(math_c REQUIRED)
find_package(data_structure_c REQUIRED)

add_library(Dictionary Language/Language.h Language/EnglishLanguage.h Language/TurkishLanguage.c Language/TurkishLanguage.h Syllibification/Syllable.c Syllibification/Syllable.h Syllibification/SyllableList.c Syllibification/SyllableList.h Dictionary/Word.c Dictionary/Word.h Dictionary/Pos.h Dictionary/TxtWord.c Dictionary/TxtWord.h Dictionary/ExceptionalWord.c Dictionary/ExceptionalWord.h Dictionary/VectorizedWord.c Dictionary/VectorizedWord.h Dictionary/Trie/TrieNode.c Dictionary/Trie/TrieNode.h Dictionary/Trie/Trie.c Dictionary/Trie/Trie.h Dictionary/Dictionary.c Dictionary/Dictionary.h Dictionary/TxtDictionary.c Dictionary/TxtDictionary.h Dictionary/VectorizedDictionary.c Dictionary/VectorizedDictionary.h)
target_link_libraries(Dictionary math_c::math_c data_structure_c::data_structure_c m)
