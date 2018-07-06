//
//  main.cpp
//  read_subwayInfo_from_OSM
//
//  Created by Jingwei Zhang on 2018/7/6.
//  Copyright © 2018 Jingwei Zhang. All rights reserved.
//

#include <iostream>



    for (unsigned relationIndex = 0; relationIndex < getNumberOfRelations(); relationIndex++) {
        const OSMRelation* temp = getRelationByIndex(relationIndex);
        pair<OSMID, unsigned> relation(temp -> id(), relationIndex);
        globalVar.OSMIDToRelationIndex.insert(relation);
    }








    for (unsigned relationIndex = 0; relationIndex < getNumberOfRelations(); relationIndex++) {
        const OSMRelation* tempRelation = getRelationByIndex(relationIndex);
        for (unsigned tagIndex = 0; tagIndex < getTagCount(tempRelation); tagIndex++) {
            string key, value;
            tie(key, value) = getTagPair(tempRelation, tagIndex);
            if (key == "route" && value == "subway") {
                vector<vector < t_point>> linePoints;
                vector <unsigned> subwayWayIndex1;
                for (unsigned member = 0; member < tempRelation->members().size(); member++) {
                    int tempWayIndex = OSMIDToWayIndex(tempRelation->members()[member].tid);
                    if (tempWayIndex != -1)
                        subwayWayIndex1.push_back(tempWayIndex);
                }
                for (unsigned wayID = 0; wayID < subwayWayIndex1.size(); wayID++) {

                    vector<LatLon> stations = wayToNodes(subwayWayIndex1[wayID]);
                    vector<t_point> t_stations;
                    // convert all nodes to xy
                    for (unsigned id = 0; id < stations.size(); id++) {
                        LatLon point = stations[id];
                        t_point xy = LatLon_to_real_XY1(point);

                        t_stations.push_back(xy);
                    }

                    linePoints.push_back(t_stations);

                }



                globalVar.subwayWayIndex.push_back(subwayWayIndex1);
                globalVar.metro.push_back(linePoints);
            }
        }

    }

    globalVar.metroColor.push_back(t_color(227, 23, 13, 255));
    globalVar.metroColor.push_back(t_color(50, 205, 50, 255));
    globalVar.metroColor.push_back(t_color(255, 97, 0, 255));
    globalVar.metroColor.push_back(t_color(30, 144, 255, 255));

    globalVar.metroColor.push_back(t_color(153, 51, 250, 255));
    globalVar.metroColor.push_back(t_color(255, 255, 0, 255));
    globalVar.metroColor.push_back(t_color(56, 94, 15, 255));
    globalVar.metroColor.push_back(t_color(56, 94, 15, 255));

    globalVar.metroColor.push_back(t_color(176, 48, 96, 255));
    globalVar.metroColor.push_back(t_color(0, 199, 140, 255));
    globalVar.metroColor.push_back(t_color(115, 74, 18, 255));
    globalVar.metroColor.push_back(t_color(218, 112, 214, 255));



 for (unsigned lineIndex = 0; lineIndex < globalVar.subwayWayIndex.size(); lineIndex ++){
 std::vector<unsigned> tempWay1 = globalVar.subwayWayIndex[lineIndex];
 for (unsigned i = 0; i < globalVar.subwayWayIndex[lineIndex].size(); i++){
 unsigned id = tempWay1[i];
 
 
 const OSMWay* tempWay = getWayByIndex(id);
 const OSMNode* tempNode = getNodeByIndex(OSMIDToNodeIndex(tempWay -> ndrefs()[0]));
 
 LatLon tempLatLon = tempNode -> coords();
 
 t_point station(LatLon_to_real_XY1(tempLatLon));
 globalVar.subwayStations.resize(lineIndex+1);
 globalVar.subwayStations[lineIndex].push_back(station);
 }
 }
 
 
 

