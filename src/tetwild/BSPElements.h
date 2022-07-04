// This file is part of TetWild, a software for generating tetrahedral meshes.
//
// Copyright (C) 2018 Yixin Hu <yixin.hu@nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
//
// Created by yihu on 8/22/17.
//

#ifndef NEW_GTET_BSPELEMENTS_H
#define NEW_GTET_BSPELEMENTS_H
#include <vector>
#include <unordered_set>

namespace tetwild {

class BSPEdge{
public:
    std::vector<int> vertices;
    //conn_faces存储一条边被哪些face id所包含
    std::unordered_set<int> conn_faces;

    BSPEdge(){}
    BSPEdge(int v1, int v2){
        vertices={v1, v2};
    }
};


class BSPFace{
public:
    //vertices存储BSP三角面顶点序号
    std::vector<int> vertices;
    //edges存储面的边id 
    std::vector<int> edges;
    //conn_nodes存储共享该face的cell序号,一般有2个,
    std::unordered_set<int> conn_nodes;
    //包含  target face id  ，与本face COPLANAR_INT，它们一定是共一个平面
    std::unordered_set<int> div_faces;

    int matched_f_id=-1;
};

class BSPtreeNode{
public:
    bool is_leaf=false;
    //将cell面作为一个node，这个cell有哪些面的idx
    std::vector<int> faces;
    //包含  target face id  ，与本cell的某一个face cross
    std::unordered_set<int> div_faces;
};

} // namespace tetwild

#endif //NEW_GTET_BSPELEMENTS_H
