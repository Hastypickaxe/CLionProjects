//
// Created by justd on 9/7/2023.
//

#include <algorithm> // Provides copy function
#include <cassert> // Provides assert function
#include "Bag1.h"

using namespace std;
namespace main_savitch_3 {
    const bag::size_type bag::CAPACITY;

    bag::size_type bag::erase(const value_type &target) {
        size_type index = 0;
        size_type many_removed = 0;
        while (index < used) {
            if (data[index] == target) {
                --used;
                data[index] = data[used];
                ++many_removed;
            } else ++index;
        }
        return many_removed;
    }

    bool bag::erase_one(const value_type &target) {
        size_type index; // The location of target in the data array
// First, set index to the location of target in the data array,
// which could be as small as 0 or as large as used-1. If target is not
// in the array, then index will be set equal to used.
        index = 0;
        while ((index < used) && (data[index] != target))
            ++index;
        if (index == used)
            return false; // target isn�t in the bag, so no work to do.
// When execution reaches here, target is in the bag at data[index].
// So, reduce used by 1 and copy the last item onto data[index].
        --used;
        data[index] = data[used];
        return true;
    }

    void bag::insert(const value_type &entry)
// Library facilities used: cassert
    {
        assert(size() < CAPACITY);
        data[used] = entry;
        ++used;
    }

    void bag::operator+=(const bag &addend)
// Library facilities used: algorithm, cassert
    {
        assert(size() + addend.size() <= CAPACITY);
        copy(addend.data, addend.data + addend.used, data + used);
        used += addend.used;
    }

    bag::size_type bag::count(const value_type &target) const {
        size_type answer;
        size_type i;
        answer = 0;
        for (i = 0; i < used; ++i)
            if (target == data[i])
                ++answer;
        return answer;
    }

    bag operator+(const bag &b1, const bag &b2) // Library facilities used: cassert
    {
        bag answer;
        assert(b1.size() + b2.size() <= bag::CAPACITY);
        answer += b1;
        answer += b2;
        return answer;
    }

    /*
    bag bag ::operator-(const main_savitch_3::bag &subtrahend) const
    {
        bag output;
        for(size_type i = 0; i < used; i++)
        {
            value_type item = data[i];
            size_type countSubtrahend = subtrahend.count(item);
            if(countSubtrahend == 0)
            {
                output.insert(item);
            }
            else if(countSubtrahend < count(item))
            {
                for(size_type j = 0; j < count(item); j++)
                {
                    output.insert(item);
                }
            }
        }
        return output;
    }

    void bag::operator-=(const main_savitch_3::bag &subtrahend)
    {
        bag output = *this - subtrahend;
    }

    bag bag ::operator^(const main_savitch_3::bag &other) const
    {
        bag output;
        for(size_type i = 0; i < used; i++)
        {
            value_type item = data[i];
            size_type countOther = other.count(item);
            if(countOther > 0)
            {
                for(size_type  j = 0; j < min(count(item), countOther); j++)
                {
                    output.insert(item);
                }
            }
        }
        return output;
    }

    bag bag ::operator&(const main_savitch_3::bag &other) const
    {
        bag output = (*this + other) - (*this ^ other);
        return output;
    }

    void bag::squeeze()
    {
        for(size_type i = 0; i < used; i++)
        {
            for(size_type j = i = 1; j < used;)
            {
                if(data[i] == data[j])
                {
                    for(size_type  k = j; k < used - 1; k++)
                    {
                        data[k] == data[k + 1];
                    }
                    --used;
                }
                else
                {
                    j++;
                }
            }
        }
    }

    void bag::sort()
    {
        for(size_type i = 0; i < used; i++)
        {
            for(size_type j = 0; j < used - i - 1; j++)
            {
                if(data[j] > data[j + 1])
                {
                    value_type temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
*/
    void bag::show() const
    {
        for(size_type i = 0; i < used; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

}
