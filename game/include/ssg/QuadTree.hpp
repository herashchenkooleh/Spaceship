#pragma once

#include "ssg/Global.hpp"

namespace ssg
{
    class QuadTree
    {
    public:
        using Ptr = SharedPtr<QuadTree>;

        QuadTree();
        ~QuadTree();

        QuadTree(const QuadTree& InObject) = delete;
        QuadTree& operator=(const QuadTree& InObject) = delete;
    };
}