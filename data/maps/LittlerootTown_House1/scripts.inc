LittlerootTown_House1_MapScripts::
	.byte 0


MapGirl::
	lock
	faceplayer
	goto_if_set FLAG_TOWN_MAP, MapGirl_2
	msgbox MapGirl_Text_1
	giveitem_std ITEM_TOWN_MAP, 1
	removeobject 2
	setflag FLAG_TOWN_MAP
MapGirl_1:
	release
	return

MapGirl_2:
	msgbox MapGirl_Text_0
	goto MapGirl_1


OrangeMap::
	lock
	msgbox OrangeMap_Text_0
	release
	return


MapGirl_Text_0:
	.string "Have a safe trip, {PLAYER}!$"

MapGirl_Text_1:
	.string "Oh, {PLAYER}!\nNice of you to drop by!\pI have something for you so you\nwon't get lost!$"

OrangeMap_Text_0:
	.string "It's a map of the ORANGE ARCHIPELAGO.$"
