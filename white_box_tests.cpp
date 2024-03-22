//======= Copyright (c) 2024, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - test suite
//
// $NoKeywords: $ivs_project_1 $white_box_tests.cpp
// $Author:     Timur Kininbayev <xkinin00@stud.fit.vutbr.cz>
// $Date:       $2024-02-14
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author Timur Kininbayev
 * 
 * @brief Implementace testu hasovaci tabulky.
 */

#include <vector>

#include "gtest/gtest.h"

#include "white_box_code.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy hasovaci tabulky, testujte nasledujici:
// 1. Verejne rozhrani hasovaci tabulky
//     - Vsechny funkce z white_box_code.h
//     - Chovani techto metod testuje pro prazdnou i neprazdnou tabulku.
// 2. Chovani tabulky v hranicnich pripadech
//     - Otestujte chovani pri kolizich ruznych klicu se stejnym hashem 
//     - Otestujte chovani pri kolizich hashu namapovane na stejne misto v 
//       indexu
//============================================================================//

//============================= hash_map_ctor  ===============================//
//test on successful creation of a hash map
TEST(HashMapCtor, ConstructorSuccess) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map); //check that returned pointer is not null
    EXPECT_EQ(map->allocated, HASH_MAP_INIT_SIZE); //check that the initial size is correct

    hash_map_dtor(map);
}

//============================= hash_map_dtor  ===============================//
TEST(HashMapDtor, DestructorSuccess) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    hash_map_put(map, "key", 22);
    hash_map_dtor(map);
    //basically we just want to check that the destructor does not crash
}

//============================= hash_map_clear  ===============================//
TEST(HashMapClear, ClearEmptyMap) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    hash_map_clear(map);

    ASSERT_EQ(map->first, nullptr);
    ASSERT_EQ(map->last, nullptr);
    ASSERT_EQ(map->used, 0);

    hash_map_dtor(map);
}

//test on successful clearing of a non-empty map
TEST(HashMapClear, ClearNonEmptyMap) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    hash_map_put(map, "key1", 1);
    hash_map_put(map, "key2", 2);
    hash_map_clear(map);

    ASSERT_EQ(map->first, nullptr);
    ASSERT_EQ(map->last, nullptr);
    ASSERT_EQ(map->used, 0);

    //check that all elements were correctly deleted and index cleared
    for (size_t i = 0; i < map->allocated; ++i)
        ASSERT_EQ(map->index[i], nullptr);

    hash_map_dtor(map);
}

//============================= hash_map_reserve  ===============================//
//test that the function returns VALUE_ERROR if the new size is less than the number of elements
TEST(HashMapReserve, ReduceBelowUsed) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    hash_map_put(map, "key1", 1);
    hash_map_put(map, "key2", 2);
    hash_map_put(map, "key3", 3);

    size_t sizeBelowUsed = hash_map_size(map) - 1;
    ASSERT_EQ(hash_map_reserve(map, sizeBelowUsed), VALUE_ERROR);

    hash_map_dtor(map);
}

//test that the function returns OK if the new size is equal to the current allocated size
TEST(HashMapReserve, SetToCurrentAllocated) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    size_t currentAllocated = map->allocated;
    ASSERT_EQ(hash_map_reserve(map, currentAllocated), OK);

    hash_map_dtor(map);
}

//test that the function returns OK and the allocated size is increased
TEST(HashMapReserve, IncreaseSizeSuccessfully) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    size_t newSize = map->allocated + 42; //increase the size by random value
    ASSERT_EQ(hash_map_reserve(map, newSize), OK);
    ASSERT_EQ(map->allocated, newSize);

    hash_map_dtor(map);
}

//============================= hash_map_capacity ===============================//
//test that the capacity is equal to the initial size
TEST(HashMapCapacity, InitialCapacity) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    size_t initialCapacity = hash_map_capacity(map);
    EXPECT_EQ(initialCapacity, HASH_MAP_INIT_SIZE);

    hash_map_dtor(map);
}

//test that the capacity is equal to the new size after reserve
TEST(HashMapCapacity, CapacityAfterReserve) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    size_t newCapacity = HASH_MAP_INIT_SIZE + 42; //increase the size by random value
    hash_map_state_code_t result = hash_map_reserve(map, newCapacity);
    ASSERT_EQ(result, OK);

    size_t capacityAfterReserve = hash_map_capacity(map);
    EXPECT_EQ(capacityAfterReserve, newCapacity);

    hash_map_dtor(map);
}

