#include <array>
#include <cstdint>
#include <DataDefs.h>
#include <Core.h>
#include <Console.h>
#include <Export.h>
#include <PluginManager.h>
#include <RemoteServer.h>
#include <RemoteClient.h>
#include <VersionInfo.h>
#include "df_all.h"
#include "DF_Types.h"
#include "RDF_Types.h"


using namespace rdf;


RDF_Type df_2_rdf(DF_Type p_df_type)
{
	switch(p_df_type)
	{
		case DF_Type::KeybindingScreen: return RDF_Type::Class;
		case DF_Type::KeybindingScreen__T_mode: return RDF_Type::Enum;
		case DF_Type::MacroScreenLoad: return RDF_Type::Class;
		case DF_Type::MacroScreenSave: return RDF_Type::Class;
		case DF_Type::T_cursor: return RDF_Type::Compound;
		case DF_Type::T_selection_rect: return RDF_Type::Compound;
		case DF_Type::abstract_building: return RDF_Type::Class;
		case DF_Type::abstract_building__T_inhabitants: return RDF_Type::Compound;
		case DF_Type::abstract_building__T_unk1: return RDF_Type::Compound;
		case DF_Type::abstract_building_contents: return RDF_Type::Struct;
		case DF_Type::abstract_building_counting_housest: return RDF_Type::Class;
		case DF_Type::abstract_building_dark_towerst: return RDF_Type::Class;
		case DF_Type::abstract_building_dungeonst: return RDF_Type::Class;
		case DF_Type::abstract_building_dungeonst__T_dungeon_type: return RDF_Type::Enum;
		case DF_Type::abstract_building_flags: return RDF_Type::Enum;
		case DF_Type::abstract_building_guildhallst: return RDF_Type::Class;
		case DF_Type::abstract_building_inn_tavernst: return RDF_Type::Class;
		case DF_Type::abstract_building_inn_tavernst__T_room_info: return RDF_Type::Compound;
		case DF_Type::abstract_building_keepst: return RDF_Type::Class;
		case DF_Type::abstract_building_libraryst: return RDF_Type::Class;
		case DF_Type::abstract_building_marketst: return RDF_Type::Class;
		case DF_Type::abstract_building_mead_hallst: return RDF_Type::Class;
		case DF_Type::abstract_building_templest: return RDF_Type::Class;
		case DF_Type::abstract_building_tombst: return RDF_Type::Class;
		case DF_Type::abstract_building_towerst: return RDF_Type::Class;
		case DF_Type::abstract_building_type: return RDF_Type::Enum;
		case DF_Type::abstract_building_underworld_spirest: return RDF_Type::Class;
		case DF_Type::abstract_building_unk: return RDF_Type::Struct;
		case DF_Type::abstract_building_unk__T_anon_1: return RDF_Type::Compound;
		case DF_Type::active_script_var_longst: return RDF_Type::Class;
		case DF_Type::active_script_var_unitst: return RDF_Type::Class;
		case DF_Type::active_script_varst: return RDF_Type::Class;
		case DF_Type::activity_entry: return RDF_Type::Struct;
		case DF_Type::activity_entry_type: return RDF_Type::Enum;
		case DF_Type::activity_event: return RDF_Type::Class;
		case DF_Type::activity_event__T_flags: return RDF_Type::Bitfield;
		case DF_Type::activity_event__T_unk_v42_1: return RDF_Type::Compound;
		case DF_Type::activity_event__T_unk_v42_2: return RDF_Type::Compound;
		case DF_Type::activity_event_combat_trainingst: return RDF_Type::Class;
		case DF_Type::activity_event_conflictst: return RDF_Type::Class;
		case DF_Type::activity_event_conflictst__T_sides: return RDF_Type::Compound;
		case DF_Type::activity_event_conflictst__T_sides__T_enemies: return RDF_Type::Compound;
		case DF_Type::activity_event_conversationst: return RDF_Type::Class;
		case DF_Type::activity_event_conversationst__T_anon_6: return RDF_Type::Compound;
		case DF_Type::activity_event_conversationst__T_flags2: return RDF_Type::Bitfield;
		case DF_Type::activity_event_conversationst__T_participants: return RDF_Type::Compound;
		case DF_Type::activity_event_conversationst__T_turns: return RDF_Type::Compound;
		case DF_Type::activity_event_conversationst__T_unk2: return RDF_Type::Compound;
		case DF_Type::activity_event_conversationst__T_unk_b4: return RDF_Type::Compound;
		case DF_Type::activity_event_copy_written_contentst: return RDF_Type::Class;
		case DF_Type::activity_event_copy_written_contentst__T_flagsmaybe: return RDF_Type::Bitfield;
		case DF_Type::activity_event_discuss_topicst: return RDF_Type::Class;
		case DF_Type::activity_event_encounterst: return RDF_Type::Class;
		case DF_Type::activity_event_encounterst__T_anon_1: return RDF_Type::Compound;
		case DF_Type::activity_event_encounterst__T_anon_2: return RDF_Type::Compound;
		case DF_Type::activity_event_fill_service_orderst: return RDF_Type::Class;
		case DF_Type::activity_event_guardst: return RDF_Type::Class;
		case DF_Type::activity_event_harassmentst: return RDF_Type::Class;
		case DF_Type::activity_event_harassmentst__T_anon_2: return RDF_Type::Compound;
		case DF_Type::activity_event_individual_skill_drillst: return RDF_Type::Class;
		case DF_Type::activity_event_make_believest: return RDF_Type::Class;
		case DF_Type::activity_event_participants: return RDF_Type::Struct;
		case DF_Type::activity_event_performancest: return RDF_Type::Class;
		case DF_Type::activity_event_performancest__T_participant_actions: return RDF_Type::Compound;
		case DF_Type::activity_event_play_with_toyst: return RDF_Type::Class;
		case DF_Type::activity_event_play_with_toyst__T_unk: return RDF_Type::Compound;
		case DF_Type::activity_event_playst: return RDF_Type::Class;
		case DF_Type::activity_event_ponder_topicst: return RDF_Type::Class;
		case DF_Type::activity_event_prayerst: return RDF_Type::Class;
		case DF_Type::activity_event_ranged_practicest: return RDF_Type::Class;
		case DF_Type::activity_event_readst: return RDF_Type::Class;
		case DF_Type::activity_event_researchst: return RDF_Type::Class;
		case DF_Type::activity_event_reunionst: return RDF_Type::Class;
		case DF_Type::activity_event_skill_demonstrationst: return RDF_Type::Class;
		case DF_Type::activity_event_socializest: return RDF_Type::Class;
		case DF_Type::activity_event_sparringst: return RDF_Type::Class;
		case DF_Type::activity_event_sparringst__T_groups: return RDF_Type::Compound;
		case DF_Type::activity_event_store_objectst: return RDF_Type::Class;
		case DF_Type::activity_event_teach_topicst: return RDF_Type::Class;
		case DF_Type::activity_event_training_sessionst: return RDF_Type::Class;
		case DF_Type::activity_event_type: return RDF_Type::Enum;
		case DF_Type::activity_event_worshipst: return RDF_Type::Class;
		case DF_Type::activity_event_writest: return RDF_Type::Class;
		case DF_Type::activity_info: return RDF_Type::Struct;
		case DF_Type::activity_info__T_flags: return RDF_Type::Bitfield;
		case DF_Type::adventure_environment_ingest_from_containerst: return RDF_Type::Class;
		case DF_Type::adventure_environment_ingest_materialst: return RDF_Type::Class;
		case DF_Type::adventure_environment_optionst: return RDF_Type::Class;
		case DF_Type::adventure_environment_pickup_chop_treest: return RDF_Type::Class;
		case DF_Type::adventure_environment_pickup_ignite_vegst: return RDF_Type::Class;
		case DF_Type::adventure_environment_pickup_make_campfirest: return RDF_Type::Class;
		case DF_Type::adventure_environment_pickup_vermin_eventst: return RDF_Type::Class;
		case DF_Type::adventure_environment_place_in_bld_containerst: return RDF_Type::Class;
		case DF_Type::adventure_environment_place_in_it_containerst: return RDF_Type::Class;
		case DF_Type::adventure_environment_unit_suck_bloodst: return RDF_Type::Class;
		case DF_Type::adventure_item_interact_choicest: return RDF_Type::Class;
		case DF_Type::adventure_item_interact_fill_from_containerst: return RDF_Type::Class;
		case DF_Type::adventure_item_interact_fill_with_materialst: return RDF_Type::Class;
		case DF_Type::adventure_item_interact_give_namest: return RDF_Type::Class;
		case DF_Type::adventure_item_interact_heat_from_tilest: return RDF_Type::Class;
		case DF_Type::adventure_item_interact_pull_outst: return RDF_Type::Class;
		case DF_Type::adventure_item_interact_readst: return RDF_Type::Class;
		case DF_Type::adventure_item_interact_strugglest: return RDF_Type::Class;
		case DF_Type::adventure_log_item: return RDF_Type::Struct;
		case DF_Type::adventure_movement_attack_creaturest: return RDF_Type::Class;
		case DF_Type::adventure_movement_building_interactst: return RDF_Type::Class;
		case DF_Type::adventure_movement_climbst: return RDF_Type::Class;
		case DF_Type::adventure_movement_hold_itemst: return RDF_Type::Class;
		case DF_Type::adventure_movement_hold_tilest: return RDF_Type::Class;
		case DF_Type::adventure_movement_item_interact_guidest: return RDF_Type::Class;
		case DF_Type::adventure_movement_item_interact_pushst: return RDF_Type::Class;
		case DF_Type::adventure_movement_item_interact_ridest: return RDF_Type::Class;
		case DF_Type::adventure_movement_item_interactst: return RDF_Type::Class;
		case DF_Type::adventure_movement_movest: return RDF_Type::Class;
		case DF_Type::adventure_movement_optionst: return RDF_Type::Class;
		case DF_Type::adventure_movement_release_hold_itemst: return RDF_Type::Class;
		case DF_Type::adventure_movement_release_hold_tilest: return RDF_Type::Class;
		case DF_Type::adventure_option_eat_item_contaminantst: return RDF_Type::Class;
		case DF_Type::adventure_option_eat_unit_contaminantst: return RDF_Type::Class;
		case DF_Type::adventure_option_view_contaminantst: return RDF_Type::Class;
		case DF_Type::adventure_optionst: return RDF_Type::Class;
		case DF_Type::adventurer_attribute_level: return RDF_Type::Enum;
		case DF_Type::agreement: return RDF_Type::Struct;
		case DF_Type::agreement__T_flags: return RDF_Type::Bitfield;
		case DF_Type::agreement_details: return RDF_Type::Struct;
		case DF_Type::agreement_details__T_data: return RDF_Type::Union;
		case DF_Type::agreement_details_data_citizenship: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_demonic_binding: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_join_party: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_location: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_parley: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_plot_abduct: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_plot_assassination: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_plot_conviction: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_plot_frame_treason: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_plot_induce_war: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_plot_infiltration_coup: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_plot_sabotage: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_plot_steal_artifact: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_position_corruption: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_promise_position: return RDF_Type::Struct;
		case DF_Type::agreement_details_data_residency: return RDF_Type::Struct;
		case DF_Type::agreement_details_type: return RDF_Type::Enum;
		case DF_Type::agreement_party: return RDF_Type::Struct;
		case DF_Type::agreement_party__T_anon_1: return RDF_Type::Compound;
		case DF_Type::ammo_flags: return RDF_Type::Enum;
		case DF_Type::animal_training_level: return RDF_Type::Enum;
		case DF_Type::announcement_flags: return RDF_Type::Bitfield;
		case DF_Type::announcement_type: return RDF_Type::Enum;
		case DF_Type::announcements: return RDF_Type::Struct;
		case DF_Type::appearance_modifier_growth_interval: return RDF_Type::Enum;
		case DF_Type::appearance_modifier_type: return RDF_Type::Enum;
		case DF_Type::architectural_element: return RDF_Type::Enum;
		case DF_Type::armor_flags: return RDF_Type::Enum;
		case DF_Type::armor_general_flags: return RDF_Type::Enum;
		case DF_Type::armor_properties: return RDF_Type::Struct;
		case DF_Type::army: return RDF_Type::Struct;
		case DF_Type::army__T_members: return RDF_Type::Compound;
		case DF_Type::army__T_unk_2c: return RDF_Type::Compound;
		case DF_Type::army_controller: return RDF_Type::Struct;
		case DF_Type::army_controller__T_type: return RDF_Type::Enum;
		case DF_Type::army_controller__T_unk_64: return RDF_Type::Union;
		case DF_Type::army_controller_invasion: return RDF_Type::Struct;
		case DF_Type::army_controller_invasion__T_anon_1: return RDF_Type::Compound;
		case DF_Type::army_controller_sub11: return RDF_Type::Struct;
		case DF_Type::army_controller_sub11__T_anon_3: return RDF_Type::Compound;
		case DF_Type::army_controller_sub12: return RDF_Type::Struct;
		case DF_Type::army_controller_sub12__T_unk_4: return RDF_Type::Compound;
		case DF_Type::army_controller_sub13: return RDF_Type::Struct;
		case DF_Type::army_controller_sub13__T_anon_4: return RDF_Type::Compound;
		case DF_Type::army_controller_sub14: return RDF_Type::Struct;
		case DF_Type::army_controller_sub14__T_anon_4: return RDF_Type::Compound;
		case DF_Type::army_controller_sub15: return RDF_Type::Struct;
		case DF_Type::army_controller_sub15__T_anon_3: return RDF_Type::Compound;
		case DF_Type::army_controller_sub16: return RDF_Type::Struct;
		case DF_Type::army_controller_sub17: return RDF_Type::Struct;
		case DF_Type::army_controller_sub18: return RDF_Type::Struct;
		case DF_Type::army_controller_sub1: return RDF_Type::Struct;
		case DF_Type::army_controller_sub4: return RDF_Type::Struct;
		case DF_Type::army_controller_sub4__T_unk_2: return RDF_Type::Bitfield;
		case DF_Type::army_controller_sub5: return RDF_Type::Struct;
		case DF_Type::army_controller_sub6: return RDF_Type::Struct;
		case DF_Type::army_controller_sub7: return RDF_Type::Struct;
		case DF_Type::army_controller_sub7__T_anon_3: return RDF_Type::Compound;
		case DF_Type::army_controller_villain_visiting: return RDF_Type::Struct;
		case DF_Type::army_flags: return RDF_Type::Enum;
		case DF_Type::art_facet_type: return RDF_Type::Enum;
		case DF_Type::art_image: return RDF_Type::Struct;
		case DF_Type::art_image_chunk: return RDF_Type::Struct;
		case DF_Type::art_image_element: return RDF_Type::Class;
		case DF_Type::art_image_element_creaturest: return RDF_Type::Class;
		case DF_Type::art_image_element_itemst: return RDF_Type::Class;
		case DF_Type::art_image_element_plantst: return RDF_Type::Class;
		case DF_Type::art_image_element_shapest: return RDF_Type::Class;
		case DF_Type::art_image_element_treest: return RDF_Type::Class;
		case DF_Type::art_image_element_type: return RDF_Type::Enum;
		case DF_Type::art_image_property: return RDF_Type::Class;
		case DF_Type::art_image_property_intransitive_verbst: return RDF_Type::Class;
		case DF_Type::art_image_property_transitive_verbst: return RDF_Type::Class;
		case DF_Type::art_image_property_type: return RDF_Type::Enum;
		case DF_Type::art_image_property_verb: return RDF_Type::Enum;
		case DF_Type::art_image_ref: return RDF_Type::Struct;
		case DF_Type::artifact_claim: return RDF_Type::Struct;
		case DF_Type::artifact_claim_type: return RDF_Type::Enum;
		case DF_Type::artifact_record: return RDF_Type::Struct;
		case DF_Type::assign_trade_status: return RDF_Type::Struct;
		case DF_Type::assign_trade_status__T_status: return RDF_Type::Enum;
		case DF_Type::assume_identity_mode: return RDF_Type::Enum;
		case DF_Type::barrack_preference_category: return RDF_Type::Enum;
		case DF_Type::battlefield: return RDF_Type::Struct;
		case DF_Type::battlefield__T_sapient_deaths: return RDF_Type::Compound;
		case DF_Type::belief_system: return RDF_Type::Struct;
		case DF_Type::biome_type: return RDF_Type::Enum;
		case DF_Type::block_burrow: return RDF_Type::Struct;
		case DF_Type::block_burrow_link: return RDF_Type::Struct;
		case DF_Type::block_flags: return RDF_Type::Bitfield;
		case DF_Type::block_square_event: return RDF_Type::Class;
		case DF_Type::block_square_event_designation_priorityst: return RDF_Type::Class;
		case DF_Type::block_square_event_frozen_liquidst: return RDF_Type::Class;
		case DF_Type::block_square_event_grassst: return RDF_Type::Class;
		case DF_Type::block_square_event_item_spatterst: return RDF_Type::Class;
		case DF_Type::block_square_event_material_spatterst: return RDF_Type::Class;
		case DF_Type::block_square_event_mineralst: return RDF_Type::Class;
		case DF_Type::block_square_event_mineralst__T_flags: return RDF_Type::Bitfield;
		case DF_Type::block_square_event_spoorst: return RDF_Type::Class;
		case DF_Type::block_square_event_type: return RDF_Type::Enum;
		case DF_Type::block_square_event_world_constructionst: return RDF_Type::Class;
		case DF_Type::body_appearance_modifier: return RDF_Type::Struct;
		case DF_Type::body_component_info: return RDF_Type::Struct;
		case DF_Type::body_detail_plan: return RDF_Type::Struct;
		case DF_Type::body_layer_status: return RDF_Type::Bitfield;
		case DF_Type::body_part_layer_flags: return RDF_Type::Enum;
		case DF_Type::body_part_layer_raw: return RDF_Type::Struct;
		case DF_Type::body_part_raw: return RDF_Type::Struct;
		case DF_Type::body_part_raw_flags: return RDF_Type::Enum;
		case DF_Type::body_part_status: return RDF_Type::Bitfield;
		case DF_Type::body_part_template: return RDF_Type::Struct;
		case DF_Type::body_part_template_contype: return RDF_Type::Enum;
		case DF_Type::body_part_template_flags: return RDF_Type::Enum;
		case DF_Type::body_size_info: return RDF_Type::Struct;
		case DF_Type::body_template: return RDF_Type::Struct;
		case DF_Type::bp_appearance_modifier: return RDF_Type::Struct;
		case DF_Type::breath_attack_type: return RDF_Type::Enum;
		case DF_Type::breed: return RDF_Type::Struct;
		case DF_Type::breed__T_unk_18: return RDF_Type::Compound;
		case DF_Type::breed__T_unk_28: return RDF_Type::Compound;
		case DF_Type::breed__T_unk_8: return RDF_Type::Compound;
		case DF_Type::build_req_choice_genst: return RDF_Type::Class;
		case DF_Type::build_req_choice_specst: return RDF_Type::Class;
		case DF_Type::build_req_choice_type: return RDF_Type::Enum;
		case DF_Type::build_req_choicest: return RDF_Type::Class;
		case DF_Type::building: return RDF_Type::Class;
		case DF_Type::building__T_activities: return RDF_Type::Compound;
		case DF_Type::building__T_job_claim_suppress: return RDF_Type::Compound;
		case DF_Type::building_actual: return RDF_Type::Class;
		case DF_Type::building_actual__T_contained_items: return RDF_Type::Compound;
		case DF_Type::building_animaltrapst: return RDF_Type::Class;
		case DF_Type::building_archerytargetst: return RDF_Type::Class;
		case DF_Type::building_archerytargetst__T_archery_direction: return RDF_Type::Enum;
		case DF_Type::building_armorstandst: return RDF_Type::Class;
		case DF_Type::building_axle_horizontalst: return RDF_Type::Class;
		case DF_Type::building_axle_verticalst: return RDF_Type::Class;
		case DF_Type::building_bars_floorst: return RDF_Type::Class;
		case DF_Type::building_bars_verticalst: return RDF_Type::Class;
		case DF_Type::building_bedst: return RDF_Type::Class;
		case DF_Type::building_bedst__T_bed_flags: return RDF_Type::Bitfield;
		case DF_Type::building_bookcasest: return RDF_Type::Class;
		case DF_Type::building_boxst: return RDF_Type::Class;
		case DF_Type::building_bridgest: return RDF_Type::Class;
		case DF_Type::building_bridgest__T_direction: return RDF_Type::Enum;
		case DF_Type::building_cabinetst: return RDF_Type::Class;
		case DF_Type::building_cagest: return RDF_Type::Class;
		case DF_Type::building_cagest__T_cage_flags: return RDF_Type::Bitfield;
		case DF_Type::building_chainst: return RDF_Type::Class;
		case DF_Type::building_chainst__T_chain_flags: return RDF_Type::Bitfield;
		case DF_Type::building_chairst: return RDF_Type::Class;
		case DF_Type::building_civzonest: return RDF_Type::Class;
		case DF_Type::building_civzonest__T_gather_flags: return RDF_Type::Bitfield;
		case DF_Type::building_civzonest__T_pit_flags: return RDF_Type::Bitfield;
		case DF_Type::building_civzonest__T_zone_flags: return RDF_Type::Bitfield;
		case DF_Type::building_coffinst: return RDF_Type::Class;
		case DF_Type::building_coffinst__T_burial_mode: return RDF_Type::Bitfield;
		case DF_Type::building_constructionst: return RDF_Type::Class;
		case DF_Type::building_def: return RDF_Type::Class;
		case DF_Type::building_def_furnacest: return RDF_Type::Class;
		case DF_Type::building_def_item: return RDF_Type::Struct;
		case DF_Type::building_def_workshopst: return RDF_Type::Class;
		case DF_Type::building_design: return RDF_Type::Struct;
		case DF_Type::building_design__T_flags: return RDF_Type::Bitfield;
		case DF_Type::building_display_furniturest: return RDF_Type::Class;
		case DF_Type::building_doorst: return RDF_Type::Class;
		case DF_Type::building_drawbuffer: return RDF_Type::Struct;
		case DF_Type::building_extents: return RDF_Type::Struct;
		case DF_Type::building_farmplotst: return RDF_Type::Class;
		case DF_Type::building_flags: return RDF_Type::Bitfield;
		case DF_Type::building_floodgatest: return RDF_Type::Class;
		case DF_Type::building_furnacest: return RDF_Type::Class;
		case DF_Type::building_gear_assemblyst: return RDF_Type::Class;
		case DF_Type::building_gear_assemblyst__T_gear_flags: return RDF_Type::Bitfield;
		case DF_Type::building_grate_floorst: return RDF_Type::Class;
		case DF_Type::building_grate_wallst: return RDF_Type::Class;
		case DF_Type::building_handler: return RDF_Type::Class;
		case DF_Type::building_hatchst: return RDF_Type::Class;
		case DF_Type::building_hivest: return RDF_Type::Class;
		case DF_Type::building_instrumentst: return RDF_Type::Class;
		case DF_Type::building_nest_boxst: return RDF_Type::Class;
		case DF_Type::building_nestst: return RDF_Type::Class;
		case DF_Type::building_offering_placest: return RDF_Type::Class;
		case DF_Type::building_road_dirtst: return RDF_Type::Class;
		case DF_Type::building_road_pavedst: return RDF_Type::Class;
		case DF_Type::building_roadst: return RDF_Type::Class;
		case DF_Type::building_rollersst: return RDF_Type::Class;
		case DF_Type::building_screw_pumpst: return RDF_Type::Class;
		case DF_Type::building_shopst: return RDF_Type::Class;
		case DF_Type::building_shopst__T_shop_flags: return RDF_Type::Bitfield;
		case DF_Type::building_siegeenginest: return RDF_Type::Class;
		case DF_Type::building_siegeenginest__T_action: return RDF_Type::Enum;
		case DF_Type::building_siegeenginest__T_facing: return RDF_Type::Enum;
		case DF_Type::building_slabst: return RDF_Type::Class;
		case DF_Type::building_squad_use: return RDF_Type::Struct;
		case DF_Type::building_statuest: return RDF_Type::Class;
		case DF_Type::building_stockpilest: return RDF_Type::Class;
		case DF_Type::building_supportst: return RDF_Type::Class;
		case DF_Type::building_supportst__T_support_flags: return RDF_Type::Bitfield;
		case DF_Type::building_tablest: return RDF_Type::Class;
		case DF_Type::building_tablest__T_table_flags: return RDF_Type::Bitfield;
		case DF_Type::building_traction_benchst: return RDF_Type::Class;
		case DF_Type::building_tradedepotst: return RDF_Type::Class;
		case DF_Type::building_tradedepotst__T_trade_flags: return RDF_Type::Bitfield;
		case DF_Type::building_trapst: return RDF_Type::Class;
		case DF_Type::building_trapst__T_stop_flags: return RDF_Type::Bitfield;
		case DF_Type::building_type: return RDF_Type::Enum;
		case DF_Type::building_users: return RDF_Type::Struct;
		case DF_Type::building_wagonst: return RDF_Type::Class;
		case DF_Type::building_water_wheelst: return RDF_Type::Class;
		case DF_Type::building_weaponrackst: return RDF_Type::Class;
		case DF_Type::building_weaponst: return RDF_Type::Class;
		case DF_Type::building_wellst: return RDF_Type::Class;
		case DF_Type::building_wellst__T_well_flags: return RDF_Type::Bitfield;
		case DF_Type::building_windmillst: return RDF_Type::Class;
		case DF_Type::building_window_gemst: return RDF_Type::Class;
		case DF_Type::building_window_glassst: return RDF_Type::Class;
		case DF_Type::building_windowst: return RDF_Type::Class;
		case DF_Type::building_workshopst: return RDF_Type::Class;
		case DF_Type::buildings_other_id: return RDF_Type::Enum;
		case DF_Type::builtin_mats: return RDF_Type::Enum;
		case DF_Type::burrow: return RDF_Type::Struct;
		case DF_Type::campfire: return RDF_Type::Struct;
		case DF_Type::caravan_state: return RDF_Type::Struct;
		case DF_Type::caravan_state__T_flags: return RDF_Type::Bitfield;
		case DF_Type::caravan_state__T_trade_state: return RDF_Type::Enum;
		case DF_Type::caste_attack: return RDF_Type::Struct;
		case DF_Type::caste_attack__T_flags: return RDF_Type::Bitfield;
		case DF_Type::caste_body_info: return RDF_Type::Struct;
		case DF_Type::caste_body_info__T_extra_butcher_objects: return RDF_Type::Compound;
		case DF_Type::caste_body_info__T_flags: return RDF_Type::Bitfield;
		case DF_Type::caste_body_info__T_interactions: return RDF_Type::Compound;
		case DF_Type::caste_body_info__T_interactions__T_type: return RDF_Type::Enum;
		case DF_Type::caste_clothing_item: return RDF_Type::Struct;
		case DF_Type::caste_raw: return RDF_Type::Struct;
		case DF_Type::caste_raw__T_anon_1: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_attributes: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_bp_appearance: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_caste_profession_name: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_extracts: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_lair_hunter_speech: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_misc: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_personality: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_secretion: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_shearable_tissue_layer: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_sound: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_unk29: return RDF_Type::Compound;
		case DF_Type::caste_raw__T_unknown2: return RDF_Type::Compound;
		case DF_Type::caste_raw_flags: return RDF_Type::Enum;
		case DF_Type::cave_column: return RDF_Type::Class;
		case DF_Type::cave_column_link: return RDF_Type::Struct;
		case DF_Type::cave_column_rectangle: return RDF_Type::Class;
		case DF_Type::cie_add_tag_mask1: return RDF_Type::Bitfield;
		case DF_Type::cie_add_tag_mask2: return RDF_Type::Bitfield;
		case DF_Type::civzone_type: return RDF_Type::Enum;
		case DF_Type::coin_batch: return RDF_Type::Struct;
		case DF_Type::coin_batch__T_image_back: return RDF_Type::Compound;
		case DF_Type::coin_batch__T_image_front: return RDF_Type::Compound;
		case DF_Type::color_modifier_raw: return RDF_Type::Struct;
		case DF_Type::combat_report_event_type: return RDF_Type::Enum;
		case DF_Type::conflict_level: return RDF_Type::Enum;
		case DF_Type::construction: return RDF_Type::Struct;
		case DF_Type::construction_flags: return RDF_Type::Bitfield;
		case DF_Type::construction_type: return RDF_Type::Enum;
		case DF_Type::conversation: return RDF_Type::Struct;
		case DF_Type::conversation__T_speech: return RDF_Type::Compound;
		case DF_Type::conversation__T_state: return RDF_Type::Enum;
		case DF_Type::conversation_menu: return RDF_Type::Enum;
		case DF_Type::coord2d: return RDF_Type::Struct;
		case DF_Type::coord2d_path: return RDF_Type::Struct;
		case DF_Type::coord: return RDF_Type::Struct;
		case DF_Type::coord_path: return RDF_Type::Struct;
		case DF_Type::coord_rect: return RDF_Type::Struct;
		case DF_Type::corpse_material_type: return RDF_Type::Enum;
		case DF_Type::craft_material_class: return RDF_Type::Enum;
		case DF_Type::creation_zone_pwg_alteration_campst: return RDF_Type::Class;
		case DF_Type::creation_zone_pwg_alteration_location_deathst: return RDF_Type::Class;
		case DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1: return RDF_Type::Compound;
		case DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1: return RDF_Type::Compound;
		case DF_Type::creation_zone_pwg_alteration_srb_ruinedst: return RDF_Type::Class;
		case DF_Type::creation_zone_pwg_alteration_srp_ruinedst: return RDF_Type::Class;
		case DF_Type::creation_zone_pwg_alteration_type: return RDF_Type::Enum;
		case DF_Type::creation_zone_pwg_alterationst: return RDF_Type::Class;
		case DF_Type::creature_graphics_appointment: return RDF_Type::Struct;
		case DF_Type::creature_graphics_role: return RDF_Type::Enum;
		case DF_Type::creature_handler: return RDF_Type::Class;
		case DF_Type::creature_interaction: return RDF_Type::Struct;
		case DF_Type::creature_interaction__T_flags: return RDF_Type::Bitfield;
		case DF_Type::creature_interaction_effect: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect__T_counter_trigger: return RDF_Type::Compound;
		case DF_Type::creature_interaction_effect_add_simple_flagst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_bleedingst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_blistersst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_body_appearance_modifierst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_body_mat_interactionst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_body_transformationst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_bp_appearance_modifierst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_bruisingst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_can_do_interactionst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_change_personalityst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_close_open_woundsst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_cough_bloodst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_cure_infectionsst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_cure_infectionst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_display_namest: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_display_symbolst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_dizzinessst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_drowsinessst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_erratic_behaviorst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_feel_emotionst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_feverst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_flags: return RDF_Type::Bitfield;
		case DF_Type::creature_interaction_effect_flash_symbolst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_heal_nervesst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_heal_tissuesst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_impair_functionst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_material_force_adjustst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_ment_att_changest: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_nauseast: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_necrosisst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_numbnessst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_oozingst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_painst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_paralysisst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_phys_att_changest: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_reduce_dizzinessst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_reduce_feverst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_reduce_nauseast: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_reduce_painst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_reduce_paralysisst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_reduce_swellingst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_regrow_partsst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_remove_simple_flagst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_sense_creature_classst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_skill_roll_adjustst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_special_attack_interactionst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_speed_changest: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_stop_bleedingst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_swellingst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_target: return RDF_Type::Struct;
		case DF_Type::creature_interaction_effect_target_mode: return RDF_Type::Enum;
		case DF_Type::creature_interaction_effect_type: return RDF_Type::Enum;
		case DF_Type::creature_interaction_effect_unconsciousnessst: return RDF_Type::Class;
		case DF_Type::creature_interaction_effect_vomit_bloodst: return RDF_Type::Class;
		case DF_Type::creature_interaction_target_flags: return RDF_Type::Bitfield;
		case DF_Type::creature_raw: return RDF_Type::Struct;
		case DF_Type::creature_raw__T_graphics: return RDF_Type::Compound;
		case DF_Type::creature_raw__T_hive_product: return RDF_Type::Compound;
		case DF_Type::creature_raw__T_profession_name: return RDF_Type::Compound;
		case DF_Type::creature_raw_flags: return RDF_Type::Enum;
		case DF_Type::creature_variation: return RDF_Type::Struct;
		case DF_Type::creature_variation_convert_tag: return RDF_Type::Struct;
		case DF_Type::crime: return RDF_Type::Struct;
		case DF_Type::crime__T_convict_data: return RDF_Type::Compound;
		case DF_Type::crime__T_counterintelligence: return RDF_Type::Compound;
		case DF_Type::crime__T_flags: return RDF_Type::Bitfield;
		case DF_Type::crime__T_mode: return RDF_Type::Enum;
		case DF_Type::crime__T_punishment: return RDF_Type::Compound;
		case DF_Type::crime__T_reports: return RDF_Type::Compound;
		case DF_Type::crime__T_victim_data: return RDF_Type::Compound;
		case DF_Type::crime_type: return RDF_Type::Enum;
		case DF_Type::cultural_identity: return RDF_Type::Struct;
		case DF_Type::cultural_identity__T_anon_1: return RDF_Type::Compound;
		case DF_Type::cultural_identity__T_anon_2: return RDF_Type::Compound;
		case DF_Type::cultural_identity__T_group_log: return RDF_Type::Compound;
		case DF_Type::cultural_identity__T_group_log__T_join_type: return RDF_Type::Enum;
		case DF_Type::cumulus_type: return RDF_Type::Enum;
		case DF_Type::curse_attr_change: return RDF_Type::Struct;
		case DF_Type::d_init: return RDF_Type::Struct;
		case DF_Type::d_init__T_store_dist: return RDF_Type::Compound;
		case DF_Type::d_init__T_wound_color: return RDF_Type::Compound;
		case DF_Type::d_init_embark_confirm: return RDF_Type::Enum;
		case DF_Type::d_init_flags1: return RDF_Type::Enum;
		case DF_Type::d_init_flags2: return RDF_Type::Enum;
		case DF_Type::d_init_flags3: return RDF_Type::Enum;
		case DF_Type::d_init_flags4: return RDF_Type::Enum;
		case DF_Type::d_init_idlers: return RDF_Type::Enum;
		case DF_Type::d_init_nickname: return RDF_Type::Enum;
		case DF_Type::d_init_tunnel: return RDF_Type::Enum;
		case DF_Type::d_init_z_view: return RDF_Type::Enum;
		case DF_Type::dance_form: return RDF_Type::Struct;
		case DF_Type::dance_form_sub1: return RDF_Type::Struct;
		case DF_Type::dance_form_sub2: return RDF_Type::Struct;
		case DF_Type::death_condition_type: return RDF_Type::Enum;
		case DF_Type::death_type: return RDF_Type::Enum;
		case DF_Type::deep_vein_hollow: return RDF_Type::Struct;
		case DF_Type::descriptor_color: return RDF_Type::Struct;
		case DF_Type::descriptor_pattern: return RDF_Type::Struct;
		case DF_Type::descriptor_shape: return RDF_Type::Struct;
		case DF_Type::descriptor_shape__T_gems_use: return RDF_Type::Bitfield;
		case DF_Type::dfhack_knowledge_scholar_flag: return RDF_Type::Enum;
		case DF_Type::dfhack_material_category: return RDF_Type::Bitfield;
		case DF_Type::dfhack_room_quality_level: return RDF_Type::Enum;
		case DF_Type::dipscript_info: return RDF_Type::Struct;
		case DF_Type::dipscript_popup: return RDF_Type::Struct;
		case DF_Type::dipscript_popup__T_flags: return RDF_Type::Bitfield;
		case DF_Type::divination_set: return RDF_Type::Struct;
		case DF_Type::divination_set_roll: return RDF_Type::Struct;
		case DF_Type::door_flags: return RDF_Type::Bitfield;
		case DF_Type::dye_info: return RDF_Type::Struct;
		case DF_Type::effect_info: return RDF_Type::Struct;
		case DF_Type::embark_feature: return RDF_Type::Struct;
		case DF_Type::embark_finder_option: return RDF_Type::Enum;
		case DF_Type::embark_item_choice: return RDF_Type::Struct;
		case DF_Type::embark_item_choice__T_list: return RDF_Type::Compound;
		case DF_Type::embark_location: return RDF_Type::Struct;
		case DF_Type::embark_note: return RDF_Type::Struct;
		case DF_Type::embark_profile: return RDF_Type::Struct;
		case DF_Type::emotion_type: return RDF_Type::Enum;
		case DF_Type::engraving: return RDF_Type::Struct;
		case DF_Type::engraving_flags: return RDF_Type::Bitfield;
		case DF_Type::entity_action_type: return RDF_Type::Enum;
		case DF_Type::entity_activity_statistics: return RDF_Type::Struct;
		case DF_Type::entity_activity_statistics__T_food: return RDF_Type::Compound;
		case DF_Type::entity_activity_statistics__T_found_misc: return RDF_Type::Bitfield;
		case DF_Type::entity_activity_statistics__T_wealth: return RDF_Type::Compound;
		case DF_Type::entity_animal_raw: return RDF_Type::Struct;
		case DF_Type::entity_animal_raw__T_flags: return RDF_Type::Bitfield;
		case DF_Type::entity_buy_prices: return RDF_Type::Struct;
		case DF_Type::entity_buy_requests: return RDF_Type::Struct;
		case DF_Type::entity_claim_mask: return RDF_Type::Struct;
		case DF_Type::entity_claim_mask__T_map: return RDF_Type::Compound;
		case DF_Type::entity_entity_link: return RDF_Type::Struct;
		case DF_Type::entity_entity_link_type: return RDF_Type::Enum;
		case DF_Type::entity_event: return RDF_Type::Struct;
		case DF_Type::entity_event__T_data: return RDF_Type::Union;
		case DF_Type::entity_event__T_data__T_abandon: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_abduction: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_accept_peace_offer: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_accept_tribute_demand: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_accept_tribute_offer: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_artifact_destroyed: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_artifact_in_feature_layer: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_artifact_in_inventory: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_artifact_in_site: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_artifact_in_subregion: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_artifact_not_in_feature_layer: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_artifact_not_in_inventory: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_artifact_not_in_site: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_artifact_not_in_subregion: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_beast: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_cease_tribute_offer: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_claim: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_flee: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_founded: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_founding: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_group: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_harass: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_incident: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_insurrection: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_insurrection_end: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_insurrection_end__T_result: return RDF_Type::Enum;
		case DF_Type::entity_event__T_data__T_invasion: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_leave: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_occupation: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_reclaimed: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_reclaiming: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_refuse_peace_offer: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_refuse_tribute_demand: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_refuse_tribute_offer: return RDF_Type::Compound;
		case DF_Type::entity_event__T_data__T_succession: return RDF_Type::Compound;
		case DF_Type::entity_event_type: return RDF_Type::Enum;
		case DF_Type::entity_material_category: return RDF_Type::Enum;
		case DF_Type::entity_name_type: return RDF_Type::Enum;
		case DF_Type::entity_occasion: return RDF_Type::Struct;
		case DF_Type::entity_occasion_info: return RDF_Type::Struct;
		case DF_Type::entity_occasion_schedule: return RDF_Type::Struct;
		case DF_Type::entity_occasion_schedule_feature: return RDF_Type::Struct;
		case DF_Type::entity_population: return RDF_Type::Struct;
		case DF_Type::entity_population_unk4: return RDF_Type::Struct;
		case DF_Type::entity_population_unk4__T_anon_1: return RDF_Type::Compound;
		case DF_Type::entity_population_unk4__T_anon_2: return RDF_Type::Compound;
		case DF_Type::entity_population_unk4__T_anon_3: return RDF_Type::Compound;
		case DF_Type::entity_position: return RDF_Type::Struct;
		case DF_Type::entity_position_assignment: return RDF_Type::Struct;
		case DF_Type::entity_position_flags: return RDF_Type::Enum;
		case DF_Type::entity_position_raw: return RDF_Type::Struct;
		case DF_Type::entity_position_raw_flags: return RDF_Type::Enum;
		case DF_Type::entity_position_responsibility: return RDF_Type::Enum;
		case DF_Type::entity_raw: return RDF_Type::Struct;
		case DF_Type::entity_raw__T_equipment: return RDF_Type::Compound;
		case DF_Type::entity_raw__T_jobs: return RDF_Type::Compound;
		case DF_Type::entity_raw__T_land_holder_trigger: return RDF_Type::Compound;
		case DF_Type::entity_raw__T_progress_trigger: return RDF_Type::Compound;
		case DF_Type::entity_raw__T_scholar: return RDF_Type::Bitfield;
		case DF_Type::entity_raw__T_symbols: return RDF_Type::Compound;
		case DF_Type::entity_raw__T_tissue_styles: return RDF_Type::Compound;
		case DF_Type::entity_raw__T_workshops: return RDF_Type::Compound;
		case DF_Type::entity_raw_flags: return RDF_Type::Enum;
		case DF_Type::entity_recipe: return RDF_Type::Struct;
		case DF_Type::entity_sell_category: return RDF_Type::Enum;
		case DF_Type::entity_sell_prices: return RDF_Type::Struct;
		case DF_Type::entity_sell_requests: return RDF_Type::Struct;
		case DF_Type::entity_site_link: return RDF_Type::Struct;
		case DF_Type::entity_site_link__T_unk_7: return RDF_Type::Compound;
		case DF_Type::entity_site_link_flags: return RDF_Type::Bitfield;
		case DF_Type::entity_site_link_status_flags: return RDF_Type::Bitfield;
		case DF_Type::entity_site_link_type: return RDF_Type::Enum;
		case DF_Type::entity_tissue_style: return RDF_Type::Struct;
		case DF_Type::entity_uniform: return RDF_Type::Struct;
		case DF_Type::entity_uniform_item: return RDF_Type::Struct;
		case DF_Type::entity_unk_v47_1: return RDF_Type::Struct;
		case DF_Type::environment_type: return RDF_Type::Enum;
		case DF_Type::era_type: return RDF_Type::Enum;
		case DF_Type::ethic_response: return RDF_Type::Enum;
		case DF_Type::ethic_type: return RDF_Type::Enum;
		case DF_Type::export_map_type: return RDF_Type::Enum;
		case DF_Type::feature: return RDF_Type::Class;
		case DF_Type::feature_alteration: return RDF_Type::Class;
		case DF_Type::feature_alteration_new_lava_fill_zst: return RDF_Type::Class;
		case DF_Type::feature_alteration_new_pop_maxst: return RDF_Type::Class;
		case DF_Type::feature_alteration_type: return RDF_Type::Enum;
		case DF_Type::feature_cavest: return RDF_Type::Class;
		case DF_Type::feature_deep_special_tubest: return RDF_Type::Class;
		case DF_Type::feature_deep_surface_portalst: return RDF_Type::Class;
		case DF_Type::feature_init: return RDF_Type::Class;
		case DF_Type::feature_init_cavest: return RDF_Type::Class;
		case DF_Type::feature_init_deep_special_tubest: return RDF_Type::Class;
		case DF_Type::feature_init_deep_surface_portalst: return RDF_Type::Class;
		case DF_Type::feature_init_flags: return RDF_Type::Enum;
		case DF_Type::feature_init_magma_core_from_layerst: return RDF_Type::Class;
		case DF_Type::feature_init_magma_poolst: return RDF_Type::Class;
		case DF_Type::feature_init_outdoor_riverst: return RDF_Type::Class;
		case DF_Type::feature_init_pitst: return RDF_Type::Class;
		case DF_Type::feature_init_subterranean_from_layerst: return RDF_Type::Class;
		case DF_Type::feature_init_underworld_from_layerst: return RDF_Type::Class;
		case DF_Type::feature_init_volcanost: return RDF_Type::Class;
		case DF_Type::feature_magma_core_from_layerst: return RDF_Type::Class;
		case DF_Type::feature_magma_poolst: return RDF_Type::Class;
		case DF_Type::feature_outdoor_riverst: return RDF_Type::Class;
		case DF_Type::feature_pitst: return RDF_Type::Class;
		case DF_Type::feature_subterranean_from_layerst: return RDF_Type::Class;
		case DF_Type::feature_type: return RDF_Type::Enum;
		case DF_Type::feature_underworld_from_layerst: return RDF_Type::Class;
		case DF_Type::feature_volcanost: return RDF_Type::Class;
		case DF_Type::file_compressorst: return RDF_Type::Struct;
		case DF_Type::fire: return RDF_Type::Struct;
		case DF_Type::flow_guide: return RDF_Type::Class;
		case DF_Type::flow_guide_item_cloudst: return RDF_Type::Class;
		case DF_Type::flow_guide_trailing_flowst: return RDF_Type::Class;
		case DF_Type::flow_guide_type: return RDF_Type::Enum;
		case DF_Type::flow_info: return RDF_Type::Struct;
		case DF_Type::flow_reuse_pool: return RDF_Type::Struct;
		case DF_Type::flow_reuse_pool__T_flags: return RDF_Type::Bitfield;
		case DF_Type::flow_type: return RDF_Type::Enum;
		case DF_Type::fog_type: return RDF_Type::Enum;
		case DF_Type::fortress_type: return RDF_Type::Enum;
		case DF_Type::front_type: return RDF_Type::Enum;
		case DF_Type::furnace_type: return RDF_Type::Enum;
		case DF_Type::furniture_type: return RDF_Type::Enum;
		case DF_Type::gait_info: return RDF_Type::Struct;
		case DF_Type::gait_info__T_flags: return RDF_Type::Bitfield;
		case DF_Type::gait_type: return RDF_Type::Enum;
		case DF_Type::game_mode: return RDF_Type::Enum;
		case DF_Type::game_type: return RDF_Type::Enum;
		case DF_Type::gate_flags: return RDF_Type::Bitfield;
		case DF_Type::general_ref: return RDF_Type::Class;
		case DF_Type::general_ref_abstract_buildingst: return RDF_Type::Class;
		case DF_Type::general_ref_activity_eventst: return RDF_Type::Class;
		case DF_Type::general_ref_artifact: return RDF_Type::Class;
		case DF_Type::general_ref_building: return RDF_Type::Class;
		case DF_Type::general_ref_building_cagedst: return RDF_Type::Class;
		case DF_Type::general_ref_building_chainst: return RDF_Type::Class;
		case DF_Type::general_ref_building_civzone_assignedst: return RDF_Type::Class;
		case DF_Type::general_ref_building_destinationst: return RDF_Type::Class;
		case DF_Type::general_ref_building_display_furniturest: return RDF_Type::Class;
		case DF_Type::general_ref_building_holderst: return RDF_Type::Class;
		case DF_Type::general_ref_building_nest_boxst: return RDF_Type::Class;
		case DF_Type::general_ref_building_triggerst: return RDF_Type::Class;
		case DF_Type::general_ref_building_triggertargetst: return RDF_Type::Class;
		case DF_Type::general_ref_building_use_target_1st: return RDF_Type::Class;
		case DF_Type::general_ref_building_use_target_2st: return RDF_Type::Class;
		case DF_Type::general_ref_building_well_tag: return RDF_Type::Class;
		case DF_Type::general_ref_coinbatch: return RDF_Type::Class;
		case DF_Type::general_ref_contained_in_itemst: return RDF_Type::Class;
		case DF_Type::general_ref_contains_itemst: return RDF_Type::Class;
		case DF_Type::general_ref_contains_unitst: return RDF_Type::Class;
		case DF_Type::general_ref_creaturest: return RDF_Type::Class;
		case DF_Type::general_ref_dance_formst: return RDF_Type::Class;
		case DF_Type::general_ref_entity: return RDF_Type::Class;
		case DF_Type::general_ref_entity_art_image: return RDF_Type::Class;
		case DF_Type::general_ref_entity_itemownerst: return RDF_Type::Class;
		case DF_Type::general_ref_entity_offeredst: return RDF_Type::Class;
		case DF_Type::general_ref_entity_popst: return RDF_Type::Class;
		case DF_Type::general_ref_entity_stolenst: return RDF_Type::Class;
		case DF_Type::general_ref_feature_layerst: return RDF_Type::Class;
		case DF_Type::general_ref_historical_eventst: return RDF_Type::Class;
		case DF_Type::general_ref_historical_figurest: return RDF_Type::Class;
		case DF_Type::general_ref_interactionst: return RDF_Type::Class;
		case DF_Type::general_ref_is_artifactst: return RDF_Type::Class;
		case DF_Type::general_ref_is_nemesisst: return RDF_Type::Class;
		case DF_Type::general_ref_item: return RDF_Type::Class;
		case DF_Type::general_ref_item_type: return RDF_Type::Class;
		case DF_Type::general_ref_knowledge_scholar_flagst: return RDF_Type::Class;
		case DF_Type::general_ref_languagest: return RDF_Type::Class;
		case DF_Type::general_ref_locationst: return RDF_Type::Class;
		case DF_Type::general_ref_mapsquare: return RDF_Type::Class;
		case DF_Type::general_ref_musical_formst: return RDF_Type::Class;
		case DF_Type::general_ref_nemesis: return RDF_Type::Class;
		case DF_Type::general_ref_poetic_formst: return RDF_Type::Class;
		case DF_Type::general_ref_projectile: return RDF_Type::Class;
		case DF_Type::general_ref_sitest: return RDF_Type::Class;
		case DF_Type::general_ref_spherest: return RDF_Type::Class;
		case DF_Type::general_ref_subregionst: return RDF_Type::Class;
		case DF_Type::general_ref_type: return RDF_Type::Enum;
		case DF_Type::general_ref_unit: return RDF_Type::Class;
		case DF_Type::general_ref_unit_beateest: return RDF_Type::Class;
		case DF_Type::general_ref_unit_cageest: return RDF_Type::Class;
		case DF_Type::general_ref_unit_climberst: return RDF_Type::Class;
		case DF_Type::general_ref_unit_foodreceiverst: return RDF_Type::Class;
		case DF_Type::general_ref_unit_geldeest: return RDF_Type::Class;
		case DF_Type::general_ref_unit_holderst: return RDF_Type::Class;
		case DF_Type::general_ref_unit_infantst: return RDF_Type::Class;
		case DF_Type::general_ref_unit_interrogateest: return RDF_Type::Class;
		case DF_Type::general_ref_unit_itemownerst: return RDF_Type::Class;
		case DF_Type::general_ref_unit_itemownerst__T_flags: return RDF_Type::Bitfield;
		case DF_Type::general_ref_unit_kidnapeest: return RDF_Type::Class;
		case DF_Type::general_ref_unit_milkeest: return RDF_Type::Class;
		case DF_Type::general_ref_unit_patientst: return RDF_Type::Class;
		case DF_Type::general_ref_unit_reporteest: return RDF_Type::Class;
		case DF_Type::general_ref_unit_riderst: return RDF_Type::Class;
		case DF_Type::general_ref_unit_sheareest: return RDF_Type::Class;
		case DF_Type::general_ref_unit_slaughtereest: return RDF_Type::Class;
		case DF_Type::general_ref_unit_suckeest: return RDF_Type::Class;
		case DF_Type::general_ref_unit_tradebringerst: return RDF_Type::Class;
		case DF_Type::general_ref_unit_traineest: return RDF_Type::Class;
		case DF_Type::general_ref_unit_workerst: return RDF_Type::Class;
		case DF_Type::general_ref_value_levelst: return RDF_Type::Class;
		case DF_Type::general_ref_written_contentst: return RDF_Type::Class;
		case DF_Type::geo_layer_type: return RDF_Type::Enum;
		case DF_Type::ghost_goal: return RDF_Type::Enum;
		case DF_Type::ghost_type: return RDF_Type::Enum;
		case DF_Type::gloves_flags: return RDF_Type::Enum;
		case DF_Type::glowing_barrier: return RDF_Type::Struct;
		case DF_Type::goal_type: return RDF_Type::Enum;
		case DF_Type::graphic: return RDF_Type::Struct;
		case DF_Type::guild_id: return RDF_Type::Enum;
		case DF_Type::hauler_type: return RDF_Type::Enum;
		case DF_Type::hauling_route: return RDF_Type::Struct;
		case DF_Type::hauling_stop: return RDF_Type::Struct;
		case DF_Type::health_view_bits1: return RDF_Type::Bitfield;
		case DF_Type::health_view_bits2: return RDF_Type::Bitfield;
		case DF_Type::health_view_bits3: return RDF_Type::Bitfield;
		case DF_Type::helm_flags: return RDF_Type::Enum;
		case DF_Type::hillock_house_type: return RDF_Type::Enum;
		case DF_Type::histfig_body_state: return RDF_Type::Enum;
		case DF_Type::histfig_entity_link: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_criminalst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_enemyst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_former_memberst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_former_mercenaryst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_former_occupationst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_former_positionst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_former_prisonerst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_former_slavest: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_former_squadst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_memberst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_mercenaryst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_occupationst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_position_claimst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_positionst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_prisonerst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_slavest: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_squadst: return RDF_Type::Class;
		case DF_Type::histfig_entity_link_type: return RDF_Type::Enum;
		case DF_Type::histfig_flags: return RDF_Type::Enum;
		case DF_Type::histfig_hf_link: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_apprenticest: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_childst: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_companionst: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_deceased_spousest: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_deityst: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_fatherst: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_former_apprenticest: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_former_masterst: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_former_spousest: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_imprisonerst: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_loverst: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_masterst: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_motherst: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_pet_ownerst: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_prisonerst: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_spousest: return RDF_Type::Class;
		case DF_Type::histfig_hf_link_type: return RDF_Type::Enum;
		case DF_Type::histfig_relationship_type: return RDF_Type::Enum;
		case DF_Type::histfig_site_link: return RDF_Type::Class;
		case DF_Type::histfig_site_link_hangoutst: return RDF_Type::Class;
		case DF_Type::histfig_site_link_home_site_abstract_buildingst: return RDF_Type::Class;
		case DF_Type::histfig_site_link_home_site_realization_buildingst: return RDF_Type::Class;
		case DF_Type::histfig_site_link_home_site_realization_sulst: return RDF_Type::Class;
		case DF_Type::histfig_site_link_home_site_saved_civzonest: return RDF_Type::Class;
		case DF_Type::histfig_site_link_lairst: return RDF_Type::Class;
		case DF_Type::histfig_site_link_occupationst: return RDF_Type::Class;
		case DF_Type::histfig_site_link_prison_abstract_buildingst: return RDF_Type::Class;
		case DF_Type::histfig_site_link_prison_site_building_profilest: return RDF_Type::Class;
		case DF_Type::histfig_site_link_seat_of_powerst: return RDF_Type::Class;
		case DF_Type::histfig_site_link_type: return RDF_Type::Enum;
		case DF_Type::historical_entity: return RDF_Type::Struct;
		case DF_Type::historical_entity__T_claims: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_derived_resources: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_flags: return RDF_Type::Bitfield;
		case DF_Type::historical_entity__T_guild_professions: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_positions: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_relations: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_relations__T_constructions: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_relations__T_diplomacy: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_resources: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_resources__T_animals: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_resources__T_metal: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_resources__T_misc_mat: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_resources__T_organic: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_resources__T_refuse: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_resources__T_unk13: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_resources__T_wood_products: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_tissue_styles: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_training_knowledge: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_unk_v47_1: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_unknown1d: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_unknown1e: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_unknown2: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_unknown2__T_unk28: return RDF_Type::Compound;
		case DF_Type::historical_entity__T_unknown2__T_unk29: return RDF_Type::Compound;
		case DF_Type::historical_entity_type: return RDF_Type::Enum;
		case DF_Type::historical_figure: return RDF_Type::Struct;
		case DF_Type::historical_figure__T_unk_fc: return RDF_Type::Compound;
		case DF_Type::historical_figure__T_unk_v47_2: return RDF_Type::Compound;
		case DF_Type::historical_figure__T_vague_relationships: return RDF_Type::Compound;
		case DF_Type::historical_figure_info: return RDF_Type::Struct;
		case DF_Type::historical_figure_info__T_books: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_books__T_flags: return RDF_Type::Bitfield;
		case DF_Type::historical_figure_info__T_curse: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_curse__T_anon_1: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_curse__T_experiments: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_known_info: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_known_info__T_anon_1: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_known_info__T_anon_6: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_known_info__T_knowledge: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal: return RDF_Type::Bitfield;
		case DF_Type::historical_figure_info__T_known_info__T_unk_a8: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_masterpieces: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_personality: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_relationships: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_relationships__T_anon_1: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_relationships__T_artifact_claims: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_relationships__T_hf_historical: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_relationships__T_hf_visual: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_relationships__T_intrigues: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_intrigue: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data: return RDF_Type::Union;
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Infiltrate_Society: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Sabotage_Actor: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type: return RDF_Type::Enum;
		case DF_Type::historical_figure_info__T_reputation: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_reputation__T_anon_1: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_reputation__T_unk_2c: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_reputation__T_unk_2c__T_anon_12: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_reputation__T_wanted: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_reputation__T_wanted__T_unk: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_skills: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_skills__T_employment_held: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_skills__T_employment_held__T_employment: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_whereabouts: return RDF_Type::Compound;
		case DF_Type::historical_figure_info__T_wounds: return RDF_Type::Compound;
		case DF_Type::historical_kills: return RDF_Type::Struct;
		case DF_Type::history_era: return RDF_Type::Struct;
		case DF_Type::history_era__T_details: return RDF_Type::Compound;
		case DF_Type::history_era__T_title: return RDF_Type::Compound;
		case DF_Type::history_event: return RDF_Type::Class;
		case DF_Type::history_event_add_entity_site_profile_flagst: return RDF_Type::Class;
		case DF_Type::history_event_add_hf_entity_honorst: return RDF_Type::Class;
		case DF_Type::history_event_add_hf_entity_linkst: return RDF_Type::Class;
		case DF_Type::history_event_add_hf_hf_linkst: return RDF_Type::Class;
		case DF_Type::history_event_add_hf_site_linkst: return RDF_Type::Class;
		case DF_Type::history_event_agreement_concludedst: return RDF_Type::Class;
		case DF_Type::history_event_agreement_formedst: return RDF_Type::Class;
		case DF_Type::history_event_agreements_voidedst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_claim_formedst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_copiedst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_copiedst__T_flags2: return RDF_Type::Bitfield;
		case DF_Type::history_event_artifact_createdst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_createdst__T_flags2: return RDF_Type::Bitfield;
		case DF_Type::history_event_artifact_destroyedst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_droppedst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_foundst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_givenst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_hiddenst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_lostst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_possessedst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_recoveredst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_storedst: return RDF_Type::Class;
		case DF_Type::history_event_artifact_transformedst: return RDF_Type::Class;
		case DF_Type::history_event_assume_identityst: return RDF_Type::Class;
		case DF_Type::history_event_body_abusedst: return RDF_Type::Class;
		case DF_Type::history_event_body_abusedst__T_abuse_data: return RDF_Type::Union;
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Animated: return RDF_Type::Compound;
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Flayed: return RDF_Type::Compound;
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Hung: return RDF_Type::Compound;
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Impaled: return RDF_Type::Compound;
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled: return RDF_Type::Compound;
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type: return RDF_Type::Enum;
		case DF_Type::history_event_body_abusedst__T_abuse_type: return RDF_Type::Enum;
		case DF_Type::history_event_building_profile_acquiredst: return RDF_Type::Class;
		case DF_Type::history_event_ceremonyst: return RDF_Type::Class;
		case DF_Type::history_event_change_creature_typest: return RDF_Type::Class;
		case DF_Type::history_event_change_hf_body_statest: return RDF_Type::Class;
		case DF_Type::history_event_change_hf_jobst: return RDF_Type::Class;
		case DF_Type::history_event_change_hf_moodst: return RDF_Type::Class;
		case DF_Type::history_event_change_hf_statest: return RDF_Type::Class;
		case DF_Type::history_event_change_hf_statest__T_state: return RDF_Type::Enum;
		case DF_Type::history_event_circumstance_info: return RDF_Type::Struct;
		case DF_Type::history_event_circumstance_info__T_data: return RDF_Type::Union;
		case DF_Type::history_event_collection: return RDF_Type::Class;
		case DF_Type::history_event_collection_abductionst: return RDF_Type::Class;
		case DF_Type::history_event_collection_battlest: return RDF_Type::Class;
		case DF_Type::history_event_collection_battlest__T_attacker_merc_type: return RDF_Type::Enum;
		case DF_Type::history_event_collection_beast_attackst: return RDF_Type::Class;
		case DF_Type::history_event_collection_ceremonyst: return RDF_Type::Class;
		case DF_Type::history_event_collection_competitionst: return RDF_Type::Class;
		case DF_Type::history_event_collection_duelst: return RDF_Type::Class;
		case DF_Type::history_event_collection_entity_overthrownst: return RDF_Type::Class;
		case DF_Type::history_event_collection_insurrectionst: return RDF_Type::Class;
		case DF_Type::history_event_collection_journeyst: return RDF_Type::Class;
		case DF_Type::history_event_collection_occasionst: return RDF_Type::Class;
		case DF_Type::history_event_collection_performancest: return RDF_Type::Class;
		case DF_Type::history_event_collection_persecutionst: return RDF_Type::Class;
		case DF_Type::history_event_collection_processionst: return RDF_Type::Class;
		case DF_Type::history_event_collection_purgest: return RDF_Type::Class;
		case DF_Type::history_event_collection_raidst: return RDF_Type::Class;
		case DF_Type::history_event_collection_site_conqueredst: return RDF_Type::Class;
		case DF_Type::history_event_collection_theftst: return RDF_Type::Class;
		case DF_Type::history_event_collection_type: return RDF_Type::Enum;
		case DF_Type::history_event_collection_warst: return RDF_Type::Class;
		case DF_Type::history_event_collection_warst__T_unk: return RDF_Type::Compound;
		case DF_Type::history_event_competitionst: return RDF_Type::Class;
		case DF_Type::history_event_context: return RDF_Type::Struct;
		case DF_Type::history_event_context__T_unk_10: return RDF_Type::Compound;
		case DF_Type::history_event_create_entity_positionst: return RDF_Type::Class;
		case DF_Type::history_event_created_buildingst: return RDF_Type::Class;
		case DF_Type::history_event_created_sitest: return RDF_Type::Class;
		case DF_Type::history_event_created_world_constructionst: return RDF_Type::Class;
		case DF_Type::history_event_creature_devouredst: return RDF_Type::Class;
		case DF_Type::history_event_dance_form_createdst: return RDF_Type::Class;
		case DF_Type::history_event_diplomat_lostst: return RDF_Type::Class;
		case DF_Type::history_event_entity_actionst: return RDF_Type::Class;
		case DF_Type::history_event_entity_alliance_formedst: return RDF_Type::Class;
		case DF_Type::history_event_entity_breach_feature_layerst: return RDF_Type::Class;
		case DF_Type::history_event_entity_createdst: return RDF_Type::Class;
		case DF_Type::history_event_entity_dissolvedst: return RDF_Type::Class;
		case DF_Type::history_event_entity_equipment_purchasest: return RDF_Type::Class;
		case DF_Type::history_event_entity_expels_hfst: return RDF_Type::Class;
		case DF_Type::history_event_entity_fled_sitest: return RDF_Type::Class;
		case DF_Type::history_event_entity_incorporatedst: return RDF_Type::Class;
		case DF_Type::history_event_entity_lawst: return RDF_Type::Class;
		case DF_Type::history_event_entity_lawst__T_add_flags: return RDF_Type::Bitfield;
		case DF_Type::history_event_entity_lawst__T_remove_flags: return RDF_Type::Bitfield;
		case DF_Type::history_event_entity_overthrownst: return RDF_Type::Class;
		case DF_Type::history_event_entity_persecutedst: return RDF_Type::Class;
		case DF_Type::history_event_entity_rampaged_in_sitest: return RDF_Type::Class;
		case DF_Type::history_event_entity_razed_buildingst: return RDF_Type::Class;
		case DF_Type::history_event_entity_searched_sitest: return RDF_Type::Class;
		case DF_Type::history_event_failed_frame_attemptst: return RDF_Type::Class;
		case DF_Type::history_event_failed_intrigue_corruptionst: return RDF_Type::Class;
		case DF_Type::history_event_first_contact_failedst: return RDF_Type::Class;
		case DF_Type::history_event_first_contactst: return RDF_Type::Class;
		case DF_Type::history_event_flags: return RDF_Type::Enum;
		case DF_Type::history_event_gamblest: return RDF_Type::Class;
		case DF_Type::history_event_hf_act_on_artifactst: return RDF_Type::Class;
		case DF_Type::history_event_hf_act_on_artifactst__T_action: return RDF_Type::Enum;
		case DF_Type::history_event_hf_act_on_buildingst: return RDF_Type::Class;
		case DF_Type::history_event_hf_act_on_buildingst__T_action: return RDF_Type::Enum;
		case DF_Type::history_event_hf_attacked_sitest: return RDF_Type::Class;
		case DF_Type::history_event_hf_confrontedst: return RDF_Type::Class;
		case DF_Type::history_event_hf_convictedst: return RDF_Type::Class;
		case DF_Type::history_event_hf_convictedst__T_plot_flags: return RDF_Type::Bitfield;
		case DF_Type::history_event_hf_convictedst__T_punishment_flags: return RDF_Type::Bitfield;
		case DF_Type::history_event_hf_destroyed_sitest: return RDF_Type::Class;
		case DF_Type::history_event_hf_does_interactionst: return RDF_Type::Class;
		case DF_Type::history_event_hf_enslavedst: return RDF_Type::Class;
		case DF_Type::history_event_hf_freedst: return RDF_Type::Class;
		case DF_Type::history_event_hf_gains_secret_goalst: return RDF_Type::Class;
		case DF_Type::history_event_hf_interrogatedst: return RDF_Type::Class;
		case DF_Type::history_event_hf_interrogatedst__T_interrogation_flags: return RDF_Type::Bitfield;
		case DF_Type::history_event_hf_learns_secretst: return RDF_Type::Class;
		case DF_Type::history_event_hf_preachst: return RDF_Type::Class;
		case DF_Type::history_event_hf_ransomedst: return RDF_Type::Class;
		case DF_Type::history_event_hf_razed_buildingst: return RDF_Type::Class;
		case DF_Type::history_event_hf_recruited_unit_type_for_entityst: return RDF_Type::Class;
		case DF_Type::history_event_hf_relationship_deniedst: return RDF_Type::Class;
		case DF_Type::history_event_hfs_formed_intrigue_relationshipst: return RDF_Type::Class;
		case DF_Type::history_event_hfs_formed_reputation_relationshipst: return RDF_Type::Class;
		case DF_Type::history_event_hist_figure_abductedst: return RDF_Type::Class;
		case DF_Type::history_event_hist_figure_diedst: return RDF_Type::Class;
		case DF_Type::history_event_hist_figure_new_petst: return RDF_Type::Class;
		case DF_Type::history_event_hist_figure_reach_summitst: return RDF_Type::Class;
		case DF_Type::history_event_hist_figure_reunionst: return RDF_Type::Class;
		case DF_Type::history_event_hist_figure_revivedst: return RDF_Type::Class;
		case DF_Type::history_event_hist_figure_revivedst__T_flags2: return RDF_Type::Bitfield;
		case DF_Type::history_event_hist_figure_simple_actionst: return RDF_Type::Class;
		case DF_Type::history_event_hist_figure_simple_battle_eventst: return RDF_Type::Class;
		case DF_Type::history_event_hist_figure_travelst: return RDF_Type::Class;
		case DF_Type::history_event_hist_figure_travelst__T_reason: return RDF_Type::Enum;
		case DF_Type::history_event_hist_figure_woundedst: return RDF_Type::Class;
		case DF_Type::history_event_hist_figure_woundedst__T_flags2: return RDF_Type::Bitfield;
		case DF_Type::history_event_hist_figure_woundedst__T_injury_type: return RDF_Type::Enum;
		case DF_Type::history_event_insurrection_endedst: return RDF_Type::Class;
		case DF_Type::history_event_insurrection_startedst: return RDF_Type::Class;
		case DF_Type::history_event_item_stolenst: return RDF_Type::Class;
		case DF_Type::history_event_knowledge_discoveredst: return RDF_Type::Class;
		case DF_Type::history_event_masterpiece_created_arch_constructst: return RDF_Type::Class;
		case DF_Type::history_event_masterpiece_created_arch_designst: return RDF_Type::Class;
		case DF_Type::history_event_masterpiece_created_dye_itemst: return RDF_Type::Class;
		case DF_Type::history_event_masterpiece_created_engravingst: return RDF_Type::Class;
		case DF_Type::history_event_masterpiece_created_foodst: return RDF_Type::Class;
		case DF_Type::history_event_masterpiece_created_item_improvementst: return RDF_Type::Class;
		case DF_Type::history_event_masterpiece_created_itemst: return RDF_Type::Class;
		case DF_Type::history_event_masterpiece_createdst: return RDF_Type::Class;
		case DF_Type::history_event_masterpiece_lostst: return RDF_Type::Class;
		case DF_Type::history_event_merchantst: return RDF_Type::Class;
		case DF_Type::history_event_modified_buildingst: return RDF_Type::Class;
		case DF_Type::history_event_modified_buildingst__T_modification: return RDF_Type::Bitfield;
		case DF_Type::history_event_musical_form_createdst: return RDF_Type::Class;
		case DF_Type::history_event_performancest: return RDF_Type::Class;
		case DF_Type::history_event_poetic_form_createdst: return RDF_Type::Class;
		case DF_Type::history_event_processionst: return RDF_Type::Class;
		case DF_Type::history_event_reason: return RDF_Type::Enum;
		case DF_Type::history_event_reason_info: return RDF_Type::Struct;
		case DF_Type::history_event_reason_info__T_data: return RDF_Type::Union;
		case DF_Type::history_event_reclaim_sitest: return RDF_Type::Class;
		case DF_Type::history_event_reclaim_sitest__T_flags2: return RDF_Type::Bitfield;
		case DF_Type::history_event_regionpop_incorporated_into_entityst: return RDF_Type::Class;
		case DF_Type::history_event_remove_hf_entity_linkst: return RDF_Type::Class;
		case DF_Type::history_event_remove_hf_hf_linkst: return RDF_Type::Class;
		case DF_Type::history_event_remove_hf_site_linkst: return RDF_Type::Class;
		case DF_Type::history_event_replaced_buildingst: return RDF_Type::Class;
		case DF_Type::history_event_sabotagest: return RDF_Type::Class;
		case DF_Type::history_event_simple_battle_subtype: return RDF_Type::Enum;
		case DF_Type::history_event_site_diedst: return RDF_Type::Class;
		case DF_Type::history_event_site_diedst__T_flags2: return RDF_Type::Bitfield;
		case DF_Type::history_event_site_disputest: return RDF_Type::Class;
		case DF_Type::history_event_site_retiredst: return RDF_Type::Class;
		case DF_Type::history_event_site_retiredst__T_flags2: return RDF_Type::Bitfield;
		case DF_Type::history_event_site_surrenderedst: return RDF_Type::Class;
		case DF_Type::history_event_sneak_into_sitest: return RDF_Type::Class;
		case DF_Type::history_event_spotted_leaving_sitest: return RDF_Type::Class;
		case DF_Type::history_event_squad_vs_squadst: return RDF_Type::Class;
		case DF_Type::history_event_tactical_situationst: return RDF_Type::Class;
		case DF_Type::history_event_tactical_situationst__T_tactics_flags: return RDF_Type::Bitfield;
		case DF_Type::history_event_topicagreement_concludedst: return RDF_Type::Class;
		case DF_Type::history_event_topicagreement_madest: return RDF_Type::Class;
		case DF_Type::history_event_topicagreement_rejectedst: return RDF_Type::Class;
		case DF_Type::history_event_tradest: return RDF_Type::Class;
		case DF_Type::history_event_type: return RDF_Type::Enum;
		case DF_Type::history_event_war_attacked_sitest: return RDF_Type::Class;
		case DF_Type::history_event_war_attacked_sitest__T_unk_1: return RDF_Type::Enum;
		case DF_Type::history_event_war_destroyed_sitest: return RDF_Type::Class;
		case DF_Type::history_event_war_field_battlest: return RDF_Type::Class;
		case DF_Type::history_event_war_peace_acceptedst: return RDF_Type::Class;
		case DF_Type::history_event_war_peace_rejectedst: return RDF_Type::Class;
		case DF_Type::history_event_war_plundered_sitest: return RDF_Type::Class;
		case DF_Type::history_event_war_site_new_leaderst: return RDF_Type::Class;
		case DF_Type::history_event_war_site_taken_overst: return RDF_Type::Class;
		case DF_Type::history_event_war_site_tribute_forcedst: return RDF_Type::Class;
		case DF_Type::history_event_war_site_tribute_forcedst__T_tribute_flags: return RDF_Type::Bitfield;
		case DF_Type::history_event_written_content_composedst: return RDF_Type::Class;
		case DF_Type::history_hit_item: return RDF_Type::Struct;
		case DF_Type::hive_flags: return RDF_Type::Bitfield;
		case DF_Type::honors_type: return RDF_Type::Struct;
		case DF_Type::honors_type__T_flags: return RDF_Type::Bitfield;
		case DF_Type::honors_type__T_required_skill_type: return RDF_Type::Bitfield;
		case DF_Type::hospital_supplies: return RDF_Type::Struct;
		case DF_Type::hospital_supplies__T_supplies_needed: return RDF_Type::Bitfield;
		case DF_Type::identity: return RDF_Type::Struct;
		case DF_Type::identity___union1: return RDF_Type::Union;
		case DF_Type::identity_type: return RDF_Type::Enum;
		case DF_Type::identity_unk_94: return RDF_Type::Struct;
		case DF_Type::image_set: return RDF_Type::Struct;
		case DF_Type::image_set__T_unk_vec1: return RDF_Type::Compound;
		case DF_Type::improvement_type: return RDF_Type::Enum;
		case DF_Type::incident: return RDF_Type::Struct;
		case DF_Type::incident__T_data: return RDF_Type::Union;
		case DF_Type::incident__T_flags: return RDF_Type::Bitfield;
		case DF_Type::incident__T_type: return RDF_Type::Enum;
		case DF_Type::incident_hfid: return RDF_Type::Struct;
		case DF_Type::incident_sub10: return RDF_Type::Struct;
		case DF_Type::incident_sub6_performance: return RDF_Type::Struct;
		case DF_Type::incident_sub6_performance__T_participants: return RDF_Type::Compound;
		case DF_Type::incident_sub7: return RDF_Type::Struct;
		case DF_Type::incident_sub8: return RDF_Type::Struct;
		case DF_Type::incident_sub9: return RDF_Type::Struct;
		case DF_Type::inclusion_type: return RDF_Type::Enum;
		case DF_Type::init: return RDF_Type::Struct;
		case DF_Type::init_display: return RDF_Type::Struct;
		case DF_Type::init_display__T_windowed: return RDF_Type::Enum;
		case DF_Type::init_display_flags: return RDF_Type::Enum;
		case DF_Type::init_font: return RDF_Type::Struct;
		case DF_Type::init_font__T_use_ttf: return RDF_Type::Enum;
		case DF_Type::init_input: return RDF_Type::Struct;
		case DF_Type::init_input_flags: return RDF_Type::Enum;
		case DF_Type::init_media: return RDF_Type::Struct;
		case DF_Type::init_media_flags: return RDF_Type::Enum;
		case DF_Type::init_window: return RDF_Type::Struct;
		case DF_Type::init_window_flags: return RDF_Type::Enum;
		case DF_Type::inorganic_flags: return RDF_Type::Enum;
		case DF_Type::inorganic_raw: return RDF_Type::Struct;
		case DF_Type::inorganic_raw__T_environment: return RDF_Type::Compound;
		case DF_Type::inorganic_raw__T_environment_spec: return RDF_Type::Compound;
		case DF_Type::inorganic_raw__T_metal_ore: return RDF_Type::Compound;
		case DF_Type::inorganic_raw__T_thread_metal: return RDF_Type::Compound;
		case DF_Type::instrument_flags: return RDF_Type::Enum;
		case DF_Type::instrument_piece: return RDF_Type::Struct;
		case DF_Type::instrument_piece__T_flags: return RDF_Type::Bitfield;
		case DF_Type::instrument_register: return RDF_Type::Struct;
		case DF_Type::insurrection_outcome: return RDF_Type::Enum;
		case DF_Type::int16_t: return RDF_Type::DFArray;
		case DF_Type::interaction: return RDF_Type::Struct;
		case DF_Type::interaction_effect: return RDF_Type::Class;
		case DF_Type::interaction_effect__T_flags: return RDF_Type::Bitfield;
		case DF_Type::interaction_effect_add_syndromest: return RDF_Type::Class;
		case DF_Type::interaction_effect_animatest: return RDF_Type::Class;
		case DF_Type::interaction_effect_change_item_qualityst: return RDF_Type::Class;
		case DF_Type::interaction_effect_change_weatherst: return RDF_Type::Class;
		case DF_Type::interaction_effect_cleanst: return RDF_Type::Class;
		case DF_Type::interaction_effect_contactst: return RDF_Type::Class;
		case DF_Type::interaction_effect_create_itemst: return RDF_Type::Class;
		case DF_Type::interaction_effect_hidest: return RDF_Type::Class;
		case DF_Type::interaction_effect_location_hint: return RDF_Type::Enum;
		case DF_Type::interaction_effect_material_emissionst: return RDF_Type::Class;
		case DF_Type::interaction_effect_propel_unitst: return RDF_Type::Class;
		case DF_Type::interaction_effect_resurrectst: return RDF_Type::Class;
		case DF_Type::interaction_effect_summon_unitst: return RDF_Type::Class;
		case DF_Type::interaction_effect_type: return RDF_Type::Enum;
		case DF_Type::interaction_flags: return RDF_Type::Enum;
		case DF_Type::interaction_instance: return RDF_Type::Struct;
		case DF_Type::interaction_source: return RDF_Type::Class;
		case DF_Type::interaction_source_attackst: return RDF_Type::Class;
		case DF_Type::interaction_source_creature_actionst: return RDF_Type::Class;
		case DF_Type::interaction_source_deityst: return RDF_Type::Class;
		case DF_Type::interaction_source_disturbancest: return RDF_Type::Class;
		case DF_Type::interaction_source_experimentst: return RDF_Type::Class;
		case DF_Type::interaction_source_ingestionst: return RDF_Type::Class;
		case DF_Type::interaction_source_regionst: return RDF_Type::Class;
		case DF_Type::interaction_source_regionst__T_region_flags: return RDF_Type::Bitfield;
		case DF_Type::interaction_source_secretst: return RDF_Type::Class;
		case DF_Type::interaction_source_secretst__T_learn_flags: return RDF_Type::Bitfield;
		case DF_Type::interaction_source_type: return RDF_Type::Enum;
		case DF_Type::interaction_source_underground_specialst: return RDF_Type::Class;
		case DF_Type::interaction_source_usage_hint: return RDF_Type::Enum;
		case DF_Type::interaction_target: return RDF_Type::Class;
		case DF_Type::interaction_target_corpsest: return RDF_Type::Class;
		case DF_Type::interaction_target_creaturest: return RDF_Type::Class;
		case DF_Type::interaction_target_info: return RDF_Type::Struct;
		case DF_Type::interaction_target_info__T_restrictions: return RDF_Type::Bitfield;
		case DF_Type::interaction_target_location_type: return RDF_Type::Enum;
		case DF_Type::interaction_target_locationst: return RDF_Type::Class;
		case DF_Type::interaction_target_materialst: return RDF_Type::Class;
		case DF_Type::interaction_target_materialst__T_restrictions: return RDF_Type::Bitfield;
		case DF_Type::interaction_target_type: return RDF_Type::Enum;
		case DF_Type::interface_breakdown_types: return RDF_Type::Enum;
		case DF_Type::interface_button: return RDF_Type::Class;
		case DF_Type::interface_button_building_category_selectorst: return RDF_Type::Class;
		case DF_Type::interface_button_building_custom_category_selectorst: return RDF_Type::Class;
		case DF_Type::interface_button_building_material_selectorst: return RDF_Type::Class;
		case DF_Type::interface_button_building_new_jobst: return RDF_Type::Class;
		case DF_Type::interface_button_buildingst: return RDF_Type::Class;
		case DF_Type::interface_button_construction_building_selectorst: return RDF_Type::Class;
		case DF_Type::interface_button_construction_category_selectorst: return RDF_Type::Class;
		case DF_Type::interface_button_construction_category_selectorst__T_category_id: return RDF_Type::Enum;
		case DF_Type::interface_button_construction_donest: return RDF_Type::Class;
		case DF_Type::interface_button_constructionst: return RDF_Type::Class;
		case DF_Type::interface_key: return RDF_Type::Enum;
		case DF_Type::interfacest: return RDF_Type::Struct;
		case DF_Type::interrogation_report: return RDF_Type::Struct;
		case DF_Type::invasion_info: return RDF_Type::Struct;
		case DF_Type::invasion_info__T_flags: return RDF_Type::Bitfield;
		case DF_Type::item: return RDF_Type::Class;
		case DF_Type::item_actual: return RDF_Type::Class;
		case DF_Type::item_ammost: return RDF_Type::Class;
		case DF_Type::item_amuletst: return RDF_Type::Class;
		case DF_Type::item_animaltrapst: return RDF_Type::Class;
		case DF_Type::item_anvilst: return RDF_Type::Class;
		case DF_Type::item_armorst: return RDF_Type::Class;
		case DF_Type::item_armorstandst: return RDF_Type::Class;
		case DF_Type::item_backpackst: return RDF_Type::Class;
		case DF_Type::item_ballistaarrowheadst: return RDF_Type::Class;
		case DF_Type::item_ballistapartsst: return RDF_Type::Class;
		case DF_Type::item_barrelst: return RDF_Type::Class;
		case DF_Type::item_barst: return RDF_Type::Class;
		case DF_Type::item_bedst: return RDF_Type::Class;
		case DF_Type::item_binst: return RDF_Type::Class;
		case DF_Type::item_blocksst: return RDF_Type::Class;
		case DF_Type::item_body_component: return RDF_Type::Class;
		case DF_Type::item_body_component__T_appearance: return RDF_Type::Compound;
		case DF_Type::item_body_component__T_body: return RDF_Type::Compound;
		case DF_Type::item_body_component__T_bone1: return RDF_Type::Compound;
		case DF_Type::item_body_component__T_bone2: return RDF_Type::Compound;
		case DF_Type::item_body_component__T_corpse_flags: return RDF_Type::Bitfield;
		case DF_Type::item_bookst: return RDF_Type::Class;
		case DF_Type::item_boulderst: return RDF_Type::Class;
		case DF_Type::item_boxst: return RDF_Type::Class;
		case DF_Type::item_braceletst: return RDF_Type::Class;
		case DF_Type::item_branchst: return RDF_Type::Class;
		case DF_Type::item_bucketst: return RDF_Type::Class;
		case DF_Type::item_cabinetst: return RDF_Type::Class;
		case DF_Type::item_cagest: return RDF_Type::Class;
		case DF_Type::item_catapultpartsst: return RDF_Type::Class;
		case DF_Type::item_chainst: return RDF_Type::Class;
		case DF_Type::item_chairst: return RDF_Type::Class;
		case DF_Type::item_cheesest: return RDF_Type::Class;
		case DF_Type::item_clothst: return RDF_Type::Class;
		case DF_Type::item_coffinst: return RDF_Type::Class;
		case DF_Type::item_coinst: return RDF_Type::Class;
		case DF_Type::item_constructed: return RDF_Type::Class;
		case DF_Type::item_corpsepiecest: return RDF_Type::Class;
		case DF_Type::item_corpsest: return RDF_Type::Class;
		case DF_Type::item_crafted: return RDF_Type::Class;
		case DF_Type::item_critter: return RDF_Type::Class;
		case DF_Type::item_crownst: return RDF_Type::Class;
		case DF_Type::item_crutchst: return RDF_Type::Class;
		case DF_Type::item_doorst: return RDF_Type::Class;
		case DF_Type::item_drinkst: return RDF_Type::Class;
		case DF_Type::item_earringst: return RDF_Type::Class;
		case DF_Type::item_eggst: return RDF_Type::Class;
		case DF_Type::item_eggst__T_egg_flags: return RDF_Type::Bitfield;
		case DF_Type::item_figurinest: return RDF_Type::Class;
		case DF_Type::item_filter_spec: return RDF_Type::Struct;
		case DF_Type::item_fish_rawst: return RDF_Type::Class;
		case DF_Type::item_fishst: return RDF_Type::Class;
		case DF_Type::item_flags2: return RDF_Type::Bitfield;
		case DF_Type::item_flags: return RDF_Type::Bitfield;
		case DF_Type::item_flaskst: return RDF_Type::Class;
		case DF_Type::item_floodgatest: return RDF_Type::Class;
		case DF_Type::item_foodst: return RDF_Type::Class;
		case DF_Type::item_foodst__T_ingredients: return RDF_Type::Compound;
		case DF_Type::item_gemst: return RDF_Type::Class;
		case DF_Type::item_globst: return RDF_Type::Class;
		case DF_Type::item_glovesst: return RDF_Type::Class;
		case DF_Type::item_gobletst: return RDF_Type::Class;
		case DF_Type::item_gratest: return RDF_Type::Class;
		case DF_Type::item_hatch_coverst: return RDF_Type::Class;
		case DF_Type::item_helmst: return RDF_Type::Class;
		case DF_Type::item_history_info: return RDF_Type::Struct;
		case DF_Type::item_instrumentst: return RDF_Type::Class;
		case DF_Type::item_kill_info: return RDF_Type::Struct;
		case DF_Type::item_liquid: return RDF_Type::Class;
		case DF_Type::item_liquid_miscst: return RDF_Type::Class;
		case DF_Type::item_liquipowder: return RDF_Type::Class;
		case DF_Type::item_magicness: return RDF_Type::Struct;
		case DF_Type::item_magicness_type: return RDF_Type::Enum;
		case DF_Type::item_matstate: return RDF_Type::Bitfield;
		case DF_Type::item_meatst: return RDF_Type::Class;
		case DF_Type::item_millstonest: return RDF_Type::Class;
		case DF_Type::item_orthopedic_castst: return RDF_Type::Class;
		case DF_Type::item_pantsst: return RDF_Type::Class;
		case DF_Type::item_petst: return RDF_Type::Class;
		case DF_Type::item_petst__T_pet_flags: return RDF_Type::Bitfield;
		case DF_Type::item_pipe_sectionst: return RDF_Type::Class;
		case DF_Type::item_plant_growthst: return RDF_Type::Class;
		case DF_Type::item_plantst: return RDF_Type::Class;
		case DF_Type::item_powder: return RDF_Type::Class;
		case DF_Type::item_powder_miscst: return RDF_Type::Class;
		case DF_Type::item_quality: return RDF_Type::Enum;
		case DF_Type::item_quernst: return RDF_Type::Class;
		case DF_Type::item_quiverst: return RDF_Type::Class;
		case DF_Type::item_remainsst: return RDF_Type::Class;
		case DF_Type::item_ringst: return RDF_Type::Class;
		case DF_Type::item_rockst: return RDF_Type::Class;
		case DF_Type::item_roughst: return RDF_Type::Class;
		case DF_Type::item_scepterst: return RDF_Type::Class;
		case DF_Type::item_seedsst: return RDF_Type::Class;
		case DF_Type::item_sheetst: return RDF_Type::Class;
		case DF_Type::item_shieldst: return RDF_Type::Class;
		case DF_Type::item_shoesst: return RDF_Type::Class;
		case DF_Type::item_siegeammost: return RDF_Type::Class;
		case DF_Type::item_skin_tannedst: return RDF_Type::Class;
		case DF_Type::item_slabst: return RDF_Type::Class;
		case DF_Type::item_smallgemst: return RDF_Type::Class;
		case DF_Type::item_splintst: return RDF_Type::Class;
		case DF_Type::item_statuest: return RDF_Type::Class;
		case DF_Type::item_stockpile_ref: return RDF_Type::Struct;
		case DF_Type::item_tablest: return RDF_Type::Class;
		case DF_Type::item_threadst: return RDF_Type::Class;
		case DF_Type::item_toolst: return RDF_Type::Class;
		case DF_Type::item_totemst: return RDF_Type::Class;
		case DF_Type::item_toyst: return RDF_Type::Class;
		case DF_Type::item_traction_benchst: return RDF_Type::Class;
		case DF_Type::item_trapcompst: return RDF_Type::Class;
		case DF_Type::item_trappartsst: return RDF_Type::Class;
		case DF_Type::item_type: return RDF_Type::Enum;
		case DF_Type::item_verminst: return RDF_Type::Class;
		case DF_Type::item_weaponrackst: return RDF_Type::Class;
		case DF_Type::item_weaponst: return RDF_Type::Class;
		case DF_Type::item_windowst: return RDF_Type::Class;
		case DF_Type::item_woodst: return RDF_Type::Class;
		case DF_Type::itemdef: return RDF_Type::Class;
		case DF_Type::itemdef_ammost: return RDF_Type::Class;
		case DF_Type::itemdef_armorst: return RDF_Type::Class;
		case DF_Type::itemdef_flags: return RDF_Type::Enum;
		case DF_Type::itemdef_foodst: return RDF_Type::Class;
		case DF_Type::itemdef_glovesst: return RDF_Type::Class;
		case DF_Type::itemdef_helmst: return RDF_Type::Class;
		case DF_Type::itemdef_instrumentst: return RDF_Type::Class;
		case DF_Type::itemdef_pantsst: return RDF_Type::Class;
		case DF_Type::itemdef_shieldst: return RDF_Type::Class;
		case DF_Type::itemdef_shoesst: return RDF_Type::Class;
		case DF_Type::itemdef_siegeammost: return RDF_Type::Class;
		case DF_Type::itemdef_toolst: return RDF_Type::Class;
		case DF_Type::itemdef_toolst__T_default_improvements: return RDF_Type::Compound;
		case DF_Type::itemdef_toyst: return RDF_Type::Class;
		case DF_Type::itemdef_trapcompst: return RDF_Type::Class;
		case DF_Type::itemdef_weaponst: return RDF_Type::Class;
		case DF_Type::itemimprovement: return RDF_Type::Class;
		case DF_Type::itemimprovement_art_imagest: return RDF_Type::Class;
		case DF_Type::itemimprovement_bandsst: return RDF_Type::Class;
		case DF_Type::itemimprovement_clothst: return RDF_Type::Class;
		case DF_Type::itemimprovement_coveredst: return RDF_Type::Class;
		case DF_Type::itemimprovement_coveredst__T_cover_flags: return RDF_Type::Bitfield;
		case DF_Type::itemimprovement_illustrationst: return RDF_Type::Class;
		case DF_Type::itemimprovement_instrument_piecest: return RDF_Type::Class;
		case DF_Type::itemimprovement_itemspecificst: return RDF_Type::Class;
		case DF_Type::itemimprovement_pagesst: return RDF_Type::Class;
		case DF_Type::itemimprovement_rings_hangingst: return RDF_Type::Class;
		case DF_Type::itemimprovement_sewn_imagest: return RDF_Type::Class;
		case DF_Type::itemimprovement_sewn_imagest__T_cloth: return RDF_Type::Compound;
		case DF_Type::itemimprovement_specific_type: return RDF_Type::Enum;
		case DF_Type::itemimprovement_spikesst: return RDF_Type::Class;
		case DF_Type::itemimprovement_threadst: return RDF_Type::Class;
		case DF_Type::itemimprovement_writingst: return RDF_Type::Class;
		case DF_Type::items_other_id: return RDF_Type::Enum;
		case DF_Type::job: return RDF_Type::Struct;
		case DF_Type::job_art_specification: return RDF_Type::Struct;
		case DF_Type::job_art_specification__T_type: return RDF_Type::Enum;
		case DF_Type::job_flags: return RDF_Type::Bitfield;
		case DF_Type::job_handler: return RDF_Type::Class;
		case DF_Type::job_handler__T_anon_1: return RDF_Type::Compound;
		case DF_Type::job_handler__T_postings: return RDF_Type::Compound;
		case DF_Type::job_handler__T_postings__T_flags: return RDF_Type::Bitfield;
		case DF_Type::job_item: return RDF_Type::Struct;
		case DF_Type::job_item_filter: return RDF_Type::Struct;
		case DF_Type::job_item_flags1: return RDF_Type::Bitfield;
		case DF_Type::job_item_flags2: return RDF_Type::Bitfield;
		case DF_Type::job_item_flags3: return RDF_Type::Bitfield;
		case DF_Type::job_item_ref: return RDF_Type::Struct;
		case DF_Type::job_item_ref__T_role: return RDF_Type::Enum;
		case DF_Type::job_item_vector_id: return RDF_Type::Enum;
		case DF_Type::job_list_link: return RDF_Type::Struct;
		case DF_Type::job_material_category: return RDF_Type::Bitfield;
		case DF_Type::job_skill: return RDF_Type::Enum;
		case DF_Type::job_skill_class: return RDF_Type::Enum;
		case DF_Type::job_subtype_surgery: return RDF_Type::Enum;
		case DF_Type::job_type: return RDF_Type::Enum;
		case DF_Type::job_type_class: return RDF_Type::Enum;
		case DF_Type::justification: return RDF_Type::Enum;
		case DF_Type::kitchen_exc_type: return RDF_Type::Enum;
		case DF_Type::kitchen_pref_flag: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_category_flag: return RDF_Type::Struct;
		case DF_Type::knowledge_scholar_category_flag__T_flag_data: return RDF_Type::Union;
		case DF_Type::knowledge_scholar_category_flag__T_flag_type: return RDF_Type::Enum;
		case DF_Type::knowledge_scholar_flags_0: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_10: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_11: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_12: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_13: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_1: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_2: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_3: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_4: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_5: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_6: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_7: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_8: return RDF_Type::Bitfield;
		case DF_Type::knowledge_scholar_flags_9: return RDF_Type::Bitfield;
		case DF_Type::lair_type: return RDF_Type::Enum;
		case DF_Type::language_name: return RDF_Type::Struct;
		case DF_Type::language_name_category: return RDF_Type::Enum;
		case DF_Type::language_symbol: return RDF_Type::Struct;
		case DF_Type::language_translation: return RDF_Type::Struct;
		case DF_Type::language_word: return RDF_Type::Struct;
		case DF_Type::language_word_flags: return RDF_Type::Bitfield;
		case DF_Type::language_word_table: return RDF_Type::Struct;
		case DF_Type::large_integer: return RDF_Type::Union;
		case DF_Type::large_integer__T_u: return RDF_Type::Compound;
		case DF_Type::large_integer___struct0: return RDF_Type::Compound;
		case DF_Type::layer_object: return RDF_Type::Class;
		case DF_Type::layer_object_buttonst: return RDF_Type::Class;
		case DF_Type::layer_object_listst: return RDF_Type::Class;
		case DF_Type::layer_type: return RDF_Type::Enum;
		case DF_Type::lever_target_type: return RDF_Type::Enum;
		case DF_Type::loadgame_save_info: return RDF_Type::Struct;
		case DF_Type::local_population: return RDF_Type::Struct;
		case DF_Type::local_population__T_flags: return RDF_Type::Bitfield;
		case DF_Type::local_population___union4: return RDF_Type::Union;
		case DF_Type::location_scribe_jobs: return RDF_Type::Struct;
		case DF_Type::machine: return RDF_Type::Class;
		case DF_Type::machine__T_components: return RDF_Type::Compound;
		case DF_Type::machine__T_flags: return RDF_Type::Bitfield;
		case DF_Type::machine_conn_modes: return RDF_Type::Bitfield;
		case DF_Type::machine_handler: return RDF_Type::Class;
		case DF_Type::machine_info: return RDF_Type::Struct;
		case DF_Type::machine_info__T_flags: return RDF_Type::Bitfield;
		case DF_Type::machine_standardst: return RDF_Type::Class;
		case DF_Type::machine_tile_set: return RDF_Type::Struct;
		case DF_Type::machine_type: return RDF_Type::Enum;
		case DF_Type::manager_order: return RDF_Type::Struct;
		case DF_Type::manager_order__T_frequency: return RDF_Type::Enum;
		case DF_Type::manager_order_condition_item: return RDF_Type::Struct;
		case DF_Type::manager_order_condition_item__T_compare_type: return RDF_Type::Enum;
		case DF_Type::manager_order_condition_order: return RDF_Type::Struct;
		case DF_Type::manager_order_condition_order__T_condition: return RDF_Type::Enum;
		case DF_Type::manager_order_status: return RDF_Type::Bitfield;
		case DF_Type::manager_order_template: return RDF_Type::Struct;
		case DF_Type::mandate: return RDF_Type::Struct;
		case DF_Type::mandate__T_mode: return RDF_Type::Enum;
		case DF_Type::mandate__T_punishment: return RDF_Type::Compound;
		case DF_Type::map_block: return RDF_Type::Struct;
		case DF_Type::map_block_column: return RDF_Type::Struct;
		case DF_Type::map_block_column__T_unmined_glyphs: return RDF_Type::Compound;
		case DF_Type::map_renderer: return RDF_Type::Struct;
		case DF_Type::map_renderer__T_anon_4: return RDF_Type::Compound;
		case DF_Type::map_viewport: return RDF_Type::Struct;
		case DF_Type::masterpiece_loss_type: return RDF_Type::Enum;
		case DF_Type::material: return RDF_Type::Struct;
		case DF_Type::material_common: return RDF_Type::Struct;
		case DF_Type::material_common__T_hardens_with_water: return RDF_Type::Compound;
		case DF_Type::material_common__T_heat: return RDF_Type::Compound;
		case DF_Type::material_common__T_reaction_product: return RDF_Type::Compound;
		case DF_Type::material_common__T_strength: return RDF_Type::Compound;
		case DF_Type::material_flags: return RDF_Type::Enum;
		case DF_Type::material_template: return RDF_Type::Struct;
		case DF_Type::material_vec_ref: return RDF_Type::Struct;
		case DF_Type::matgloss_list: return RDF_Type::Struct;
		case DF_Type::matgloss_list__T_unk_0: return RDF_Type::Compound;
		case DF_Type::matter_state: return RDF_Type::Enum;
		case DF_Type::meeting_context: return RDF_Type::Struct;
		case DF_Type::meeting_diplomat_info: return RDF_Type::Struct;
		case DF_Type::meeting_diplomat_info__T_flags: return RDF_Type::Bitfield;
		case DF_Type::meeting_event: return RDF_Type::Struct;
		case DF_Type::meeting_event_type: return RDF_Type::Enum;
		case DF_Type::meeting_topic: return RDF_Type::Enum;
		case DF_Type::meeting_variable: return RDF_Type::Struct;
		case DF_Type::mental_attribute_type: return RDF_Type::Enum;
		case DF_Type::mental_picture: return RDF_Type::Struct;
		case DF_Type::mental_picture__T_unk: return RDF_Type::Compound;
		case DF_Type::mental_picture_element_hfst: return RDF_Type::Class;
		case DF_Type::mental_picture_element_regionst: return RDF_Type::Class;
		case DF_Type::mental_picture_element_sitest: return RDF_Type::Class;
		case DF_Type::mental_picture_element_type: return RDF_Type::Enum;
		case DF_Type::mental_picture_elementst: return RDF_Type::Class;
		case DF_Type::mental_picture_property_actionst: return RDF_Type::Class;
		case DF_Type::mental_picture_property_adjectivest: return RDF_Type::Class;
		case DF_Type::mental_picture_property_color_patternst: return RDF_Type::Class;
		case DF_Type::mental_picture_property_datest: return RDF_Type::Class;
		case DF_Type::mental_picture_property_emotionst: return RDF_Type::Class;
		case DF_Type::mental_picture_property_positionst: return RDF_Type::Class;
		case DF_Type::mental_picture_property_shapest: return RDF_Type::Class;
		case DF_Type::mental_picture_property_timest: return RDF_Type::Class;
		case DF_Type::mental_picture_property_toolst: return RDF_Type::Class;
		case DF_Type::mental_picture_property_type: return RDF_Type::Enum;
		case DF_Type::mental_picture_propertyst: return RDF_Type::Class;
		case DF_Type::misc_trait_type: return RDF_Type::Enum;
		case DF_Type::mission: return RDF_Type::Struct;
		case DF_Type::mission__T_details: return RDF_Type::Union;
		case DF_Type::mission__T_details__T_raid: return RDF_Type::Compound;
		case DF_Type::mission__T_details__T_raid__T_raid_flags: return RDF_Type::Bitfield;
		case DF_Type::mission__T_details__T_raid__T_raid_type: return RDF_Type::Enum;
		case DF_Type::mission__T_details__T_recovery: return RDF_Type::Compound;
		case DF_Type::mission__T_details__T_request: return RDF_Type::Compound;
		case DF_Type::mission__T_details__T_rescue: return RDF_Type::Compound;
		case DF_Type::mission__T_type: return RDF_Type::Enum;
		case DF_Type::mission_campaign_report: return RDF_Type::Struct;
		case DF_Type::mission_report: return RDF_Type::Struct;
		case DF_Type::monument_type: return RDF_Type::Enum;
		case DF_Type::mood_type: return RDF_Type::Enum;
		case DF_Type::mountain_peak_flags: return RDF_Type::Enum;
		case DF_Type::moving_party: return RDF_Type::Struct;
		case DF_Type::moving_party__T_members: return RDF_Type::Compound;
		case DF_Type::musical_form: return RDF_Type::Struct;
		case DF_Type::musical_form__T_flags: return RDF_Type::Bitfield;
		case DF_Type::musical_form_feature: return RDF_Type::Bitfield;
		case DF_Type::musical_form_instruments: return RDF_Type::Struct;
		case DF_Type::musical_form_instruments__T_substitutions: return RDF_Type::Bitfield;
		case DF_Type::musical_form_interval: return RDF_Type::Struct;
		case DF_Type::musical_form_interval__T_flags: return RDF_Type::Bitfield;
		case DF_Type::musical_form_melodies: return RDF_Type::Struct;
		case DF_Type::musical_form_pitch_style: return RDF_Type::Enum;
		case DF_Type::musical_form_purpose: return RDF_Type::Enum;
		case DF_Type::musical_form_style: return RDF_Type::Enum;
		case DF_Type::musical_form_sub4: return RDF_Type::Struct;
		case DF_Type::musical_form_vocals: return RDF_Type::Struct;
		case DF_Type::need_type: return RDF_Type::Enum;
		case DF_Type::nemesis_flags: return RDF_Type::Enum;
		case DF_Type::nemesis_offload: return RDF_Type::Struct;
		case DF_Type::nemesis_record: return RDF_Type::Struct;
		case DF_Type::next_global_id: return RDF_Type::Enum;
		case DF_Type::occasion_schedule_feature: return RDF_Type::Enum;
		case DF_Type::occasion_schedule_type: return RDF_Type::Enum;
		case DF_Type::occupation: return RDF_Type::Struct;
		case DF_Type::occupation_sub1: return RDF_Type::Struct;
		case DF_Type::occupation_type: return RDF_Type::Enum;
		case DF_Type::ocean_wave: return RDF_Type::Struct;
		case DF_Type::organic_mat_category: return RDF_Type::Enum;
		case DF_Type::orientation_flags: return RDF_Type::Bitfield;
		case DF_Type::pants_flags: return RDF_Type::Enum;
		case DF_Type::part_of_speech: return RDF_Type::Enum;
		case DF_Type::party_info: return RDF_Type::Struct;
		case DF_Type::pattern_type: return RDF_Type::Enum;
		case DF_Type::performance_event_type: return RDF_Type::Enum;
		case DF_Type::performance_participant_type: return RDF_Type::Enum;
		case DF_Type::performance_play_orderst: return RDF_Type::Class;
		case DF_Type::performance_play_orderst__T_anon_4: return RDF_Type::Compound;
		case DF_Type::personality_facet_type: return RDF_Type::Enum;
		case DF_Type::physical_attribute_type: return RDF_Type::Enum;
		case DF_Type::pitch_choice_type: return RDF_Type::Enum;
		case DF_Type::plant: return RDF_Type::Struct;
		case DF_Type::plant__T_damage_flags: return RDF_Type::Bitfield;
		case DF_Type::plant_flags: return RDF_Type::Bitfield;
		case DF_Type::plant_growth: return RDF_Type::Struct;
		case DF_Type::plant_growth__T_behavior: return RDF_Type::Bitfield;
		case DF_Type::plant_growth__T_locations: return RDF_Type::Bitfield;
		case DF_Type::plant_growth_print: return RDF_Type::Struct;
		case DF_Type::plant_raw: return RDF_Type::Struct;
		case DF_Type::plant_raw__T_colors: return RDF_Type::Compound;
		case DF_Type::plant_raw__T_material_defs: return RDF_Type::Compound;
		case DF_Type::plant_raw__T_tiles: return RDF_Type::Compound;
		case DF_Type::plant_raw_flags: return RDF_Type::Enum;
		case DF_Type::plant_tree_info: return RDF_Type::Struct;
		case DF_Type::plant_tree_tile: return RDF_Type::Bitfield;
		case DF_Type::plot_agreement: return RDF_Type::Struct;
		case DF_Type::plot_role_type: return RDF_Type::Enum;
		case DF_Type::plot_strategy_type: return RDF_Type::Enum;
		case DF_Type::poetic_form: return RDF_Type::Struct;
		case DF_Type::poetic_form__T_flags: return RDF_Type::Bitfield;
		case DF_Type::poetic_form_action: return RDF_Type::Enum;
		case DF_Type::poetic_form_additional_feature: return RDF_Type::Enum;
		case DF_Type::poetic_form_caesura_position: return RDF_Type::Enum;
		case DF_Type::poetic_form_feature: return RDF_Type::Bitfield;
		case DF_Type::poetic_form_mood: return RDF_Type::Enum;
		case DF_Type::poetic_form_part: return RDF_Type::Struct;
		case DF_Type::poetic_form_part__T_flags: return RDF_Type::Bitfield;
		case DF_Type::poetic_form_pattern: return RDF_Type::Enum;
		case DF_Type::poetic_form_perspective: return RDF_Type::Struct;
		case DF_Type::poetic_form_perspective__T_type: return RDF_Type::Enum;
		case DF_Type::poetic_form_subject: return RDF_Type::Enum;
		case DF_Type::poetic_form_subject_target: return RDF_Type::Union;
		case DF_Type::poetic_form_subject_target__T_Concept: return RDF_Type::Compound;
		case DF_Type::poetic_form_subject_target__T_Histfig: return RDF_Type::Compound;
		case DF_Type::popup_message: return RDF_Type::Struct;
		case DF_Type::power_info: return RDF_Type::Struct;
		case DF_Type::pressure_plate_info: return RDF_Type::Struct;
		case DF_Type::pressure_plate_info__T_flags: return RDF_Type::Bitfield;
		case DF_Type::profession: return RDF_Type::Enum;
		case DF_Type::proj_itemst: return RDF_Type::Class;
		case DF_Type::proj_list_link: return RDF_Type::Struct;
		case DF_Type::proj_magicst: return RDF_Type::Class;
		case DF_Type::proj_unitst: return RDF_Type::Class;
		case DF_Type::projectile: return RDF_Type::Class;
		case DF_Type::projectile_flags: return RDF_Type::Bitfield;
		case DF_Type::projectile_type: return RDF_Type::Enum;
		case DF_Type::property_ownership: return RDF_Type::Struct;
		case DF_Type::punishment: return RDF_Type::Struct;
		case DF_Type::reaction: return RDF_Type::Struct;
		case DF_Type::reaction__T_building: return RDF_Type::Compound;
		case DF_Type::reaction_category: return RDF_Type::Struct;
		case DF_Type::reaction_description: return RDF_Type::Struct;
		case DF_Type::reaction_flags: return RDF_Type::Enum;
		case DF_Type::reaction_product: return RDF_Type::Class;
		case DF_Type::reaction_product_improvement_flags: return RDF_Type::Enum;
		case DF_Type::reaction_product_item_flags: return RDF_Type::Enum;
		case DF_Type::reaction_product_item_improvementst: return RDF_Type::Class;
		case DF_Type::reaction_product_item_improvementst__T_get_material: return RDF_Type::Compound;
		case DF_Type::reaction_product_itemst: return RDF_Type::Class;
		case DF_Type::reaction_product_itemst__T_get_material: return RDF_Type::Compound;
		case DF_Type::reaction_product_type: return RDF_Type::Enum;
		case DF_Type::reaction_reagent: return RDF_Type::Class;
		case DF_Type::reaction_reagent_flags: return RDF_Type::Bitfield;
		case DF_Type::reaction_reagent_itemst: return RDF_Type::Class;
		case DF_Type::reaction_reagent_type: return RDF_Type::Enum;
		case DF_Type::region_block_event_sphere_fieldst: return RDF_Type::Class;
		case DF_Type::region_block_event_type: return RDF_Type::Enum;
		case DF_Type::region_block_eventst: return RDF_Type::Class;
		case DF_Type::region_map_entry: return RDF_Type::Struct;
		case DF_Type::region_map_entry__T_clouds: return RDF_Type::Bitfield;
		case DF_Type::region_map_entry__T_wind: return RDF_Type::Bitfield;
		case DF_Type::region_map_entry_flags: return RDF_Type::Enum;
		case DF_Type::region_weather: return RDF_Type::Struct;
		case DF_Type::relationship_event: return RDF_Type::Struct;
		case DF_Type::relationship_event_supplement: return RDF_Type::Struct;
		case DF_Type::renderer: return RDF_Type::Class;
		case DF_Type::report: return RDF_Type::Struct;
		case DF_Type::report__T_flags: return RDF_Type::Bitfield;
		case DF_Type::reputation_type: return RDF_Type::Enum;
		case DF_Type::resource_allotment_data: return RDF_Type::Struct;
		case DF_Type::resource_allotment_data__T_unk_654: return RDF_Type::Compound;
		case DF_Type::resource_allotment_specifier: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_ammost: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_anvilst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_armor_bodyst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_armor_bootsst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_armor_glovesst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_armor_helmst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_armor_pantsst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_backpackst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_bagst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_bedst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_bonest: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_boxst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_cabinetst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_chairst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_cheesest: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_clothing_bodyst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_clothing_bootsst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_clothing_glovesst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_clothing_helmst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_clothing_pantsst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_clothst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_craftsst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_cropst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_extractst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_flaskst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_gemsst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_hornst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_leatherst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_meatst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_metalst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_pearlst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_powderst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_quiverst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_shellst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_skinst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_soapst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_stonest: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_tablest: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_tallowst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_threadst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_toothst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_type: return RDF_Type::Enum;
		case DF_Type::resource_allotment_specifier_weapon_meleest: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_weapon_rangedst: return RDF_Type::Class;
		case DF_Type::resource_allotment_specifier_woodst: return RDF_Type::Class;
		case DF_Type::rhythm: return RDF_Type::Struct;
		case DF_Type::rhythm_sub1: return RDF_Type::Struct;
		case DF_Type::rhythm_sub1__T_anon_1: return RDF_Type::Compound;
		case DF_Type::rhythm_sub2: return RDF_Type::Struct;
		case DF_Type::room_rent_info: return RDF_Type::Struct;
		case DF_Type::room_rent_info__T_flags: return RDF_Type::Bitfield;
		case DF_Type::route_stockpile_link: return RDF_Type::Struct;
		case DF_Type::route_stockpile_link__T_mode: return RDF_Type::Bitfield;
		case DF_Type::scale: return RDF_Type::Struct;
		case DF_Type::scale__T_unk1: return RDF_Type::Compound;
		case DF_Type::scale_sub1: return RDF_Type::Struct;
		case DF_Type::scale_sub2: return RDF_Type::Struct;
		case DF_Type::schedule_info: return RDF_Type::Struct;
		case DF_Type::schedule_slot: return RDF_Type::Struct;
		case DF_Type::screw_pump_direction: return RDF_Type::Enum;
		case DF_Type::scribejob: return RDF_Type::Struct;
		case DF_Type::script_step_conditionalst: return RDF_Type::Class;
		case DF_Type::script_step_conditionalst__T_condition: return RDF_Type::Compound;
		case DF_Type::script_step_constructtopiclistst: return RDF_Type::Class;
		case DF_Type::script_step_dipeventst: return RDF_Type::Class;
		case DF_Type::script_step_diphistoryst: return RDF_Type::Class;
		case DF_Type::script_step_discussst: return RDF_Type::Class;
		case DF_Type::script_step_eventst: return RDF_Type::Class;
		case DF_Type::script_step_invasionst: return RDF_Type::Class;
		case DF_Type::script_step_setvarst: return RDF_Type::Class;
		case DF_Type::script_step_simpleactionst: return RDF_Type::Class;
		case DF_Type::script_step_textviewerst: return RDF_Type::Class;
		case DF_Type::script_step_topicdiscussionst: return RDF_Type::Class;
		case DF_Type::script_stepst: return RDF_Type::Class;
		case DF_Type::script_var_longst: return RDF_Type::Class;
		case DF_Type::script_var_unitst: return RDF_Type::Class;
		case DF_Type::script_varst: return RDF_Type::Class;
		case DF_Type::setup_character_info: return RDF_Type::Struct;
		case DF_Type::setup_character_info__T_available_embark_items: return RDF_Type::Compound;
		case DF_Type::setup_character_info__T_page: return RDF_Type::Enum;
		case DF_Type::setup_character_info__T_sel_trait_column: return RDF_Type::Enum;
		case DF_Type::setup_character_info__T_status: return RDF_Type::Enum;
		case DF_Type::shoes_flags: return RDF_Type::Enum;
		case DF_Type::shop_type: return RDF_Type::Enum;
		case DF_Type::siegeengine_type: return RDF_Type::Enum;
		case DF_Type::site_building_item: return RDF_Type::Struct;
		case DF_Type::site_dispute_type: return RDF_Type::Enum;
		case DF_Type::site_realization_building: return RDF_Type::Struct;
		case DF_Type::site_realization_building__T_unk_4c: return RDF_Type::Compound;
		case DF_Type::site_realization_building_info_castle_courtyardst: return RDF_Type::Class;
		case DF_Type::site_realization_building_info_castle_towerst: return RDF_Type::Class;
		case DF_Type::site_realization_building_info_castle_wallst: return RDF_Type::Class;
		case DF_Type::site_realization_building_info_hillock_housest: return RDF_Type::Class;
		case DF_Type::site_realization_building_info_market_squarest: return RDF_Type::Class;
		case DF_Type::site_realization_building_info_shop_housest: return RDF_Type::Class;
		case DF_Type::site_realization_building_info_tree_housest: return RDF_Type::Class;
		case DF_Type::site_realization_building_info_trenchesst: return RDF_Type::Class;
		case DF_Type::site_realization_building_info_trenchesst__T_spokes: return RDF_Type::Compound;
		case DF_Type::site_realization_building_infost: return RDF_Type::Class;
		case DF_Type::site_realization_building_type: return RDF_Type::Enum;
		case DF_Type::site_realization_crossroads: return RDF_Type::Struct;
		case DF_Type::site_reputation_info: return RDF_Type::Struct;
		case DF_Type::site_reputation_report: return RDF_Type::Struct;
		case DF_Type::site_shop_type: return RDF_Type::Enum;
		case DF_Type::site_type: return RDF_Type::Enum;
		case DF_Type::skill_rating: return RDF_Type::Enum;
		case DF_Type::slab_engraving_type: return RDF_Type::Enum;
		case DF_Type::sound_production_type: return RDF_Type::Enum;
		case DF_Type::spatter: return RDF_Type::Struct;
		case DF_Type::spatter__T_flags: return RDF_Type::Bitfield;
		case DF_Type::spatter_common: return RDF_Type::Struct;
		case DF_Type::spatter_common__T_base_flags: return RDF_Type::Bitfield;
		case DF_Type::special_mat_table: return RDF_Type::Struct;
		case DF_Type::specific_ref: return RDF_Type::Struct;
		case DF_Type::specific_ref__T_data: return RDF_Type::Union;
		case DF_Type::specific_ref__T_data__T_wrestle: return RDF_Type::Compound;
		case DF_Type::specific_ref_type: return RDF_Type::Enum;
		case DF_Type::sphere_type: return RDF_Type::Enum;
		case DF_Type::spoils_report: return RDF_Type::Struct;
		case DF_Type::squad: return RDF_Type::Struct;
		case DF_Type::squad__T_rooms: return RDF_Type::Compound;
		case DF_Type::squad_ammo_spec: return RDF_Type::Struct;
		case DF_Type::squad_ammo_spec__T_flags: return RDF_Type::Bitfield;
		case DF_Type::squad_event_type: return RDF_Type::Enum;
		case DF_Type::squad_order: return RDF_Type::Class;
		case DF_Type::squad_order_cannot_reason: return RDF_Type::Enum;
		case DF_Type::squad_order_cause_trouble_for_entityst: return RDF_Type::Class;
		case DF_Type::squad_order_defend_burrowsst: return RDF_Type::Class;
		case DF_Type::squad_order_drive_armies_from_sitest: return RDF_Type::Class;
		case DF_Type::squad_order_drive_entity_off_sitest: return RDF_Type::Class;
		case DF_Type::squad_order_kill_hfst: return RDF_Type::Class;
		case DF_Type::squad_order_kill_listst: return RDF_Type::Class;
		case DF_Type::squad_order_movest: return RDF_Type::Class;
		case DF_Type::squad_order_patrol_routest: return RDF_Type::Class;
		case DF_Type::squad_order_raid_sitest: return RDF_Type::Class;
		case DF_Type::squad_order_rescue_hfst: return RDF_Type::Class;
		case DF_Type::squad_order_retrieve_artifactst: return RDF_Type::Class;
		case DF_Type::squad_order_trainst: return RDF_Type::Class;
		case DF_Type::squad_order_type: return RDF_Type::Enum;
		case DF_Type::squad_position: return RDF_Type::Struct;
		case DF_Type::squad_schedule_entry: return RDF_Type::Struct;
		case DF_Type::squad_schedule_order: return RDF_Type::Struct;
		case DF_Type::squad_uniform_spec: return RDF_Type::Struct;
		case DF_Type::squad_use_flags: return RDF_Type::Bitfield;
		case DF_Type::stockpile_category: return RDF_Type::Enum;
		case DF_Type::stockpile_group_set: return RDF_Type::Bitfield;
		case DF_Type::stockpile_links: return RDF_Type::Struct;
		case DF_Type::stockpile_list: return RDF_Type::Enum;
		case DF_Type::stockpile_settings: return RDF_Type::Struct;
		case DF_Type::stockpile_settings__T_ammo: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_animals: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_armor: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_bars_blocks: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_cloth: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_coins: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_finished_goods: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_food: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_furniture: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_gems: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_leather: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_ore: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_refuse: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_sheet: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_stone: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_weapons: return RDF_Type::Compound;
		case DF_Type::stockpile_settings__T_wood: return RDF_Type::Compound;
		case DF_Type::stop_depart_condition: return RDF_Type::Struct;
		case DF_Type::stop_depart_condition__T_direction: return RDF_Type::Enum;
		case DF_Type::stop_depart_condition__T_flags: return RDF_Type::Bitfield;
		case DF_Type::stop_depart_condition__T_mode: return RDF_Type::Enum;
		case DF_Type::strain_type: return RDF_Type::Enum;
		case DF_Type::stratus_type: return RDF_Type::Enum;
		case DF_Type::syndrome: return RDF_Type::Struct;
		case DF_Type::syndrome_flags: return RDF_Type::Bitfield;
		case DF_Type::tactical_situation: return RDF_Type::Enum;
		case DF_Type::talk_choice: return RDF_Type::Struct;
		case DF_Type::talk_choice__T_unk: return RDF_Type::Compound;
		case DF_Type::talk_choice_type: return RDF_Type::Enum;
		case DF_Type::temperaturest: return RDF_Type::Struct;
		case DF_Type::temple_deity_data: return RDF_Type::Union;
		case DF_Type::temple_deity_type: return RDF_Type::Enum;
		case DF_Type::text_info_element_longst: return RDF_Type::Class;
		case DF_Type::text_info_element_stringst: return RDF_Type::Class;
		case DF_Type::text_info_elementst: return RDF_Type::Class;
		case DF_Type::texture_handler: return RDF_Type::Struct;
		case DF_Type::tile_bitmask: return RDF_Type::Struct;
		case DF_Type::tile_building_occ: return RDF_Type::Enum;
		case DF_Type::tile_designation: return RDF_Type::Bitfield;
		case DF_Type::tile_dig_designation: return RDF_Type::Enum;
		case DF_Type::tile_liquid: return RDF_Type::Enum;
		case DF_Type::tile_liquid_flow: return RDF_Type::Bitfield;
		case DF_Type::tile_liquid_flow_dir: return RDF_Type::Enum;
		case DF_Type::tile_occupancy: return RDF_Type::Bitfield;
		case DF_Type::tile_page: return RDF_Type::Struct;
		case DF_Type::tile_traffic: return RDF_Type::Enum;
		case DF_Type::tiletype: return RDF_Type::Enum;
		case DF_Type::tiletype_material: return RDF_Type::Enum;
		case DF_Type::tiletype_shape: return RDF_Type::Enum;
		case DF_Type::tiletype_shape_basic: return RDF_Type::Enum;
		case DF_Type::tiletype_special: return RDF_Type::Enum;
		case DF_Type::tiletype_variant: return RDF_Type::Enum;
		case DF_Type::timbre_type: return RDF_Type::Enum;
		case DF_Type::timed_event: return RDF_Type::Struct;
		case DF_Type::timed_event_type: return RDF_Type::Enum;
		case DF_Type::tissue: return RDF_Type::Struct;
		case DF_Type::tissue_flags: return RDF_Type::Enum;
		case DF_Type::tissue_style_raw: return RDF_Type::Struct;
		case DF_Type::tissue_style_type: return RDF_Type::Enum;
		case DF_Type::tissue_template: return RDF_Type::Struct;
		case DF_Type::tool_flags: return RDF_Type::Enum;
		case DF_Type::tool_uses: return RDF_Type::Enum;
		case DF_Type::tower_shape: return RDF_Type::Bitfield;
		case DF_Type::toy_flags: return RDF_Type::Enum;
		case DF_Type::training_assignment: return RDF_Type::Struct;
		case DF_Type::training_assignment__T_flags: return RDF_Type::Bitfield;
		case DF_Type::training_knowledge_level: return RDF_Type::Enum;
		case DF_Type::trap_type: return RDF_Type::Enum;
		case DF_Type::trapcomp_flags: return RDF_Type::Enum;
		case DF_Type::tree_house_type: return RDF_Type::Enum;
		case DF_Type::tuning_type: return RDF_Type::Enum;
		case DF_Type::ui: return RDF_Type::Struct;
		case DF_Type::ui__T_alerts: return RDF_Type::Compound;
		case DF_Type::ui__T_alerts__T_list: return RDF_Type::Compound;
		case DF_Type::ui__T_becoming_capital: return RDF_Type::Compound;
		case DF_Type::ui__T_burrows: return RDF_Type::Compound;
		case DF_Type::ui__T_economy_prices: return RDF_Type::Compound;
		case DF_Type::ui__T_economy_prices__T_price_adjustment: return RDF_Type::Compound;
		case DF_Type::ui__T_economy_prices__T_price_setter: return RDF_Type::Compound;
		case DF_Type::ui__T_equipment: return RDF_Type::Compound;
		case DF_Type::ui__T_equipment__T_update: return RDF_Type::Bitfield;
		case DF_Type::ui__T_hauling: return RDF_Type::Compound;
		case DF_Type::ui__T_invasions: return RDF_Type::Compound;
		case DF_Type::ui__T_kitchen: return RDF_Type::Compound;
		case DF_Type::ui__T_main: return RDF_Type::Compound;
		case DF_Type::ui__T_main__T_dead_citizens: return RDF_Type::Compound;
		case DF_Type::ui__T_map_edge: return RDF_Type::Compound;
		case DF_Type::ui__T_squads: return RDF_Type::Compound;
		case DF_Type::ui__T_stockpile: return RDF_Type::Compound;
		case DF_Type::ui__T_tax_collection: return RDF_Type::Compound;
		case DF_Type::ui__T_unk23c8_flags: return RDF_Type::Bitfield;
		case DF_Type::ui__T_unk2a8c: return RDF_Type::Compound;
		case DF_Type::ui__T_waypoints: return RDF_Type::Compound;
		case DF_Type::ui__T_waypoints__T_points: return RDF_Type::Compound;
		case DF_Type::ui__T_waypoints__T_routes: return RDF_Type::Compound;
		case DF_Type::ui_advmode: return RDF_Type::Struct;
		case DF_Type::ui_advmode__T_assume_identity: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_companions: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_conversation: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_conversation__T_choices: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_conversation__T_targets: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_conversation__T_targets__T_type: return RDF_Type::Enum;
		case DF_Type::ui_advmode__T_interactions: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_show_menu: return RDF_Type::Enum;
		case DF_Type::ui_advmode__T_travel_right_map: return RDF_Type::Enum;
		case DF_Type::ui_advmode__T_unk_3124: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_unk_3170: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_unk_3170__T_unk_2: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_unk_v40_1: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_unk_v40_2: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_unk_v40_3: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_unk_v40_4: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_unk_v40_4__T_unk_v40_4a: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_unk_v40_5: return RDF_Type::Compound;
		case DF_Type::ui_advmode__T_unk_v42_1: return RDF_Type::Compound;
		case DF_Type::ui_advmode_menu: return RDF_Type::Enum;
		case DF_Type::ui_build_item_req: return RDF_Type::Struct;
		case DF_Type::ui_build_selector: return RDF_Type::Class;
		case DF_Type::ui_hotkey: return RDF_Type::Struct;
		case DF_Type::ui_hotkey__T_cmd: return RDF_Type::Enum;
		case DF_Type::ui_hotkey___union2: return RDF_Type::Union;
		case DF_Type::ui_look_list: return RDF_Type::Struct;
		case DF_Type::ui_look_list__T_items: return RDF_Type::Compound;
		case DF_Type::ui_look_list__T_items__T_data: return RDF_Type::Union;
		case DF_Type::ui_look_list__T_items__T_data__T_Magma: return RDF_Type::Compound;
		case DF_Type::ui_look_list__T_items__T_data__T_Spatter: return RDF_Type::Compound;
		case DF_Type::ui_look_list__T_items__T_data__T_Water: return RDF_Type::Compound;
		case DF_Type::ui_look_list__T_items__T_type: return RDF_Type::Enum;
		case DF_Type::ui_sidebar_menus: return RDF_Type::Struct;
		case DF_Type::ui_sidebar_menus__T_barracks: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_building: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_command_line: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_designation: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_designation__T_mine_mode: return RDF_Type::Enum;
		case DF_Type::ui_sidebar_menus__T_hospital: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_job_details: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_location: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_minimap: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_unit: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_unit__T_expel_error: return RDF_Type::Enum;
		case DF_Type::ui_sidebar_menus__T_unit_cursor: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_unit_skills: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_workshop_job: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_zone: return RDF_Type::Compound;
		case DF_Type::ui_sidebar_menus__T_zone__T_mode: return RDF_Type::Enum;
		case DF_Type::ui_sidebar_mode: return RDF_Type::Enum;
		case DF_Type::ui_unit_view_mode: return RDF_Type::Struct;
		case DF_Type::ui_unit_view_mode__T_value: return RDF_Type::Enum;
		case DF_Type::uint16_t: return RDF_Type::DFArray;
		case DF_Type::uint8_t: return RDF_Type::DFArray;
		case DF_Type::undead_flags: return RDF_Type::Bitfield;
		case DF_Type::uniform_category: return RDF_Type::Enum;
		case DF_Type::uniform_flags: return RDF_Type::Bitfield;
		case DF_Type::uniform_indiv_choice: return RDF_Type::Bitfield;
		case DF_Type::unit: return RDF_Type::Class;
		case DF_Type::unit__T_animal: return RDF_Type::Compound;
		case DF_Type::unit__T_appearance: return RDF_Type::Compound;
		case DF_Type::unit__T_body: return RDF_Type::Compound;
		case DF_Type::unit__T_counters2: return RDF_Type::Compound;
		case DF_Type::unit__T_counters: return RDF_Type::Compound;
		case DF_Type::unit__T_counters__T_soldier_mood: return RDF_Type::Enum;
		case DF_Type::unit__T_curse: return RDF_Type::Compound;
		case DF_Type::unit__T_enemy: return RDF_Type::Compound;
		case DF_Type::unit__T_enemy__T_undead: return RDF_Type::Compound;
		case DF_Type::unit__T_enemy__T_unk_448: return RDF_Type::Compound;
		case DF_Type::unit__T_enemy__T_unk_448__T_unk: return RDF_Type::Compound;
		case DF_Type::unit__T_enemy__T_unk_44c: return RDF_Type::Compound;
		case DF_Type::unit__T_enemy__T_unk_v40_sub3: return RDF_Type::Compound;
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_2: return RDF_Type::Compound;
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_6: return RDF_Type::Compound;
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7: return RDF_Type::Compound;
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1: return RDF_Type::Compound;
		case DF_Type::unit__T_enemy__T_witness_reports: return RDF_Type::Compound;
		case DF_Type::unit__T_job: return RDF_Type::Compound;
		case DF_Type::unit__T_meeting: return RDF_Type::Compound;
		case DF_Type::unit__T_meeting__T_state: return RDF_Type::Enum;
		case DF_Type::unit__T_military: return RDF_Type::Compound;
		case DF_Type::unit__T_military__T_pickup_flags: return RDF_Type::Bitfield;
		case DF_Type::unit__T_opponent: return RDF_Type::Compound;
		case DF_Type::unit__T_path: return RDF_Type::Compound;
		case DF_Type::unit__T_reports: return RDF_Type::Compound;
		case DF_Type::unit__T_status2: return RDF_Type::Compound;
		case DF_Type::unit__T_status: return RDF_Type::Compound;
		case DF_Type::unit__T_status__T_eat_history: return RDF_Type::Compound;
		case DF_Type::unit__T_status__T_eat_history__T_drink: return RDF_Type::Compound;
		case DF_Type::unit__T_status__T_eat_history__T_food: return RDF_Type::Compound;
		case DF_Type::unit__T_syndromes: return RDF_Type::Compound;
		case DF_Type::unit__T_unknown7: return RDF_Type::Compound;
		case DF_Type::unit_action: return RDF_Type::Struct;
		case DF_Type::unit_action__T_data: return RDF_Type::Union;
		case DF_Type::unit_action_data_attack: return RDF_Type::Struct;
		case DF_Type::unit_action_data_attack__T_flags: return RDF_Type::Bitfield;
		case DF_Type::unit_action_data_attack__T_unk_4: return RDF_Type::Compound;
		case DF_Type::unit_action_data_attack__T_unk_4__T_wrestle_type: return RDF_Type::Enum;
		case DF_Type::unit_action_data_block: return RDF_Type::Struct;
		case DF_Type::unit_action_data_climb: return RDF_Type::Struct;
		case DF_Type::unit_action_data_dodge: return RDF_Type::Struct;
		case DF_Type::unit_action_data_hold_item: return RDF_Type::Struct;
		case DF_Type::unit_action_data_hold_terrain: return RDF_Type::Struct;
		case DF_Type::unit_action_data_job2: return RDF_Type::Struct;
		case DF_Type::unit_action_data_job: return RDF_Type::Struct;
		case DF_Type::unit_action_data_jump: return RDF_Type::Struct;
		case DF_Type::unit_action_data_lie_down: return RDF_Type::Struct;
		case DF_Type::unit_action_data_move: return RDF_Type::Struct;
		case DF_Type::unit_action_data_move__T_flags: return RDF_Type::Bitfield;
		case DF_Type::unit_action_data_parry: return RDF_Type::Struct;
		case DF_Type::unit_action_data_push_object: return RDF_Type::Struct;
		case DF_Type::unit_action_data_recover: return RDF_Type::Struct;
		case DF_Type::unit_action_data_release_item: return RDF_Type::Struct;
		case DF_Type::unit_action_data_release_terrain: return RDF_Type::Struct;
		case DF_Type::unit_action_data_stand_up: return RDF_Type::Struct;
		case DF_Type::unit_action_data_suck_blood: return RDF_Type::Struct;
		case DF_Type::unit_action_data_talk: return RDF_Type::Struct;
		case DF_Type::unit_action_data_unsteady: return RDF_Type::Struct;
		case DF_Type::unit_action_type: return RDF_Type::Enum;
		case DF_Type::unit_appearance: return RDF_Type::Struct;
		case DF_Type::unit_attribute: return RDF_Type::Struct;
		case DF_Type::unit_bp_health_flags: return RDF_Type::Bitfield;
		case DF_Type::unit_chunk: return RDF_Type::Struct;
		case DF_Type::unit_chunk__T_units: return RDF_Type::Compound;
		case DF_Type::unit_coin_debt: return RDF_Type::Struct;
		case DF_Type::unit_complaint: return RDF_Type::Struct;
		case DF_Type::unit_complaint__T_type: return RDF_Type::Enum;
		case DF_Type::unit_dance_skill: return RDF_Type::Struct;
		case DF_Type::unit_demand: return RDF_Type::Struct;
		case DF_Type::unit_demand__T_place: return RDF_Type::Enum;
		case DF_Type::unit_emotion_memory: return RDF_Type::Struct;
		case DF_Type::unit_flags1: return RDF_Type::Bitfield;
		case DF_Type::unit_flags2: return RDF_Type::Bitfield;
		case DF_Type::unit_flags3: return RDF_Type::Bitfield;
		case DF_Type::unit_flags4: return RDF_Type::Bitfield;
		case DF_Type::unit_genes: return RDF_Type::Struct;
		case DF_Type::unit_ghost_info: return RDF_Type::Struct;
		case DF_Type::unit_ghost_info__T_flags: return RDF_Type::Bitfield;
		case DF_Type::unit_ghost_info__T_target: return RDF_Type::Union;
		case DF_Type::unit_health_flags: return RDF_Type::Bitfield;
		case DF_Type::unit_health_info: return RDF_Type::Struct;
		case DF_Type::unit_health_info__T_op_history: return RDF_Type::Compound;
		case DF_Type::unit_health_info__T_op_history__T_info: return RDF_Type::Union;
		case DF_Type::unit_health_info__T_op_history__T_info__T_bandage: return RDF_Type::Compound;
		case DF_Type::unit_health_info__T_op_history__T_info__T_crutch: return RDF_Type::Compound;
		case DF_Type::unit_instrument_skill: return RDF_Type::Struct;
		case DF_Type::unit_inventory_item: return RDF_Type::Struct;
		case DF_Type::unit_inventory_item__T_mode: return RDF_Type::Enum;
		case DF_Type::unit_item_use: return RDF_Type::Struct;
		case DF_Type::unit_item_wrestle: return RDF_Type::Struct;
		case DF_Type::unit_labor: return RDF_Type::Enum;
		case DF_Type::unit_labor_category: return RDF_Type::Enum;
		case DF_Type::unit_misc_trait: return RDF_Type::Struct;
		case DF_Type::unit_musical_skill: return RDF_Type::Struct;
		case DF_Type::unit_path_goal: return RDF_Type::Enum;
		case DF_Type::unit_personality: return RDF_Type::Struct;
		case DF_Type::unit_personality__T_dreams: return RDF_Type::Compound;
		case DF_Type::unit_personality__T_emotions: return RDF_Type::Compound;
		case DF_Type::unit_personality__T_emotions__T_flags: return RDF_Type::Bitfield;
		case DF_Type::unit_personality__T_flags: return RDF_Type::Bitfield;
		case DF_Type::unit_personality__T_memories: return RDF_Type::Compound;
		case DF_Type::unit_personality__T_memories__T_reflected_on: return RDF_Type::Compound;
		case DF_Type::unit_personality__T_needs: return RDF_Type::Compound;
		case DF_Type::unit_personality__T_unk5: return RDF_Type::Compound;
		case DF_Type::unit_personality__T_unk_v40_2: return RDF_Type::Compound;
		case DF_Type::unit_personality__T_unk_v40_6: return RDF_Type::Compound;
		case DF_Type::unit_personality__T_values: return RDF_Type::Compound;
		case DF_Type::unit_poetic_skill: return RDF_Type::Struct;
		case DF_Type::unit_preference: return RDF_Type::Struct;
		case DF_Type::unit_preference__T_type: return RDF_Type::Enum;
		case DF_Type::unit_preference___union3: return RDF_Type::Union;
		case DF_Type::unit_relationship_type: return RDF_Type::Enum;
		case DF_Type::unit_report_type: return RDF_Type::Enum;
		case DF_Type::unit_request: return RDF_Type::Struct;
		case DF_Type::unit_request__T_type: return RDF_Type::Enum;
		case DF_Type::unit_skill: return RDF_Type::Struct;
		case DF_Type::unit_soul: return RDF_Type::Struct;
		case DF_Type::unit_soul__T_performance_skills: return RDF_Type::Compound;
		case DF_Type::unit_station_type: return RDF_Type::Enum;
		case DF_Type::unit_storage_status: return RDF_Type::Struct;
		case DF_Type::unit_syndrome: return RDF_Type::Struct;
		case DF_Type::unit_syndrome__T_flags: return RDF_Type::Bitfield;
		case DF_Type::unit_syndrome__T_symptoms: return RDF_Type::Compound;
		case DF_Type::unit_syndrome__T_symptoms__T_flags: return RDF_Type::Bitfield;
		case DF_Type::unit_thought_type: return RDF_Type::Enum;
		case DF_Type::unit_unk_138: return RDF_Type::Struct;
		case DF_Type::unit_wound: return RDF_Type::Struct;
		case DF_Type::unit_wound__T_flags: return RDF_Type::Bitfield;
		case DF_Type::unit_wound__T_parts: return RDF_Type::Compound;
		case DF_Type::units_other_id: return RDF_Type::Enum;
		case DF_Type::unk_scale_enum_type: return RDF_Type::Enum;
		case DF_Type::vague_relationship_type: return RDF_Type::Enum;
		case DF_Type::value_type: return RDF_Type::Enum;
		case DF_Type::vehicle: return RDF_Type::Struct;
		case DF_Type::vermin: return RDF_Type::Struct;
		case DF_Type::vermin_flags: return RDF_Type::Bitfield;
		case DF_Type::viewscreen: return RDF_Type::Class;
		case DF_Type::viewscreen_adopt_regionst: return RDF_Type::Class;
		case DF_Type::viewscreen_adventure_logst: return RDF_Type::Class;
		case DF_Type::viewscreen_adventure_logst__T_info_mode: return RDF_Type::Enum;
		case DF_Type::viewscreen_adventure_logst__T_mode: return RDF_Type::Enum;
		case DF_Type::viewscreen_adventure_logst__T_unk_68: return RDF_Type::Compound;
		case DF_Type::viewscreen_announcelistst: return RDF_Type::Class;
		case DF_Type::viewscreen_assign_display_itemst: return RDF_Type::Class;
		case DF_Type::viewscreen_assign_display_itemst__T_sel_column: return RDF_Type::Enum;
		case DF_Type::viewscreen_barterst: return RDF_Type::Class;
		case DF_Type::viewscreen_buildinglistst: return RDF_Type::Class;
		case DF_Type::viewscreen_buildingst: return RDF_Type::Class;
		case DF_Type::viewscreen_choose_start_sitest: return RDF_Type::Class;
		case DF_Type::viewscreen_choose_start_sitest__T_finder: return RDF_Type::Compound;
		case DF_Type::viewscreen_choose_start_sitest__T_finder__T_finder_state: return RDF_Type::Enum;
		case DF_Type::viewscreen_choose_start_sitest__T_page: return RDF_Type::Enum;
		case DF_Type::viewscreen_civlistst: return RDF_Type::Class;
		case DF_Type::viewscreen_civlistst__T_artifact_details: return RDF_Type::Compound;
		case DF_Type::viewscreen_civlistst__T_page: return RDF_Type::Enum;
		case DF_Type::viewscreen_civlistst__T_rumors: return RDF_Type::Compound;
		case DF_Type::viewscreen_civlistst__T_rumors__T_type: return RDF_Type::Enum;
		case DF_Type::viewscreen_civlistst__T_unk_cache: return RDF_Type::Compound;
		case DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp1: return RDF_Type::Compound;
		case DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp2: return RDF_Type::Compound;
		case DF_Type::viewscreen_counterintelligencest: return RDF_Type::Class;
		case DF_Type::viewscreen_createquotast: return RDF_Type::Class;
		case DF_Type::viewscreen_customize_unitst: return RDF_Type::Class;
		case DF_Type::viewscreen_dungeon_monsterstatusst: return RDF_Type::Class;
		case DF_Type::viewscreen_dungeon_wrestlest: return RDF_Type::Class;
		case DF_Type::viewscreen_dungeon_wrestlest__T_unk1: return RDF_Type::Compound;
		case DF_Type::viewscreen_dungeonmodest: return RDF_Type::Class;
		case DF_Type::viewscreen_dwarfmodest: return RDF_Type::Class;
		case DF_Type::viewscreen_entityst: return RDF_Type::Class;
		case DF_Type::viewscreen_export_graphical_mapst: return RDF_Type::Class;
		case DF_Type::viewscreen_export_graphical_mapst__T_rgb_buffer: return RDF_Type::Compound;
		case DF_Type::viewscreen_export_regionst: return RDF_Type::Class;
		case DF_Type::viewscreen_export_regionst__T_unk1: return RDF_Type::Compound;
		case DF_Type::viewscreen_game_cleanerst: return RDF_Type::Class;
		case DF_Type::viewscreen_game_cleanerst__T_state: return RDF_Type::Enum;
		case DF_Type::viewscreen_image_creator_mode: return RDF_Type::Enum;
		case DF_Type::viewscreen_image_creatorst: return RDF_Type::Class;
		case DF_Type::viewscreen_image_creatorst__T_artifacts: return RDF_Type::Compound;
		case DF_Type::viewscreen_image_creatorst__T_entities: return RDF_Type::Compound;
		case DF_Type::viewscreen_image_creatorst__T_histfigs: return RDF_Type::Compound;
		case DF_Type::viewscreen_image_creatorst__T_objects: return RDF_Type::Compound;
		case DF_Type::viewscreen_image_creatorst__T_plants: return RDF_Type::Compound;
		case DF_Type::viewscreen_image_creatorst__T_relationships: return RDF_Type::Compound;
		case DF_Type::viewscreen_image_creatorst__T_shapes: return RDF_Type::Compound;
		case DF_Type::viewscreen_image_creatorst__T_sites: return RDF_Type::Compound;
		case DF_Type::viewscreen_image_creatorst__T_trees: return RDF_Type::Compound;
		case DF_Type::viewscreen_itemst: return RDF_Type::Class;
		case DF_Type::viewscreen_joblistst: return RDF_Type::Class;
		case DF_Type::viewscreen_jobmanagementst: return RDF_Type::Class;
		case DF_Type::viewscreen_jobst: return RDF_Type::Class;
		case DF_Type::viewscreen_justicest: return RDF_Type::Class;
		case DF_Type::viewscreen_justicest__T_cur_column: return RDF_Type::Enum;
		case DF_Type::viewscreen_kitchenpref_page: return RDF_Type::Enum;
		case DF_Type::viewscreen_kitchenprefst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_arena_creaturest: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_assigntradest: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_choose_language_namest: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_choose_language_namest__T_current_component: return RDF_Type::Enum;
		case DF_Type::viewscreen_layer_currencyst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_export_play_mapst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_militaryst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_militaryst__T_ammo: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_militaryst__T_ammo__T_add_item: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_militaryst__T_ammo__T_material: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_militaryst__T_equip: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_add_item: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_assigned: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_color: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode: return RDF_Type::Enum;
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_material: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_mode: return RDF_Type::Enum;
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_uniform: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_militaryst__T_page: return RDF_Type::Enum;
		case DF_Type::viewscreen_layer_militaryst__T_positions: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_militaryst__T_squad_members: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_militaryst__T_squads: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_musicsoundst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_noblelistst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_noblelistst__T_candidates: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_noblelistst__T_info: return RDF_Type::Compound;
		case DF_Type::viewscreen_layer_noblelistst__T_mode: return RDF_Type::Enum;
		case DF_Type::viewscreen_layer_overall_healthst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_reactionst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_squad_schedulest: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_stockpilest: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_stone_restrictionst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_unit_actionst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_unit_healthst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_unit_relationshipst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_world_gen_param_presetst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_world_gen_paramst: return RDF_Type::Class;
		case DF_Type::viewscreen_layer_world_gen_paramst__T_unk1: return RDF_Type::Compound;
		case DF_Type::viewscreen_legendsst: return RDF_Type::Class;
		case DF_Type::viewscreen_legendsst__T_anon_7: return RDF_Type::Compound;
		case DF_Type::viewscreen_legendsst__T_anon_7__T_anon_3: return RDF_Type::Compound;
		case DF_Type::viewscreen_legendsst__T_cur_page: return RDF_Type::Enum;
		case DF_Type::viewscreen_loadgamest: return RDF_Type::Class;
		case DF_Type::viewscreen_loadgamest__T_cur_step: return RDF_Type::Enum;
		case DF_Type::viewscreen_locationsst: return RDF_Type::Class;
		case DF_Type::viewscreen_locationsst__T_in_edit: return RDF_Type::Enum;
		case DF_Type::viewscreen_locationsst__T_menu: return RDF_Type::Enum;
		case DF_Type::viewscreen_meetingst: return RDF_Type::Class;
		case DF_Type::viewscreen_movieplayerst: return RDF_Type::Class;
		case DF_Type::viewscreen_new_regionst: return RDF_Type::Class;
		case DF_Type::viewscreen_new_regionst__T_worldgen_presets: return RDF_Type::Compound;
		case DF_Type::viewscreen_noblest: return RDF_Type::Class;
		case DF_Type::viewscreen_optionst: return RDF_Type::Class;
		case DF_Type::viewscreen_overallstatusst: return RDF_Type::Class;
		case DF_Type::viewscreen_petitionsst: return RDF_Type::Class;
		case DF_Type::viewscreen_petst: return RDF_Type::Class;
		case DF_Type::viewscreen_petst__T_animal: return RDF_Type::Union;
		case DF_Type::viewscreen_petst__T_mode: return RDF_Type::Enum;
		case DF_Type::viewscreen_pricest: return RDF_Type::Class;
		case DF_Type::viewscreen_reportlistst: return RDF_Type::Class;
		case DF_Type::viewscreen_requestagreementst: return RDF_Type::Class;
		case DF_Type::viewscreen_savegamest: return RDF_Type::Class;
		case DF_Type::viewscreen_selectitemst: return RDF_Type::Class;
		case DF_Type::viewscreen_setupadventurest: return RDF_Type::Class;
		case DF_Type::viewscreen_setupadventurest__T_page: return RDF_Type::Enum;
		case DF_Type::viewscreen_setupadventurest__T_races_info: return RDF_Type::Compound;
		case DF_Type::viewscreen_setupadventurest__T_status: return RDF_Type::Enum;
		case DF_Type::viewscreen_setupdwarfgamest: return RDF_Type::Class;
		case DF_Type::viewscreen_setupdwarfgamest__T_animals: return RDF_Type::Compound;
		case DF_Type::viewscreen_setupdwarfgamest__T_mode: return RDF_Type::Enum;
		case DF_Type::viewscreen_setupdwarfgamest__T_unk_v43: return RDF_Type::Compound;
		case DF_Type::viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9: return RDF_Type::Compound;
		case DF_Type::viewscreen_storesst: return RDF_Type::Class;
		case DF_Type::viewscreen_textviewerst: return RDF_Type::Class;
		case DF_Type::viewscreen_textviewerst__T_formatted_text: return RDF_Type::Compound;
		case DF_Type::viewscreen_textviewerst__T_formatted_text__T_flags: return RDF_Type::Bitfield;
		case DF_Type::viewscreen_titlest: return RDF_Type::Class;
		case DF_Type::viewscreen_titlest__T_sel_subpage: return RDF_Type::Enum;
		case DF_Type::viewscreen_titlest__T_start_savegames: return RDF_Type::Compound;
		case DF_Type::viewscreen_topicmeeting_fill_land_holder_positionsst: return RDF_Type::Class;
		case DF_Type::viewscreen_topicmeeting_takerequestsst: return RDF_Type::Class;
		case DF_Type::viewscreen_topicmeetingst: return RDF_Type::Class;
		case DF_Type::viewscreen_tradeagreementst: return RDF_Type::Class;
		case DF_Type::viewscreen_tradegoodsst: return RDF_Type::Class;
		case DF_Type::viewscreen_tradelistst: return RDF_Type::Class;
		case DF_Type::viewscreen_treasurelistst: return RDF_Type::Class;
		case DF_Type::viewscreen_unitlist_page: return RDF_Type::Enum;
		case DF_Type::viewscreen_unitlistst: return RDF_Type::Class;
		case DF_Type::viewscreen_unitst: return RDF_Type::Class;
		case DF_Type::viewscreen_update_regionst: return RDF_Type::Class;
		case DF_Type::viewscreen_wagesst: return RDF_Type::Class;
		case DF_Type::viewscreen_workquota_conditionst: return RDF_Type::Class;
		case DF_Type::viewscreen_workquota_conditionst__T_mode: return RDF_Type::Enum;
		case DF_Type::viewscreen_workquota_conditionst__T_traits: return RDF_Type::Compound;
		case DF_Type::viewscreen_workquota_conditionst__T_traits__T_flags: return RDF_Type::Bitfield;
		case DF_Type::viewscreen_workquota_detailsst: return RDF_Type::Class;
		case DF_Type::viewscreen_workshop_profilest: return RDF_Type::Class;
		case DF_Type::viewscreen_workshop_profilest__T_tab: return RDF_Type::Enum;
		case DF_Type::weapon_attack: return RDF_Type::Struct;
		case DF_Type::weapon_attack__T_flags: return RDF_Type::Bitfield;
		case DF_Type::weapon_flags: return RDF_Type::Enum;
		case DF_Type::weather_type: return RDF_Type::Enum;
		case DF_Type::web_cluster: return RDF_Type::Struct;
		case DF_Type::whereabouts_type: return RDF_Type::Enum;
		case DF_Type::widget_menu: return RDF_Type::Struct;
		case DF_Type::widget_textbox: return RDF_Type::Struct;
		case DF_Type::workshop_profile: return RDF_Type::Struct;
		case DF_Type::workshop_type: return RDF_Type::Enum;
		case DF_Type::world: return RDF_Type::Struct;
		case DF_Type::world__T_activities: return RDF_Type::Compound;
		case DF_Type::world__T_agreements: return RDF_Type::Compound;
		case DF_Type::world__T_area_grasses: return RDF_Type::Compound;
		case DF_Type::world__T_area_grasses__T_layer_grasses: return RDF_Type::Compound;
		case DF_Type::world__T_arena_settings: return RDF_Type::Compound;
		case DF_Type::world__T_arena_spawn: return RDF_Type::Compound;
		case DF_Type::world__T_arena_spawn__T_equipment: return RDF_Type::Compound;
		case DF_Type::world__T_arena_spawn__T_item_types: return RDF_Type::Compound;
		case DF_Type::world__T_arena_spawn__T_tame: return RDF_Type::Enum;
		case DF_Type::world__T_armies: return RDF_Type::Compound;
		case DF_Type::world__T_army_controllers: return RDF_Type::Compound;
		case DF_Type::world__T_army_tracking_info: return RDF_Type::Compound;
		case DF_Type::world__T_artifacts: return RDF_Type::Compound;
		case DF_Type::world__T_belief_systems: return RDF_Type::Compound;
		case DF_Type::world__T_crimes: return RDF_Type::Compound;
		case DF_Type::world__T_cultural_identities: return RDF_Type::Compound;
		case DF_Type::world__T_cur_savegame: return RDF_Type::Compound;
		case DF_Type::world__T_dance_forms: return RDF_Type::Compound;
		case DF_Type::world__T_divination_sets: return RDF_Type::Compound;
		case DF_Type::world__T_enemy_status_cache: return RDF_Type::Compound;
		case DF_Type::world__T_entities: return RDF_Type::Compound;
		case DF_Type::world__T_features: return RDF_Type::Compound;
		case DF_Type::world__T_flow_engine: return RDF_Type::Compound;
		case DF_Type::world__T_flow_guides: return RDF_Type::Compound;
		case DF_Type::world__T_formations: return RDF_Type::Compound;
		case DF_Type::world__T_identities: return RDF_Type::Compound;
		case DF_Type::world__T_image_sets: return RDF_Type::Compound;
		case DF_Type::world__T_incidents: return RDF_Type::Compound;
		case DF_Type::world__T_interaction_instances: return RDF_Type::Compound;
		case DF_Type::world__T_items: return RDF_Type::Compound;
		case DF_Type::world__T_languages: return RDF_Type::Compound;
		case DF_Type::world__T_map: return RDF_Type::Compound;
		case DF_Type::world__T_map_extras: return RDF_Type::Compound;
		case DF_Type::world__T_math: return RDF_Type::Compound;
		case DF_Type::world__T_math__T_approx: return RDF_Type::Compound;
		case DF_Type::world__T_musical_forms: return RDF_Type::Compound;
		case DF_Type::world__T_nemesis: return RDF_Type::Compound;
		case DF_Type::world__T_occupations: return RDF_Type::Compound;
		case DF_Type::world__T_pathfinder: return RDF_Type::Compound;
		case DF_Type::world__T_pathfinder__T_boundary_heap: return RDF_Type::Compound;
		case DF_Type::world__T_plants: return RDF_Type::Compound;
		case DF_Type::world__T_poetic_forms: return RDF_Type::Compound;
		case DF_Type::world__T_profession_skills: return RDF_Type::Compound;
		case DF_Type::world__T_rhythms: return RDF_Type::Compound;
		case DF_Type::world__T_scales: return RDF_Type::Compound;
		case DF_Type::world__T_schedules: return RDF_Type::Compound;
		case DF_Type::world__T_squads: return RDF_Type::Compound;
		case DF_Type::world__T_status: return RDF_Type::Compound;
		case DF_Type::world__T_status__T_flags: return RDF_Type::Bitfield;
		case DF_Type::world__T_status__T_slots: return RDF_Type::Compound;
		case DF_Type::world__T_status__T_slots__T_flags: return RDF_Type::Bitfield;
		case DF_Type::world__T_stockpile: return RDF_Type::Compound;
		case DF_Type::world__T_stockpile__T_simple1: return RDF_Type::Compound;
		case DF_Type::world__T_stockpile__T_simple2: return RDF_Type::Compound;
		case DF_Type::world__T_stockpile__T_simple3: return RDF_Type::Compound;
		case DF_Type::world__T_units: return RDF_Type::Compound;
		case DF_Type::world__T_unk_131ec0: return RDF_Type::Compound;
		case DF_Type::world__T_unk_131ef0: return RDF_Type::Compound;
		case DF_Type::world__T_unk_131ef0__T_claims: return RDF_Type::Compound;
		case DF_Type::world__T_unk_19325c: return RDF_Type::Compound;
		case DF_Type::world__T_unk_19325c__T_anon_1: return RDF_Type::Compound;
		case DF_Type::world__T_unk_19325c__T_anon_2: return RDF_Type::Compound;
		case DF_Type::world__T_unk_19325c__T_anon_3: return RDF_Type::Compound;
		case DF_Type::world__T_unk_26c678: return RDF_Type::Compound;
		case DF_Type::world__T_unk_v40_6: return RDF_Type::Compound;
		case DF_Type::world__T_vehicles: return RDF_Type::Compound;
		case DF_Type::world__T_vermin: return RDF_Type::Compound;
		case DF_Type::world__T_worldgen: return RDF_Type::Compound;
		case DF_Type::world__T_worldgen__T_worldgen_parms: return RDF_Type::Compound;
		case DF_Type::world__T_worldgen_coord_buf: return RDF_Type::Compound;
		case DF_Type::world__T_worldgen_status: return RDF_Type::Compound;
		case DF_Type::world__T_written_contents: return RDF_Type::Compound;
		case DF_Type::world_construction: return RDF_Type::Class;
		case DF_Type::world_construction_bridgest: return RDF_Type::Class;
		case DF_Type::world_construction_roadst: return RDF_Type::Class;
		case DF_Type::world_construction_square: return RDF_Type::Class;
		case DF_Type::world_construction_square_bridgest: return RDF_Type::Class;
		case DF_Type::world_construction_square_roadst: return RDF_Type::Class;
		case DF_Type::world_construction_square_tunnelst: return RDF_Type::Class;
		case DF_Type::world_construction_square_wallst: return RDF_Type::Class;
		case DF_Type::world_construction_tunnelst: return RDF_Type::Class;
		case DF_Type::world_construction_type: return RDF_Type::Enum;
		case DF_Type::world_construction_wallst: return RDF_Type::Class;
		case DF_Type::world_dat_summary: return RDF_Type::Struct;
		case DF_Type::world_data: return RDF_Type::Struct;
		case DF_Type::world_data__T_constructions: return RDF_Type::Compound;
		case DF_Type::world_data__T_feature_map: return RDF_Type::Compound;
		case DF_Type::world_data__T_feature_map__T_features: return RDF_Type::Compound;
		case DF_Type::world_data__T_flip_latitude: return RDF_Type::Enum;
		case DF_Type::world_data__T_mountain_peaks: return RDF_Type::Compound;
		case DF_Type::world_data__T_unk_274: return RDF_Type::Compound;
		case DF_Type::world_data__T_unk_274__T_unk_10: return RDF_Type::Compound;
		case DF_Type::world_data__T_unk_482f8: return RDF_Type::Compound;
		case DF_Type::world_data__T_unk_b4: return RDF_Type::Compound;
		case DF_Type::world_gen_param_basest: return RDF_Type::Class;
		case DF_Type::world_gen_param_charst: return RDF_Type::Class;
		case DF_Type::world_gen_param_memberst: return RDF_Type::Class;
		case DF_Type::world_gen_param_seedst: return RDF_Type::Class;
		case DF_Type::world_gen_param_valuest: return RDF_Type::Class;
		case DF_Type::world_geo_biome: return RDF_Type::Struct;
		case DF_Type::world_geo_layer: return RDF_Type::Struct;
		case DF_Type::world_history: return RDF_Type::Struct;
		case DF_Type::world_history__T_event_collections: return RDF_Type::Compound;
		case DF_Type::world_history__T_intrigues: return RDF_Type::Compound;
		case DF_Type::world_history__T_intrigues__T_anon_1: return RDF_Type::Compound;
		case DF_Type::world_landmass: return RDF_Type::Struct;
		case DF_Type::world_object_data: return RDF_Type::Struct;
		case DF_Type::world_object_data__T_offloaded_buildings: return RDF_Type::Compound;
		case DF_Type::world_object_data__T_offloaded_items: return RDF_Type::Compound;
		case DF_Type::world_object_data__T_unk_94: return RDF_Type::Compound;
		case DF_Type::world_population: return RDF_Type::Struct;
		case DF_Type::world_population___union5: return RDF_Type::Union;
		case DF_Type::world_population_ref: return RDF_Type::Struct;
		case DF_Type::world_population_type: return RDF_Type::Enum;
		case DF_Type::world_raws: return RDF_Type::Struct;
		case DF_Type::world_raws__T_bodyglosses: return RDF_Type::Compound;
		case DF_Type::world_raws__T_buildings: return RDF_Type::Compound;
		case DF_Type::world_raws__T_descriptors: return RDF_Type::Compound;
		case DF_Type::world_raws__T_effects: return RDF_Type::Compound;
		case DF_Type::world_raws__T_itemdefs: return RDF_Type::Compound;
		case DF_Type::world_raws__T_language: return RDF_Type::Compound;
		case DF_Type::world_raws__T_plants: return RDF_Type::Compound;
		case DF_Type::world_raws__T_reactions: return RDF_Type::Compound;
		case DF_Type::world_raws__T_syndromes: return RDF_Type::Compound;
		case DF_Type::world_region: return RDF_Type::Struct;
		case DF_Type::world_region_details: return RDF_Type::Struct;
		case DF_Type::world_region_details__T_edges: return RDF_Type::Compound;
		case DF_Type::world_region_details__T_rivers_horizontal: return RDF_Type::Compound;
		case DF_Type::world_region_details__T_rivers_vertical: return RDF_Type::Compound;
		case DF_Type::world_region_feature: return RDF_Type::Struct;
		case DF_Type::world_region_type: return RDF_Type::Enum;
		case DF_Type::world_river: return RDF_Type::Struct;
		case DF_Type::world_site: return RDF_Type::Struct;
		case DF_Type::world_site__T_subtype_info: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_118: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_13c: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_188: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_188__T_unk1: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_1: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_1__T_units: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_21c: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_v40_2: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_v40_4a: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_v40_4b: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_v40_4c: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_v40_4d: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_v40_4d__T_anon_1: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_v43_2: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_v47_1: return RDF_Type::Compound;
		case DF_Type::world_site__T_unk_v47_1__T_unk_1: return RDF_Type::Compound;
		case DF_Type::world_site_flags: return RDF_Type::Enum;
		case DF_Type::world_site_inhabitant: return RDF_Type::Struct;
		case DF_Type::world_site_realization: return RDF_Type::Struct;
		case DF_Type::world_site_realization__T_areas: return RDF_Type::Compound;
		case DF_Type::world_site_realization__T_areas__T_type: return RDF_Type::Enum;
		case DF_Type::world_site_realization__T_building_map: return RDF_Type::Compound;
		case DF_Type::world_site_realization__T_river_map: return RDF_Type::Compound;
		case DF_Type::world_site_realization__T_unk_193bc: return RDF_Type::Compound;
		case DF_Type::world_site_realization__T_unk_193bc__T_unk_8: return RDF_Type::Compound;
		case DF_Type::world_site_realization__T_unk_55e8: return RDF_Type::Compound;
		case DF_Type::world_site_realization__T_unk_55e8__T_unk_v40_2: return RDF_Type::Compound;
		case DF_Type::world_site_type: return RDF_Type::Enum;
		case DF_Type::world_site_unk130: return RDF_Type::Struct;
		case DF_Type::world_site_unk130__T_unk_4: return RDF_Type::Compound;
		case DF_Type::world_underground_region: return RDF_Type::Struct;
		case DF_Type::world_underground_region__T_type: return RDF_Type::Enum;
		case DF_Type::world_unk26c678_unk38: return RDF_Type::Struct;
		case DF_Type::world_unk_20: return RDF_Type::Struct;
		case DF_Type::world_unk_20__T_anon_7: return RDF_Type::Compound;
		case DF_Type::world_unk_6c: return RDF_Type::Struct;
		case DF_Type::world_unk_a8: return RDF_Type::Struct;
		case DF_Type::world_unk_b4: return RDF_Type::Struct;
		case DF_Type::world_unk_c0: return RDF_Type::Struct;
		case DF_Type::world_unk_c0__T_anon_7: return RDF_Type::Compound;
		case DF_Type::worldgen_range_type: return RDF_Type::Enum;
		case DF_Type::worldgen_region_type: return RDF_Type::Enum;
		case DF_Type::wound_curse_info: return RDF_Type::Struct;
		case DF_Type::wound_curse_info__T_timing: return RDF_Type::Compound;
		case DF_Type::wound_damage_flags1: return RDF_Type::Bitfield;
		case DF_Type::wound_damage_flags2: return RDF_Type::Bitfield;
		case DF_Type::wound_effect_type: return RDF_Type::Enum;
		case DF_Type::written_content: return RDF_Type::Struct;
		case DF_Type::written_content_style: return RDF_Type::Enum;
		case DF_Type::written_content_type: return RDF_Type::Enum;
		case DF_Type::z_level_flags: return RDF_Type::Bitfield;
		case DF_Type::zoom_commands: return RDF_Type::Enum;
		default: break;
	}
	return RDF_Type::None;
}

