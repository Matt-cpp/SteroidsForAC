#pragma once

// 1.2.0.2 Offsets for assault cube
constexpr auto localPlayer = 0x10F4F4;
constexpr auto health = 0xF8;
constexpr auto armor = 0xFC;
constexpr auto ARammo = 0x150;
constexpr auto nameOffsetWithinPadding = 0x225;

class NamePadding {
public:
	char preNamePadding[549]; //0x0000
	char maxCharactersInName[16]; //0x0225
	char postNamePadding[3609]; //0x0235
}; //Size: 0x104E