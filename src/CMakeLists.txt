cmake_minimum_required(VERSION 3.23)
project(Dictionary C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(Dictionary src/Language/Language.h src/Language/EnglishLanguage.h src/Language/TurkishLanguage.c src/Language/TurkishLanguage.h src/Syllibification/Syllable.c src/Syllibification/Syllable.h src/Syllibification/SyllableList.c src/Syllibification/SyllableList.h src/Dictionary/Word.c src/Dictionary/Word.h src/Dictionary/Pos.h src/Dictionary/TxtWord.c src/Dictionary/TxtWord.h src/Dictionary/ExceptionalWord.c src/Dictionary/ExceptionalWord.h src/Dictionary/VectorizedWord.c src/Dictionary/VectorizedWord.h src/Dictionary/Trie/TrieNode.c src/Dictionary/Trie/TrieNode.h src/Dictionary/Trie/Trie.c src/Dictionary/Trie/Trie.h src/Dictionary/Dictionary.c src/Dictionary/Dictionary.h src/Dictionary/TxtDictionary.c src/Dictionary/TxtDictionary.h src/Dictionary/VectorizedDictionary.c src/Dictionary/VectorizedDictionary.h)
target_link_libraries(Dictionary ${CONAN_LIBS})
