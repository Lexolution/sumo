/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2020 German Aerospace Center (DLR) and others.
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    GNEPathElements.h
/// @author  Pablo Alvarez Lopez
/// @date    May 2020
///
// A abstract class for representation of element paths
/****************************************************************************/
#pragma once
#include <config.h>

#include <netedit/GNEGeometry.h>
#include <utils/gui/globjects/GUIGlObjectTypes.h>
#include <utils/geom/Position.h>

#include "GNEAttributeCarrier.h"


// ===========================================================================
// class definitions
// ===========================================================================

/**
 * @class GNEPathElements
 * @brief An special type of Attribute carrier that owns hierarchical elements
 */
class GNEPathElements {

public:

    /// @brief path element
    class PathElement {

    public:
        /// @brief constructor for junctions
        PathElement(GNEJunction* junction);

        /// @brief constructor for lanes
        PathElement(GNELane* lane);

        /// @brief get junction
        GNEJunction* getJunction() const;

        /// @brief get lane
        GNELane* getLane() const;

    protected:
        /// @brief junction
        GNEJunction* myJunction;

        /// @brief lane
        GNELane* myLane;

    private:
        /// @brief default constructor
        PathElement();
    };

    /// @brief Constructor
    GNEPathElements(GNEDemandElement* demandElement);

    /// @brief Destructor
    ~GNEPathElements();

    /// @brief get path edges
    const std::vector<GNEPathElements::PathElement>& getPath() const;

    /// @brief draw path child
    void drawPathChildren(const GUIVisualizationSettings& s, const GNELane* lane) const;

protected:
    /// @brief update path lanes
    void updatePathLanes(SUMOVehicleClass vClass, GNELane* fromLane, GNELane* toLane, const std::vector<GNEEdge*> &viaEdges);

    /// @brief invalidate path lanes
    void invalidatePathLanes(SUMOVehicleClass vClass, GNELane* fromLane, GNELane* toLane, const std::vector<GNEEdge*> &viaEdges);

private:
    /// @brief ponter to demand element (this)
    GNEDemandElement* myDemandElement;

    /// @brief vector of edges used in paths
    std::vector<PathElement> myPathElements;

    /// @brief Invalidated copy constructor.
    GNEPathElements(const GNEPathElements&) = delete;

    /// @brief Invalidated assignment operator.
    GNEPathElements& operator=(const GNEPathElements&) = delete;
};

