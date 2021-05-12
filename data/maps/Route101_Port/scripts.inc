Route101_Port_MapScripts::
	.byte 0


Route49PortSailor::
	lock
	faceplayer
	msgbox Route49PortSailor_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route49PortSailor_2
	msgbox Route49PortSailor_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Route49PortSailor_2:
	msgbox Route49PortSailor_Text_1, MSGBOX_AUTOCLOSE
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_ROUTE101_PORT
	compare VAR_FACING, 2
	goto_if_eq Route49PortSailor_6
Route49PortSailor_5:
	compare VAR_FACING, 4
	goto_if_eq Route49PortSailor_9
Route49PortSailor_8:
	delay 30
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	delay 60
	applymovement 3, Route49BoatMovement
	PlaySE SE_NAMINORI
	waitmovement 0
	delay 25
	warp MAP_OLDALE_TOWN_PORT, 255, 16, 10
	waitstate
	release
	end

Route49PortSailor_6:
	applymovement EVENT_OBJ_ID_PLAYER, Route49PlayerBoard1
	waitmovement 0
	goto Route49PortSailor_5

Route49PortSailor_9:
	applymovement EVENT_OBJ_ID_PLAYER, Route49PlayerBoard2
	waitmovement 0
	goto Route49PortSailor_8


Route49PlayerBoard1:
	walk_up
	step_end

Route49PlayerBoard2:
	walk_right
	walk_in_place_fastest_up
	step_end

Route49BoatMovement:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route49PortFisherman::
	lock
	faceplayer
	msgbox Route49PortFisherman_Text_0, MSGBOX_AUTOCLOSE
	release
	return


Route49PortSailor_Text_0:
	.string "Hey, kid! Do you need a ride to\nTANGELO ISLAND?$"

Route49PortSailor_Text_1:
	.string "Alright! Off we go!$"

Route49PortSailor_Text_2:
	.string "Aye, as you like it, then.$"

Route49PortFisherman_Text_0:
	.string "They say you aren't allowed to\nfish in ports.\pThat's so unfair, don't you think?$"
