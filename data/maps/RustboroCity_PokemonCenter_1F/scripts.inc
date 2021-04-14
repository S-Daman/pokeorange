RustboroCity_PokemonCenter_1F_MapScripts:: @ 8214D62
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition: @ 8214D6D
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

@ VAR_0x800B is the Nurse's object event id
RustboroCity_PokemonCenter_1F_EventScript_Nurse:: @ 8214D76
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl:: @ 8214D96
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor: @ 8214E81
	.string "I came all the way here to buy some\n"
	.string "POKéMON DOLLS, but they no longer\l"
	.string "sell them at the BAZAAR!\p"
	.string "What a disappointment, really!$"