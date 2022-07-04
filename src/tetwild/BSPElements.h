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
    //conn_faces�洢һ���߱���Щface id������
    std::unordered_set<int> conn_faces;

    BSPEdge(){}
    BSPEdge(int v1, int v2){
        vertices={v1, v2};
    }
};


class BSPFace{
public:
    //vertices�洢BSP�����涥�����
    std::vector<int> vertices;
    //edges�洢��ı�id 
    std::vector<int> edges;
    //conn_nodes�洢�����face��cell���,һ����2��,
    std::unordered_set<int> conn_nodes;
    //����  target face id  ���뱾face COPLANAR_INT������һ���ǹ�һ��ƽ��
    std::unordered_set<int> div_faces;

    int matched_f_id=-1;
};

class BSPtreeNode{
public:
    bool is_leaf=false;
    //��cell����Ϊһ��node�����cell����Щ���idx
    std::vector<int> faces;
    //����  target face id  ���뱾cell��ĳһ��face cross
    std::unordered_set<int> div_faces;
};

} // namespace tetwild

#endif //NEW_GTET_BSPELEMENTS_H
