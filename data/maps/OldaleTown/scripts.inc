OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, OldaleTown_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

OldaleTown_MapScripts_MAP_SCRIPT_ON_LOAD:
	return


OldaleTownGirl::
	lock
	faceplayer
	msgbox OldaleTownGirl_Text_0, MSGBOX_AUTOCLOSE
	release
	return


OldaleTownBoy::
	lock
	faceplayer
	msgbox OldaleTownBoy_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TangeloIslandSign::
	lock
	msgbox TangeloIslandSign_Text_0, MSGBOX_SIGN
	release
	return


TangeloIslandPortSign::
	lock
	msgbox TangeloIslandPortSign_Text_0, MSGBOX_SIGN
	release
	return


TangeloCenterSign::
	lock
	msgbox TangeloCenterSign_Text_0, MSGBOX_SIGN
	release
	return


TangeloIslandTracey::
	lock
	faceplayer
	goto_if_set FLAG_GS_BALL_TRACEY, TangeloIslandTracey_2
	msgbox TangeloIslandTracey_Text_3, MSGBOX_DEFAULT
	giveitem_std ITEM_DEVON_GOODS, 1, 0
	setflag FLAG_GS_BALL_TRACEY
	release
	end

TangeloIslandTracey_2:
	goto_if_set FLAG_GS_BALL_IVY, TangeloIslandTracey_5
	msgbox TangeloIslandTracey_Text_2, MSGBOX_AUTOCLOSE
	release
	end

TangeloIslandTracey_5:
	msgbox TangeloIslandTracey_Text_0, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MAY_1, TraceyLostText
	msgbox TangeloIslandTracey_Text_1, MSGBOX_AUTOCLOSE
	applymovement EVENT_OBJ_ID_PLAYER, TangeloIslandPlayerMove1
	waitmovement 0
	applymovement 3, TangeloIslandTraceyMove1
	waitmovement 0
	removeobject 3
	setflag FLAG_GS_BALL_TRACEY2
	release
	end


TangeloIslandPlayerMove1:
	walk_down
	walk_right
	face_left
	step_end

TangeloIslandTraceyMove1:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TangeloIslandLapras::
	lockall
	playmoncry SPECIES_WEAK_LAPRAS, 0
	msgbox TangeloIslandLapras_Text_0, MSGBOX_YESNO
	waitmoncry
	compare VAR_RESULT, 0
	goto_if_eq TangeloIslandLapras_2
	setvar VAR_ROUTE105_STATE, 5
	setvar VAR_TEMP_1, SPECIES_WEAK_LAPRAS
	givemon SPECIES_WEAK_LAPRAS, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq TangeloIslandLapras_5
	compare VAR_RESULT, 1
	goto_if_eq TangeloIslandLapras_8
	goto Common_EventScript_NoMoreRoomForPokemon
	end

TangeloIslandLapras_2:
	msgbox TangeloIslandLapras_Text_1, MSGBOX_AUTOCLOSE
	releaseall
	end

TangeloIslandLapras_5:
	bufferspeciesname 1, SPECIES_WEAK_LAPRAS
	removeobject 4
	playfanfare MUS_FANFA5
	message ObtainedLapras
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_WEAK_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TangeloIslandLapras_11
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	releaseall
	end

TangeloIslandLapras_8:
	bufferspeciesname 1, SPECIES_WEAK_LAPRAS
	removeobject 4
	playfanfare MUS_FANFA5
	message ObtainedLapras
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_WEAK_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq TangeloIslandLapras_14
	call Common_EventScript_NameReceivedBoxMon
	call Common_EventScript_TransferredToPC
	setflag FLAG_TANGELO_LAPRAS
	releaseall
	end

TangeloIslandLapras_11:
	setflag FLAG_TANGELO_LAPRAS
	releaseall
	end

TangeloIslandLapras_14:
	call Common_EventScript_TransferredToPC
	setflag FLAG_TANGELO_LAPRAS
	releaseall
	end


OldaleTownGirl_Text_0:
	.string "There are lots of TRAINERS on\nROUTE 50.\pThey all plan on taking on the\nORANGE CREW.$"

OldaleTownBoy_Text_0:
	.string "Have you checked the POKéMON MART\nout yet?\pI heard they finally restocked their\nsupply of POKé BALLS recently.$"

TangeloIslandSign_Text_0:
	.string "TANGELO ISLAND\nThe Bell Tolls for a Bright Future$"

TangeloIslandPortSign_Text_0:
	.string "TANGELO ISLAND PORT$"

TangeloCenterSign_Text_0:
	.string "TANGELO CENTER$"

TangeloIslandTracey_Text_0:
	.string "So, you delivered it?\pWhat? You're taking on the\nORANGE CREW?\pThat's really interesting.\pSay, why don't we have a battle?\nI'm kinda strong!$"

TangeloIslandTracey_Text_1:
	.string "Say, why don't you take this\nLAPRAS?\pIt was separated from its family,\nand needs a good TRAINER.\pOh, how rude!\nThe name is TRACEY.\lI'm a POKéMON WATCHER.\pAnyway, I must be off.\nSee you around!$"

TangeloIslandTracey_Text_2:
	.string "Could you please deliver that\nGS BALL to her for me?$"

TangeloIslandTracey_Text_3:
	.string "This poor LAPRAS was washed up\non ROUTE 50. I saved it.\p… … … … … … … …\n… … … … … … … …\pWhat's that? You are from\nVALENCIA?\pI see. I was on my way there to\ndeliver something to PROF. IVY\lfor a friend.\pDo you think you could deliver it\nfor me?$"

TangeloIslandLapras_Text_0:
	.string "The LAPRAS seems eager to\njoin you.\pTake LAPRAS?$"

TangeloIslandLapras_Text_1:
	.string "{PLAYER} left the LAPRAS where it was.$"

TraceyLostText::
	.string "Wow, you might have a chance!$"

ObtainedLapras::
	.string "{PLAYER} obtained a LAPRAS!$"
