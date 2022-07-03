/*program to construct complete binary tree using an array*/
#include <iostream>
#include <stdlib.h>
using namespace std;

class basicFunctions
{
protected:
    /*returns the resultant of base to the power exponent*/
    int power(int base, short exponent)
    {
        int result = 1;
        while (exponent > 0)
        {
            result = result * base;
            exponent--;
        }
        return result;
    }

public:
    /*take argument of base address of static array and input the number from user. Returns true on success, false on failure */
    bool inputArrayStatic(int *array, int length)
    {
        /*How to check failure in input of array
         *actually before input each element of array contains garbage value.
         *we will store garbage value of any index.
         *and after input we will match the garbage of same index with current value
         *if value matched then there will failure in input of array.
         *
         * But It will not work in case of dynamic array. Because dynamic memory blocks are initialized by 0 itself
         * It may possible that user have input the same data which was the garbage of that index.
         * So, this is not a good practice for solving this issue.
         */
        long lastGarbageValue = array[length - 1];
        cout << "last garbage value = " << lastGarbageValue << endl;
        for (int i = 0; i < length; i++)
        {
            cout << "write element of index " << i << endl;
            cin >> array[i];
        }
        if (lastGarbageValue == array[length - 1])
            return false;
        return true;
    }

    /*take argument of length of array and returns the base address of the dynamic array stored in heap.
     *data will not lost after return because stack will be vanished but heap remains safe until use of free() or program's end */
    int *inputArrayDynamic(int length)
    {
        int *array = (int *)calloc(length, sizeof(int));
        inputArrayStatic(array, length);
        return array;
    }

    /*take the argument of base address of array and its length and display the array*/
    void
    display(int *array, int length)
    {
        for (int i = 0; i < length; i++)
            cout << *(array + i) << " ";
        cout << endl;
    }
};

class binaryTreeRelated : protected basicFunctions
{
protected:
    /*Returns maximum number of possible levels in current tree*/
    int lastLevelNumber(int length)
    {
        if (length <= 0)
            return -1;
        /*checking level by level*/
        int numberOfTotalNodes = length;
        for (int i = 1; true; i++)
        {
            if (numberOfTotalNodes >= power(2, i - 1) && numberOfTotalNodes < power(2, i))
                return i - 1;
        }
    }

    /*returns total number of nodes in left subtree of received parent node index. Here it is assume that array started from 0. Returns -1 if index of parent node > lengthOfArray*/
    short numberOfNodesInLeftSubtree(int lengthOfArray, int indexOfParentNode)
    {
        /*here lengthOfArray is the equal to number of nodes in tree and lengthOfArray-1 is the index of last node*/
        short indexOfLastNode = lengthOfArray - 1;
        short numberOfNode = -1; //-1 because we are moving one extra iteration in loop.i.e., when last node reached then also condition satisfied and one extra iteration happen. So, we have started it with -1 ore we can return with result-1
        while (indexOfParentNode <= indexOfLastNode)
        {
            int nextLeftChildIndex = 2 * indexOfParentNode + 1; // left child = (2*i)+1 if array started from 0
            indexOfParentNode = nextLeftChildIndex;
            numberOfNode++;
        }
        return numberOfNode;
    }
};

/*Class to construct binary tree from array given by user*/
class constructCompleteBinaryTree : private binaryTreeRelated
{
    int length;
    int *array;

    void construct()
    {
        /*we have find the number of nodes in last level. It will use to know the current position of rootNode
        and to find the no. of nodes in last level. We must need to know the 'lastLevel'*/
        // int positionOfRoot = power(2, lastLevelNumber(length));
        int positionOfRoot = 2 * numberOfNodesInLeftSubtree(length, 0);
        int savePositionOfRoot = positionOfRoot;
        /*the formula for above shortcut is following:
         *total no. of elements in last level (including whitespace)= total nodes in last level + whitespace
         * = (2^i)+ total no. of nodes till last 2nd level
         * = (2^i)+ (2^h)-1
         * here i=last level. h=height=lastLevel+1. And for only height, here last level = last2ndLevel, height=i
         * =(2^i)+(2^i)-1 = result(let)
         * position of root=result+1/2=2*(2^i)/2=2*i;//where i is the last level
         */

        int previousLevel = 0;
        /*we are taking 1 space for here only*/
        /*whenever level changed the next data will goes in new line*/
        for (int i = 0; i < length; i++)
        {
            int level = lastLevelNumber(i + 1);
            if (previousLevel != level)
            {
                cout << endl;
                previousLevel = level;

                positionOfRoot = savePositionOfRoot - lastLevelNumber(length);
                savePositionOfRoot = positionOfRoot;
            }

            /*now constructing tree*/
            for (short j = 0; j < positionOfRoot; j++) // printing space
                cout << "_";
            positionOfRoot = lastLevelNumber(length); // for space b/w the nodes of current level

            cout << array[i];
        }
    }

public:
    void constructTree(int *array, int length)
    {
        this->array = array;
        (*this).length = length; // using the value of current object instead of address which is return by this pointer
        construct();
    }
};

int main()
{
    system("cls");
    basicFunctions array;
    int myArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Array is following" << endl;
    array.display(myArray, 9);

    constructCompleteBinaryTree tree;
    cout << "\n\033[1;32m========BINARY TREE OF ABOVE ARRAY IS FOLLOWING=========\033[0m" << endl;
    tree.constructTree(myArray, 9);

    return 0;
}
/*
 cout << "write size of array" << endl;
 cin >> sizeOfArray;
*/