//============================= hash_map_size  ===============================//
//test that the size is 0 after initialization
TEST(HashMapSize, InitialSize) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    size_t initialSize = hash_map_size(map);
    EXPECT_EQ(initialSize, 0); //expecting the size to be 0 after initialization

    hash_map_dtor(map);
}

//test that the size is equal to the number of elements after insert
TEST(HashMapSize, SizeAfterInsert) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    hash_map_put(map, "key1", 1);
    hash_map_put(map, "key2", 2);

    size_t expectedSize = 2;
    size_t actualSize = hash_map_size(map);
    EXPECT_EQ(actualSize, expectedSize);

    hash_map_dtor(map);
}

//===================================hash_map_contains========================//
//test if map contains inserted key
TEST(HashMapContains, ContainsExistingKey) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    hash_map_put(map, "key1", 100);
    
    bool contains = hash_map_contains(map, "key1");
    EXPECT_TRUE(contains);

    hash_map_dtor(map);
}

//test if map does not contain a key that was not added
TEST(HashMapContains, ContainsNonexistentKey) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);
    
    bool contains = hash_map_contains(map, "nonexistent_key");
    EXPECT_FALSE(contains);

    hash_map_dtor(map);
}

//===============================hash_map_put=================================//
//test on successful addition of a new item
TEST(HashMapPut, PutNewItem) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    hash_map_state_code_t result = hash_map_put(map, "key1", 100);
    EXPECT_EQ(result, OK);

    //check that the size increased
    size_t size = hash_map_size(map);
    EXPECT_EQ(size, 1);

    hash_map_dtor(map);
}

//test that the function returns KEY_ALREADY_EXISTS if the key is already in the map
TEST(HashMapPut, UpdateExistingItem) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    //put the same key twice with different values
    hash_map_put(map, "key1", 100);
    hash_map_state_code_t result = hash_map_put(map, "key1", 200);
    EXPECT_EQ(result, KEY_ALREADY_EXISTS);

    //check that the size remained the same
    size_t size = hash_map_size(map);
    EXPECT_EQ(size, 1);

    //check that the value was updated
    int value = 0;
    hash_map_get(map, "key1", &value);
    EXPECT_EQ(value, 200); 

    hash_map_dtor(map);
}

//===============================hash_map_get=================================//
//test on successful retrieval of a value
TEST(HashMapGet, GetValueSuccess) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    //inserting an item to check the retrieval
    hash_map_put(map, "key1", 100);

    int value = 0;
    hash_map_state_code_t result = hash_map_get(map, "key1", &value);
    EXPECT_EQ(result, OK);
    EXPECT_EQ(value, 100);

    hash_map_dtor(map);
}

//test on getting a value for a non-existent key
TEST(HashMapGet, KeyNotFoundError) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    int value = 0;
    hash_map_state_code_t result = hash_map_get(map, "key1", &value);
    EXPECT_EQ(result, KEY_ERROR);

    hash_map_dtor(map);
}

//===============================hash_map_remove=================================//
//test on successful removal of an item
TEST(HashMapRemove, RemoveExistingItem) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    hash_map_put(map, "key1", 100);

    hash_map_state_code_t result = hash_map_remove(map, "key1");
    EXPECT_EQ(result, OK);

    //check that the element is no longer available
    int value = 0;
    result = hash_map_get(map, "key1", &value);
    EXPECT_EQ(result, KEY_ERROR);

    hash_map_dtor(map);
}

//test on removing a non-existent item
TEST(HashMapRemove, RemoveNonexistentItem) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    hash_map_state_code_t result = hash_map_remove(map, "key1");
    EXPECT_EQ(result, KEY_ERROR);

    hash_map_dtor(map);
}

//===============================hash_map_pop=================================//
//test on successful removal and retrieval of a value for an existing item
TEST(HashMapPop, PopExistingItem) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    hash_map_put(map, "key1", 100);
    int value = 0;

    hash_map_state_code_t result = hash_map_pop(map, "key1", &value);
    EXPECT_EQ(result, OK);
    EXPECT_EQ(value, 100);

    //check that the element is no longer available
    result = hash_map_get(map, "key1", &value);
    EXPECT_EQ(result, KEY_ERROR);

    hash_map_dtor(map);
}

//test on removing a non-existent item
TEST(HashMapPop, PopNonexistentItem) {
    hash_map_t* map = hash_map_ctor();
    ASSERT_NE(nullptr, map);

    int value = 0;
    hash_map_state_code_t result = hash_map_pop(map, "nonexistent_key", &value);
    EXPECT_EQ(result, KEY_ERROR);

    hash_map_dtor(map);
}

/*** Konec souboru white_box_tests.cpp ***/
