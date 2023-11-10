//
//  FitCloudRoutePlanDefines.h
//  FitCloudRoutePlan
//
//  Created by pcjbird on 2023-11-03.
//

#ifndef FitCloudRoutePlanDefines_h
#define FitCloudRoutePlanDefines_h

/// The map provider
typedef NS_ENUM(NSInteger, FITCLOUDROUTEPLANMAPPROVIDER)
{
    /// 百度地图 (Baidu Map)
    FITCLOUDROUTEPLANMAPPROVIDER_BAIDU = 1,
    
    /// 高德地图 (AMap)
    FITCLOUDROUTEPLANMAPPROVIDER_AMAP = 2,
};

/// The navigation type
typedef NS_ENUM(NSInteger, FITCLOUDROUTEPLANNAVITYPE) {
    /// unknown
    FITCLOUDROUTEPLANNAVITYPE_UNKNOWN = 0x00,
    /// normal cycle
    FITCLOUDROUTEPLANNAVITYPE_NORMAL_CYCLE = 0x01,
    /// electric cycle
    FITCLOUDROUTEPLANNAVITYPE_ELECTRIC_CYCLE = 0x02,
    /// walking
    FITCLOUDROUTEPLANNAVITYPE_WALK = 0x03,
};

/// The guide kind
typedef NS_ENUM(NSInteger, FITCLOUDROUTEPLANGUIDEKIND)
{
    /// 无效，Invalid
    FITCLOUDROUTEPLANGUIDEKIND_INVALID = 0x00,
    /// 起点，Start
    FITCLOUDROUTEPLANGUIDEKIND_START = 0x01,
    /// 直行，Front
    FITCLOUDROUTEPLANGUIDEKIND_FRONT = 0x02,
    /// 右前方转弯，Right front
    FITCLOUDROUTEPLANGUIDEKIND_RIGHT_FRONT = 0x03,
    /// 右转，Right
    FITCLOUDROUTEPLANGUIDEKIND_RIGHT = 0x04,
    /// 右后方转弯，Right back
    FITCLOUDROUTEPLANGUIDEKIND_RIGHT_BACK = 0x05,
    /// 左后方转弯，Left back
    FITCLOUDROUTEPLANGUIDEKIND_LEFT_BACK = 0x06,
    /// 左转，Left
    FITCLOUDROUTEPLANGUIDEKIND_LEFT = 0x07,
    /// 左前方转弯，Left front
    FITCLOUDROUTEPLANGUIDEKIND_LEFT_FRONT = 0x08,
    /// 左掉头，Left u-turn
    FITCLOUDROUTEPLANGUIDEKIND_LEFT_U_TURN = 0x09,
    /// 右掉头，Right u-turn
    FITCLOUDROUTEPLANGUIDEKIND_RIGHT_U_TURN = 0x0A,
    /// 到达，Dest
    FITCLOUDROUTEPLANGUIDEKIND_DEST = 0x0B,
    /// 台阶楼梯，Stair
    FITCLOUDROUTEPLANGUIDEKIND_STAIR = 0x0C,
};

#endif /* FitCloudRoutePlanDefines_h */
