//
// Created by Olcay Taner YILDIZ on 23.02.2023.
//

#ifndef DICTIONARY_POS_H
#define DICTIONARY_POS_H

enum pos {
/**
 * Adjective.
 */
    ADJECTIVE_POS,
/**
* Noun.
*/
    NOUN_POS,
/**
* Verb.
*/
    VERB_POS,
/**
* Adverb.
*/
    ADVERB_POS,
/**
* Conjunction.
*/
    CONJUNCTION_POS,
/**
* Interjection.
*/
    INTERJECTION_POS,
/**
* Preposition.
*/
    PREPOSITION,
/**
* Pronoun.
*/
    PRONOUN_POS
};

typedef enum pos Pos;

#endif //DICTIONARY_POS_H
