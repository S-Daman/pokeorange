Route102_Gatehouse_MapScripts::
	.byte 0


Route50GateLass::
	lock
	faceplayer
	msgbox Route50GateLass_Text_0, MSGBOX_AUTOCLOSE
	release
	return


Route50GatePoliceman::
	lock
	faceplayer
	msgbox Route50GatePoliceman_Text_0, MSGBOX_AUTOCLOSE
	release
	return


Route50GateGuardStopsYou::
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Route50GateMove1
	waitmovement 0
	msgbox Route50GateGuardStopsYou_Text_0, MSGBOX_AUTOCLOSE
	applymovement EVENT_OBJ_ID_PLAYER, Route50GateMove2
	waitmovement 0
	releaseall
	end


Route50GateMove1:
	face_right
	step_end

Route50GateMove2:
	walk_down
	step_end

Route50GateLass_Text_0:
	.string "Oh, of all the rotten luck!\pYou can't go to MIKAN ISLAND\nunless you go through the WOODS!$"

Route50GatePoliceman_Text_0:
	.string "TRAINER, be careful in TANGELO WOODS.\pMake sure you've stocked up on REPELS\nand status-healers like ANTIDOTES.$"

Route50GateGuardStopsYou_Text_0:
	.string "Ahead lies TANGELO JUNGLE.\pMake sure you've come prepared\nwith a strong POKéMON.$"
