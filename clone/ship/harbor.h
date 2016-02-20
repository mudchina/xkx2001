//Cracked by Roath
// harbor.h  所有港口资料
// by ALN@XKX

// locx indicates positions of easts-wests, + means east, - means west
// locy indicates positions of south-norths, + means north, - means south

// all 大陆港口
mapping harbors = ([
        "/d/beijing/tanggu"    :    0,
        "/d/jiaxing/zhoushan"   : -200,
        "/d/quanzhou/yongning" : -280,
        "/d/quanzhou/anhai"    : -300,
]);

// all 海岛港口
mapping islands = ([
        "/d/shenlong/beach"    : ({ 30,   20}), 
        "/d/island/icefire1"   : ({100,  600}),
        "/d/taohua/haitan"     : ({ 20, -210}),
]);

// 荒岛
// 如果船停在荒岛，玩家可以派一个人守船
// 因为在荒岛，玩家无法唤船
string *wildharbors = ({
        "/d/island/icefire1",
});
