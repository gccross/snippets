#include <iostream>
#include <set>


//////   Don't worry about these forward declarations.
//////   They are just here to make sure you don't get error messages


class MovingThing;
class ConstructionZone{};
class Coords;

class ThingsThatMove{ 
public:
  ConstructionZone* begin() {return nullptr;}
  ConstructionZone* end() {return nullptr;}
};

double magic_distance_calculator(const Coords& position);



//////    Start worrying here :)


struct BlockageCalculator {
    /**
     * @brief Type of blockage classes that are possible.
     */
    enum class BlockageType
    {
        INACTIVE_MOVING_THING,
        CONSTRUCTION_ZONE
    };

    enum class MovingThingType
    {
        VEHICLE,
        PEDESTRIAN,
        BICYCLE,
        NOT_A_MOVING_THING
    };

    /**
     * @brief Store of the distance to from the ego vehicle to the obstacle. Note that depending on the type, the right
     * pointer will have to initalized
     */
    struct BlockageInfo
    {
        double             distanceToOurVehicle;
        BlockageType       blockageType;
        MovingThingType    thingType;

        const MovingThing*      movingThing            = nullptr;
        const ConstructionZone* constructionZone = nullptr;

        bool operator<(const BlockageInfo& blockageInfo) const noexcept
        {
            return distanceToOurVehicle < blockageInfo.distanceToOurVehicle;
        }
    };

  
    std::set<BlockageInfo> sortByDistanceToEgo() const
    {
      std::set<BlockageInfo> distances;
        
      auto calculateObjectDistanceToOurVehicle = [&ourVehiclePostion, &distances](const auto&  objects) {
        for (auto& object : objects) {
            double      distance   = magic_distance_calculator(ourVehiclePosition);
            distances.insert(BlockageInfo{distance, 
                                          BlockageType::CONSTRUCTION_ZONE, 
                                          MovingThingType::NOT_A_MOVING_THING, 
                                          nullptr, &object});
        }
      };

	transform(cbegin(objects), cend(objects),/// to finish 
      
      calculateObjectDistanceToOurVehicle(thingsThatMove);
      
      return distances;
    }
// let's use ZOOM again

    const Coords& ourVehiclePosition;
    const ThingsThatMove& thingsThatMove;
    
};


int main() {
  // do nothing;

}
