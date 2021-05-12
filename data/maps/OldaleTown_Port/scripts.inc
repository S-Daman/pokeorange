OldaleTown_Port_MapScripts::
	.byte 0


OldalePortSailor::
	lock
	faceplayer
	msgbox OldalePortSailor_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq OldalePortSailor_2
	msgbox OldalePortSailor_Text_2, MSGBOX_AUTOCLOSE
	release
	end

OldalePortSailor_2:
	msgbox OldalePortSailor_Text_1, MSGBOX_AUTOCLOSE
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_OLDALE_TOWN_PORT
	compare VAR_FACING, 2
	goto_if_eq OldalePortSailor_6
OldalePortSailor_5:
	compare VAR_FACING, 4
	goto_if_eq OldalePortSailor_9
OldalePortSailor_8:
	delay 30
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	delay 60
	applymovement 3, OldaleBoatMovement
	PlaySE SE_NAMINORI
	waitmovement 0
	delay 25
	warp MAP_ROUTE101_PORT, 255, 16, 10
	waitstate
	release
	end

OldalePortSailor_6:
	applymovement EVENT_OBJ_ID_PLAYER, OldalePlayerBoard1
	waitmovement 0
	goto OldalePortSailor_5

OldalePortSailor_9:
	applymovement EVENT_OBJ_ID_PLAYER, OldalePlayerBoard2
	waitmovement 0
	goto OldalePortSailor_8


OldalePlayerBoard1:
	walk_up
	step_end

OldalePlayerBoard2:
	walk_right
	walk_in_place_fastest_up
	step_end

OldaleBoatMovement:
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

OldalePortBeauty::
	lock
	faceplayer
	msgbox OldalePortBeauty_Text_0, MSGBOX_AUTOCLOSE
	release
	return


OldalePortSailor_Text_0:
	.string "Hey, kid! Do you need a ride to\nVALENCIA ISLAND?$"

OldalePortSailor_Text_1:
	.string "Alright! Off we go!$"

OldalePortSailor_Text_2:
	.string "Aye, as you like it, then.$"

OldalePortBeauty_Text_0:
	.string "The ocean current is really strong\nbetween VALENCIA and TANGELO.\pIt makes it impossible to simply\nsurf to VALENCIA from here.$"
