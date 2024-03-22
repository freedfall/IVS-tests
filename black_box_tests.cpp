//======= Copyright (c) 2024, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     Timur Kininbayev <xkinin00@stud.fit.vutbr.cz>
// $Date:       $2024-02-14
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author Timur Kininbayev
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// Helper functions declarations (implement these based on your tree structure)


//============================== helper functions ============================//

//function to check if all leaves are black
bool checkAllLeavesBlack(const BinaryTree& tree){
    while(tree.FindNode(0) != nullptr){
        if(tree.FindNode(0)->color == BinaryTree::RED)
            return false;
    }
    return true;
}

//function to check if red nodes have black children
bool checkRedNodes(const BinaryTree& tree)
{
    if(tree.FindNode(0) != nullptr){
        if(tree.FindNode(0)->color == BinaryTree::RED){
            if(tree.FindNode(0)->pLeft->color == BinaryTree::RED || tree.FindNode(0)->pRight->color == BinaryTree::RED)
                return false;
        }
    }
    return true;

}

//function to count black nodes from root to leaf
int countBlackNodes(const BinaryTree::Node_t* node){
    int count = 0;
    while(node != nullptr){
        if(node->color == BinaryTree::BLACK)
            count++;
        node = node->pParent;
    }
    return count;

}

//================================ tests ==================================//

//test of InsertNode, DeleteNode and FindNode methods for empty tree
TEST(EmptyTree, InsertNode) {
    BinaryTree tree;
    auto [inserted, node] = tree.InsertNode(10);
    EXPECT_TRUE(inserted);
    EXPECT_NE(nullptr, node);
}

TEST(EmptyTree, DeleteNode) {
    BinaryTree tree;
    bool deleted = tree.DeleteNode(10);
    EXPECT_FALSE(deleted);
}

TEST(EmptyTree, FindNode) {
    BinaryTree tree;
    auto* node = tree.FindNode(10);
    EXPECT_EQ(nullptr, node);
}

//test of InsertNode, DeleteNode and FindNode methods for non-empty tree
TEST(NonEmptyTree, InsertNode) {
    BinaryTree tree;
    tree.InsertNode(10);
    auto [inserted, node] = tree.InsertNode(20);
    EXPECT_TRUE(inserted);
    EXPECT_NE(nullptr, node);
    EXPECT_EQ(20, node->key); 
}

TEST(NonEmptyTree, DeleteNode) {
    BinaryTree tree;
    tree.InsertNode(10);
    bool deleted = tree.DeleteNode(10);
    EXPECT_TRUE(deleted);
}

TEST(NonEmptyTree, FindNode) {
    BinaryTree tree;
    tree.InsertNode(10);
    auto* node = tree.FindNode(10);
    EXPECT_NE(nullptr, node);
    EXPECT_EQ(10, node->key); 
}

// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//

TEST(TreeAxioms, Axiom1) {
    BinaryTree tree;
    tree.InsertNode(10);
    tree.InsertNode(20);
    tree.InsertNode(30);
    tree.InsertNode(40);
    EXPECT_TRUE(checkAllLeavesBlack(tree));
}

TEST(TreeAxioms, Axiom2) {
    BinaryTree tree;
    tree.InsertNode(10);
    tree.InsertNode(20);
    tree.InsertNode(30);
    tree.InsertNode(40);
    EXPECT_TRUE(checkRedNodes(tree));
}

TEST(TreeAxioms, Axiom3) {
    BinaryTree tree;
    tree.InsertNode(10);
    tree.InsertNode(20);
    EXPECT_TRUE(countBlackNodes(tree.FindNode(10)) == countBlackNodes(tree.FindNode(20)));
}

/*** Konec souboru black_box_tests.cpp ***/
