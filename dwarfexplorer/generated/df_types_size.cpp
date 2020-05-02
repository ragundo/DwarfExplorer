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
#include <unordered_map>

namespace rdf
{
std::map<DF_Type,size_t> DF_types_size_table = 
{
	{ DF_Type::abstract_building, sizeof(df::abstract_building) },
	{ DF_Type::abstract_building__T_inhabitants, sizeof(df::abstract_building::T_inhabitants) },
	{ DF_Type::abstract_building__T_unk1, sizeof(df::abstract_building::T_unk1) },
	{ DF_Type::abstract_building_contents, sizeof(df::abstract_building_contents) },
	{ DF_Type::abstract_building_counting_housest, sizeof(df::abstract_building_counting_housest) },
	{ DF_Type::abstract_building_dark_towerst, sizeof(df::abstract_building_dark_towerst) },
	{ DF_Type::abstract_building_dungeonst, sizeof(df::abstract_building_dungeonst) },
	{ DF_Type::abstract_building_dungeonst__T_dungeon_type, sizeof(df::abstract_building_dungeonst::T_dungeon_type) },
	{ DF_Type::abstract_building_flags, sizeof(df::enums::abstract_building_flags::abstract_building_flags) },
	{ DF_Type::abstract_building_guildhallst, sizeof(df::abstract_building_guildhallst) },
	{ DF_Type::abstract_building_inn_tavernst, sizeof(df::abstract_building_inn_tavernst) },
	{ DF_Type::abstract_building_inn_tavernst__T_room_info, sizeof(df::abstract_building_inn_tavernst::T_room_info) },
	{ DF_Type::abstract_building_keepst, sizeof(df::abstract_building_keepst) },
	{ DF_Type::abstract_building_libraryst, sizeof(df::abstract_building_libraryst) },
	{ DF_Type::abstract_building_marketst, sizeof(df::abstract_building_marketst) },
	{ DF_Type::abstract_building_mead_hallst, sizeof(df::abstract_building_mead_hallst) },
	{ DF_Type::abstract_building_templest, sizeof(df::abstract_building_templest) },
	{ DF_Type::abstract_building_tombst, sizeof(df::abstract_building_tombst) },
	{ DF_Type::abstract_building_towerst, sizeof(df::abstract_building_towerst) },
	{ DF_Type::abstract_building_type, sizeof(df::enums::abstract_building_type::abstract_building_type) },
	{ DF_Type::abstract_building_underworld_spirest, sizeof(df::abstract_building_underworld_spirest) },
	{ DF_Type::abstract_building_unk, sizeof(df::abstract_building_unk) },
	{ DF_Type::abstract_building_unk__T_anon_1, sizeof(df::abstract_building_unk::T_anon_1) },
	{ DF_Type::active_script_var_longst, sizeof(df::active_script_var_longst) },
	{ DF_Type::active_script_var_unitst, sizeof(df::active_script_var_unitst) },
	{ DF_Type::active_script_varst, sizeof(df::active_script_varst) },
	{ DF_Type::activity_entry, sizeof(df::activity_entry) },
	{ DF_Type::activity_entry_type, sizeof(df::enums::activity_entry_type::activity_entry_type) },
	{ DF_Type::activity_event, sizeof(df::activity_event) },
	{ DF_Type::activity_event__T_flags, sizeof(df::activity_event::T_flags) },
	{ DF_Type::activity_event__T_unk_v42_1, sizeof(df::activity_event::T_unk_v42_1) },
	{ DF_Type::activity_event__T_unk_v42_2, sizeof(df::activity_event::T_unk_v42_2) },
	{ DF_Type::activity_event_combat_trainingst, sizeof(df::activity_event_combat_trainingst) },
	{ DF_Type::activity_event_conflictst, sizeof(df::activity_event_conflictst) },
	{ DF_Type::activity_event_conflictst__T_sides, sizeof(df::activity_event_conflictst::T_sides) },
	{ DF_Type::activity_event_conflictst__T_sides__T_enemies, sizeof(df::activity_event_conflictst::T_sides::T_enemies) },
	{ DF_Type::activity_event_conversationst, sizeof(df::activity_event_conversationst) },
	{ DF_Type::activity_event_conversationst__T_anon_6, sizeof(df::activity_event_conversationst::T_anon_6) },
	{ DF_Type::activity_event_conversationst__T_flags2, sizeof(df::activity_event_conversationst::T_flags2) },
	{ DF_Type::activity_event_conversationst__T_participants, sizeof(df::activity_event_conversationst::T_participants) },
	{ DF_Type::activity_event_conversationst__T_turns, sizeof(df::activity_event_conversationst::T_turns) },
	{ DF_Type::activity_event_conversationst__T_unk2, sizeof(df::activity_event_conversationst::T_unk2) },
	{ DF_Type::activity_event_conversationst__T_unk_b4, sizeof(df::activity_event_conversationst::T_unk_b4) },
	{ DF_Type::activity_event_copy_written_contentst, sizeof(df::activity_event_copy_written_contentst) },
	{ DF_Type::activity_event_copy_written_contentst__T_flagsmaybe, sizeof(df::activity_event_copy_written_contentst::T_flagsmaybe) },
	{ DF_Type::activity_event_discuss_topicst, sizeof(df::activity_event_discuss_topicst) },
	{ DF_Type::activity_event_encounterst, sizeof(df::activity_event_encounterst) },
	{ DF_Type::activity_event_encounterst__T_anon_1, sizeof(df::activity_event_encounterst::T_anon_1) },
	{ DF_Type::activity_event_encounterst__T_anon_2, sizeof(df::activity_event_encounterst::T_anon_2) },
	{ DF_Type::activity_event_fill_service_orderst, sizeof(df::activity_event_fill_service_orderst) },
	{ DF_Type::activity_event_guardst, sizeof(df::activity_event_guardst) },
	{ DF_Type::activity_event_harassmentst, sizeof(df::activity_event_harassmentst) },
	{ DF_Type::activity_event_harassmentst__T_anon_2, sizeof(df::activity_event_harassmentst::T_anon_2) },
	{ DF_Type::activity_event_individual_skill_drillst, sizeof(df::activity_event_individual_skill_drillst) },
	{ DF_Type::activity_event_make_believest, sizeof(df::activity_event_make_believest) },
	{ DF_Type::activity_event_participants, sizeof(df::activity_event_participants) },
	{ DF_Type::activity_event_performancest, sizeof(df::activity_event_performancest) },
	{ DF_Type::activity_event_performancest__T_participant_actions, sizeof(df::activity_event_performancest::T_participant_actions) },
	{ DF_Type::activity_event_play_with_toyst, sizeof(df::activity_event_play_with_toyst) },
	{ DF_Type::activity_event_play_with_toyst__T_unk, sizeof(df::activity_event_play_with_toyst::T_unk) },
	{ DF_Type::activity_event_playst, sizeof(df::activity_event_playst) },
	{ DF_Type::activity_event_ponder_topicst, sizeof(df::activity_event_ponder_topicst) },
	{ DF_Type::activity_event_prayerst, sizeof(df::activity_event_prayerst) },
	{ DF_Type::activity_event_ranged_practicest, sizeof(df::activity_event_ranged_practicest) },
	{ DF_Type::activity_event_readst, sizeof(df::activity_event_readst) },
	{ DF_Type::activity_event_researchst, sizeof(df::activity_event_researchst) },
	{ DF_Type::activity_event_reunionst, sizeof(df::activity_event_reunionst) },
	{ DF_Type::activity_event_skill_demonstrationst, sizeof(df::activity_event_skill_demonstrationst) },
	{ DF_Type::activity_event_socializest, sizeof(df::activity_event_socializest) },
	{ DF_Type::activity_event_sparringst, sizeof(df::activity_event_sparringst) },
	{ DF_Type::activity_event_sparringst__T_groups, sizeof(df::activity_event_sparringst::T_groups) },
	{ DF_Type::activity_event_store_objectst, sizeof(df::activity_event_store_objectst) },
	{ DF_Type::activity_event_teach_topicst, sizeof(df::activity_event_teach_topicst) },
	{ DF_Type::activity_event_training_sessionst, sizeof(df::activity_event_training_sessionst) },
	{ DF_Type::activity_event_type, sizeof(df::enums::activity_event_type::activity_event_type) },
	{ DF_Type::activity_event_worshipst, sizeof(df::activity_event_worshipst) },
	{ DF_Type::activity_event_writest, sizeof(df::activity_event_writest) },
	{ DF_Type::activity_info, sizeof(df::activity_info) },
	{ DF_Type::activity_info__T_flags, sizeof(df::activity_info::T_flags) },
	{ DF_Type::adventure_environment_ingest_from_containerst, sizeof(df::adventure_environment_ingest_from_containerst) },
	{ DF_Type::adventure_environment_ingest_materialst, sizeof(df::adventure_environment_ingest_materialst) },
	{ DF_Type::adventure_environment_optionst, sizeof(df::adventure_environment_optionst) },
	{ DF_Type::adventure_environment_pickup_chop_treest, sizeof(df::adventure_environment_pickup_chop_treest) },
	{ DF_Type::adventure_environment_pickup_ignite_vegst, sizeof(df::adventure_environment_pickup_ignite_vegst) },
	{ DF_Type::adventure_environment_pickup_make_campfirest, sizeof(df::adventure_environment_pickup_make_campfirest) },
	{ DF_Type::adventure_environment_pickup_vermin_eventst, sizeof(df::adventure_environment_pickup_vermin_eventst) },
	{ DF_Type::adventure_environment_place_in_bld_containerst, sizeof(df::adventure_environment_place_in_bld_containerst) },
	{ DF_Type::adventure_environment_place_in_it_containerst, sizeof(df::adventure_environment_place_in_it_containerst) },
	{ DF_Type::adventure_environment_unit_suck_bloodst, sizeof(df::adventure_environment_unit_suck_bloodst) },
	{ DF_Type::adventure_item_interact_choicest, sizeof(df::adventure_item_interact_choicest) },
	{ DF_Type::adventure_item_interact_fill_from_containerst, sizeof(df::adventure_item_interact_fill_from_containerst) },
	{ DF_Type::adventure_item_interact_fill_with_materialst, sizeof(df::adventure_item_interact_fill_with_materialst) },
	{ DF_Type::adventure_item_interact_give_namest, sizeof(df::adventure_item_interact_give_namest) },
	{ DF_Type::adventure_item_interact_heat_from_tilest, sizeof(df::adventure_item_interact_heat_from_tilest) },
	{ DF_Type::adventure_item_interact_pull_outst, sizeof(df::adventure_item_interact_pull_outst) },
	{ DF_Type::adventure_item_interact_readst, sizeof(df::adventure_item_interact_readst) },
	{ DF_Type::adventure_item_interact_strugglest, sizeof(df::adventure_item_interact_strugglest) },
	{ DF_Type::adventure_log_item, sizeof(df::adventure_log_item) },
	{ DF_Type::adventure_movement_attack_creaturest, sizeof(df::adventure_movement_attack_creaturest) },
	{ DF_Type::adventure_movement_building_interactst, sizeof(df::adventure_movement_building_interactst) },
	{ DF_Type::adventure_movement_climbst, sizeof(df::adventure_movement_climbst) },
	{ DF_Type::adventure_movement_hold_itemst, sizeof(df::adventure_movement_hold_itemst) },
	{ DF_Type::adventure_movement_hold_tilest, sizeof(df::adventure_movement_hold_tilest) },
	{ DF_Type::adventure_movement_item_interact_guidest, sizeof(df::adventure_movement_item_interact_guidest) },
	{ DF_Type::adventure_movement_item_interact_pushst, sizeof(df::adventure_movement_item_interact_pushst) },
	{ DF_Type::adventure_movement_item_interact_ridest, sizeof(df::adventure_movement_item_interact_ridest) },
	{ DF_Type::adventure_movement_item_interactst, sizeof(df::adventure_movement_item_interactst) },
	{ DF_Type::adventure_movement_movest, sizeof(df::adventure_movement_movest) },
	{ DF_Type::adventure_movement_optionst, sizeof(df::adventure_movement_optionst) },
	{ DF_Type::adventure_movement_release_hold_itemst, sizeof(df::adventure_movement_release_hold_itemst) },
	{ DF_Type::adventure_movement_release_hold_tilest, sizeof(df::adventure_movement_release_hold_tilest) },
	{ DF_Type::adventure_option_eat_item_contaminantst, sizeof(df::adventure_option_eat_item_contaminantst) },
	{ DF_Type::adventure_option_eat_unit_contaminantst, sizeof(df::adventure_option_eat_unit_contaminantst) },
	{ DF_Type::adventure_option_view_contaminantst, sizeof(df::adventure_option_view_contaminantst) },
	{ DF_Type::adventure_optionst, sizeof(df::adventure_optionst) },
	{ DF_Type::adventurer_attribute_level, sizeof(df::enums::adventurer_attribute_level::adventurer_attribute_level) },
	{ DF_Type::agreement, sizeof(df::agreement) },
	{ DF_Type::agreement__T_flags, sizeof(df::agreement::T_flags) },
	{ DF_Type::agreement_details, sizeof(df::agreement_details) },
	{ DF_Type::agreement_details__T_data, sizeof(df::agreement_details::T_data) },
	{ DF_Type::agreement_details_data_citizenship, sizeof(df::agreement_details_data_citizenship) },
	{ DF_Type::agreement_details_data_demonic_binding, sizeof(df::agreement_details_data_demonic_binding) },
	{ DF_Type::agreement_details_data_join_party, sizeof(df::agreement_details_data_join_party) },
	{ DF_Type::agreement_details_data_location, sizeof(df::agreement_details_data_location) },
	{ DF_Type::agreement_details_data_parley, sizeof(df::agreement_details_data_parley) },
	{ DF_Type::agreement_details_data_plot_abduct, sizeof(df::agreement_details_data_plot_abduct) },
	{ DF_Type::agreement_details_data_plot_assassination, sizeof(df::agreement_details_data_plot_assassination) },
	{ DF_Type::agreement_details_data_plot_conviction, sizeof(df::agreement_details_data_plot_conviction) },
	{ DF_Type::agreement_details_data_plot_frame_treason, sizeof(df::agreement_details_data_plot_frame_treason) },
	{ DF_Type::agreement_details_data_plot_induce_war, sizeof(df::agreement_details_data_plot_induce_war) },
	{ DF_Type::agreement_details_data_plot_infiltration_coup, sizeof(df::agreement_details_data_plot_infiltration_coup) },
	{ DF_Type::agreement_details_data_plot_sabotage, sizeof(df::agreement_details_data_plot_sabotage) },
	{ DF_Type::agreement_details_data_plot_steal_artifact, sizeof(df::agreement_details_data_plot_steal_artifact) },
	{ DF_Type::agreement_details_data_position_corruption, sizeof(df::agreement_details_data_position_corruption) },
	{ DF_Type::agreement_details_data_promise_position, sizeof(df::agreement_details_data_promise_position) },
	{ DF_Type::agreement_details_data_residency, sizeof(df::agreement_details_data_residency) },
	{ DF_Type::agreement_details_type, sizeof(df::enums::agreement_details_type::agreement_details_type) },
	{ DF_Type::agreement_party, sizeof(df::agreement_party) },
	{ DF_Type::agreement_party__T_anon_1, sizeof(df::agreement_party::T_anon_1) },
	{ DF_Type::ammo_flags, sizeof(df::enums::ammo_flags::ammo_flags) },
	{ DF_Type::animal_training_level, sizeof(df::enums::animal_training_level::animal_training_level) },
	{ DF_Type::announcement_flags, sizeof(df::announcement_flags) },
	{ DF_Type::announcement_type, sizeof(df::enums::announcement_type::announcement_type) },
	{ DF_Type::announcements, sizeof(df::announcements) },
	{ DF_Type::appearance_modifier_growth_interval, sizeof(df::enums::appearance_modifier_growth_interval::appearance_modifier_growth_interval) },
	{ DF_Type::appearance_modifier_type, sizeof(df::enums::appearance_modifier_type::appearance_modifier_type) },
	{ DF_Type::architectural_element, sizeof(df::enums::architectural_element::architectural_element) },
	{ DF_Type::armor_flags, sizeof(df::enums::armor_flags::armor_flags) },
	{ DF_Type::armor_general_flags, sizeof(df::enums::armor_general_flags::armor_general_flags) },
	{ DF_Type::armor_properties, sizeof(df::armor_properties) },
	{ DF_Type::army, sizeof(df::army) },
	{ DF_Type::army__T_members, sizeof(df::army::T_members) },
	{ DF_Type::army__T_unk_2c, sizeof(df::army::T_unk_2c) },
	{ DF_Type::army_controller, sizeof(df::army_controller) },
	{ DF_Type::army_controller__T_type, sizeof(df::army_controller::T_type) },
	{ DF_Type::army_controller__T_unk_64, sizeof(df::army_controller::T_unk_64) },
	{ DF_Type::army_controller_invasion, sizeof(df::army_controller_invasion) },
	{ DF_Type::army_controller_invasion__T_anon_1, sizeof(df::army_controller_invasion::T_anon_1) },
	{ DF_Type::army_controller_sub1, sizeof(df::army_controller_sub1) },
	{ DF_Type::army_controller_sub11, sizeof(df::army_controller_sub11) },
	{ DF_Type::army_controller_sub11__T_anon_3, sizeof(df::army_controller_sub11::T_anon_3) },
	{ DF_Type::army_controller_sub12, sizeof(df::army_controller_sub12) },
	{ DF_Type::army_controller_sub12__T_unk_4, sizeof(df::army_controller_sub12::T_unk_4) },
	{ DF_Type::army_controller_sub13, sizeof(df::army_controller_sub13) },
	{ DF_Type::army_controller_sub13__T_anon_4, sizeof(df::army_controller_sub13::T_anon_4) },
	{ DF_Type::army_controller_sub14, sizeof(df::army_controller_sub14) },
	{ DF_Type::army_controller_sub14__T_anon_4, sizeof(df::army_controller_sub14::T_anon_4) },
	{ DF_Type::army_controller_sub15, sizeof(df::army_controller_sub15) },
	{ DF_Type::army_controller_sub15__T_anon_3, sizeof(df::army_controller_sub15::T_anon_3) },
	{ DF_Type::army_controller_sub16, sizeof(df::army_controller_sub16) },
	{ DF_Type::army_controller_sub17, sizeof(df::army_controller_sub17) },
	{ DF_Type::army_controller_sub18, sizeof(df::army_controller_sub18) },
	{ DF_Type::army_controller_sub4, sizeof(df::army_controller_sub4) },
	{ DF_Type::army_controller_sub4__T_unk_2, sizeof(df::army_controller_sub4::T_unk_2) },
	{ DF_Type::army_controller_sub5, sizeof(df::army_controller_sub5) },
	{ DF_Type::army_controller_sub6, sizeof(df::army_controller_sub6) },
	{ DF_Type::army_controller_sub7, sizeof(df::army_controller_sub7) },
	{ DF_Type::army_controller_sub7__T_anon_3, sizeof(df::army_controller_sub7::T_anon_3) },
	{ DF_Type::army_controller_villain_visiting, sizeof(df::army_controller_villain_visiting) },
	{ DF_Type::army_flags, sizeof(df::enums::army_flags::army_flags) },
	{ DF_Type::art_facet_type, sizeof(df::enums::art_facet_type::art_facet_type) },
	{ DF_Type::art_image, sizeof(df::art_image) },
	{ DF_Type::art_image_chunk, sizeof(df::art_image_chunk) },
	{ DF_Type::art_image_element, sizeof(df::art_image_element) },
	{ DF_Type::art_image_element_creaturest, sizeof(df::art_image_element_creaturest) },
	{ DF_Type::art_image_element_itemst, sizeof(df::art_image_element_itemst) },
	{ DF_Type::art_image_element_plantst, sizeof(df::art_image_element_plantst) },
	{ DF_Type::art_image_element_shapest, sizeof(df::art_image_element_shapest) },
	{ DF_Type::art_image_element_treest, sizeof(df::art_image_element_treest) },
	{ DF_Type::art_image_element_type, sizeof(df::enums::art_image_element_type::art_image_element_type) },
	{ DF_Type::art_image_property, sizeof(df::art_image_property) },
	{ DF_Type::art_image_property_intransitive_verbst, sizeof(df::art_image_property_intransitive_verbst) },
	{ DF_Type::art_image_property_transitive_verbst, sizeof(df::art_image_property_transitive_verbst) },
	{ DF_Type::art_image_property_type, sizeof(df::enums::art_image_property_type::art_image_property_type) },
	{ DF_Type::art_image_property_verb, sizeof(df::enums::art_image_property_verb::art_image_property_verb) },
	{ DF_Type::art_image_ref, sizeof(df::art_image_ref) },
	{ DF_Type::artifact_claim, sizeof(df::artifact_claim) },
	{ DF_Type::artifact_claim_type, sizeof(df::enums::artifact_claim_type::artifact_claim_type) },
	{ DF_Type::artifact_record, sizeof(df::artifact_record) },
	{ DF_Type::assign_trade_status, sizeof(df::assign_trade_status) },
	{ DF_Type::assign_trade_status__T_status, sizeof(df::assign_trade_status::T_status) },
	{ DF_Type::assume_identity_mode, sizeof(df::enums::assume_identity_mode::assume_identity_mode) },
	{ DF_Type::barrack_preference_category, sizeof(df::enums::barrack_preference_category::barrack_preference_category) },
	{ DF_Type::battlefield, sizeof(df::battlefield) },
	{ DF_Type::battlefield__T_sapient_deaths, sizeof(df::battlefield::T_sapient_deaths) },
	{ DF_Type::belief_system, sizeof(df::belief_system) },
	{ DF_Type::biome_type, sizeof(df::enums::biome_type::biome_type) },
	{ DF_Type::block_burrow, sizeof(df::block_burrow) },
	{ DF_Type::block_burrow_link, sizeof(df::block_burrow_link) },
	{ DF_Type::block_flags, sizeof(df::block_flags) },
	{ DF_Type::block_square_event, sizeof(df::block_square_event) },
	{ DF_Type::block_square_event_designation_priorityst, sizeof(df::block_square_event_designation_priorityst) },
	{ DF_Type::block_square_event_frozen_liquidst, sizeof(df::block_square_event_frozen_liquidst) },
	{ DF_Type::block_square_event_grassst, sizeof(df::block_square_event_grassst) },
	{ DF_Type::block_square_event_item_spatterst, sizeof(df::block_square_event_item_spatterst) },
	{ DF_Type::block_square_event_material_spatterst, sizeof(df::block_square_event_material_spatterst) },
	{ DF_Type::block_square_event_mineralst, sizeof(df::block_square_event_mineralst) },
	{ DF_Type::block_square_event_mineralst__T_flags, sizeof(df::block_square_event_mineralst::T_flags) },
	{ DF_Type::block_square_event_spoorst, sizeof(df::block_square_event_spoorst) },
	{ DF_Type::block_square_event_type, sizeof(df::enums::block_square_event_type::block_square_event_type) },
	{ DF_Type::block_square_event_world_constructionst, sizeof(df::block_square_event_world_constructionst) },
	{ DF_Type::body_appearance_modifier, sizeof(df::body_appearance_modifier) },
	{ DF_Type::body_component_info, sizeof(df::body_component_info) },
	{ DF_Type::body_detail_plan, sizeof(df::body_detail_plan) },
	{ DF_Type::body_layer_status, sizeof(df::body_layer_status) },
	{ DF_Type::body_part_layer_flags, sizeof(df::enums::body_part_layer_flags::body_part_layer_flags) },
	{ DF_Type::body_part_layer_raw, sizeof(df::body_part_layer_raw) },
	{ DF_Type::body_part_raw, sizeof(df::body_part_raw) },
	{ DF_Type::body_part_raw_flags, sizeof(df::enums::body_part_raw_flags::body_part_raw_flags) },
	{ DF_Type::body_part_status, sizeof(df::body_part_status) },
	{ DF_Type::body_part_template, sizeof(df::body_part_template) },
	{ DF_Type::body_part_template_contype, sizeof(df::enums::body_part_template_contype::body_part_template_contype) },
	{ DF_Type::body_part_template_flags, sizeof(df::enums::body_part_template_flags::body_part_template_flags) },
	{ DF_Type::body_size_info, sizeof(df::body_size_info) },
	{ DF_Type::body_template, sizeof(df::body_template) },
	{ DF_Type::bp_appearance_modifier, sizeof(df::bp_appearance_modifier) },
	{ DF_Type::breath_attack_type, sizeof(df::enums::breath_attack_type::breath_attack_type) },
	{ DF_Type::breed, sizeof(df::breed) },
	{ DF_Type::breed__T_unk_18, sizeof(df::breed::T_unk_18) },
	{ DF_Type::breed__T_unk_28, sizeof(df::breed::T_unk_28) },
	{ DF_Type::breed__T_unk_8, sizeof(df::breed::T_unk_8) },
	{ DF_Type::build_req_choice_genst, sizeof(df::build_req_choice_genst) },
	{ DF_Type::build_req_choice_specst, sizeof(df::build_req_choice_specst) },
	{ DF_Type::build_req_choice_type, sizeof(df::enums::build_req_choice_type::build_req_choice_type) },
	{ DF_Type::build_req_choicest, sizeof(df::build_req_choicest) },
	{ DF_Type::building, sizeof(df::building) },
	{ DF_Type::building__T_activities, sizeof(df::building::T_activities) },
	{ DF_Type::building__T_job_claim_suppress, sizeof(df::building::T_job_claim_suppress) },
	{ DF_Type::building_actual, sizeof(df::building_actual) },
	{ DF_Type::building_actual__T_contained_items, sizeof(df::building_actual::T_contained_items) },
	{ DF_Type::building_animaltrapst, sizeof(df::building_animaltrapst) },
	{ DF_Type::building_archerytargetst, sizeof(df::building_archerytargetst) },
	{ DF_Type::building_archerytargetst__T_archery_direction, sizeof(df::building_archerytargetst::T_archery_direction) },
	{ DF_Type::building_armorstandst, sizeof(df::building_armorstandst) },
	{ DF_Type::building_axle_horizontalst, sizeof(df::building_axle_horizontalst) },
	{ DF_Type::building_axle_verticalst, sizeof(df::building_axle_verticalst) },
	{ DF_Type::building_bars_floorst, sizeof(df::building_bars_floorst) },
	{ DF_Type::building_bars_verticalst, sizeof(df::building_bars_verticalst) },
	{ DF_Type::building_bedst, sizeof(df::building_bedst) },
	{ DF_Type::building_bedst__T_bed_flags, sizeof(df::building_bedst::T_bed_flags) },
	{ DF_Type::building_bookcasest, sizeof(df::building_bookcasest) },
	{ DF_Type::building_boxst, sizeof(df::building_boxst) },
	{ DF_Type::building_bridgest, sizeof(df::building_bridgest) },
	{ DF_Type::building_bridgest__T_direction, sizeof(df::building_bridgest::T_direction) },
	{ DF_Type::building_cabinetst, sizeof(df::building_cabinetst) },
	{ DF_Type::building_cagest, sizeof(df::building_cagest) },
	{ DF_Type::building_cagest__T_cage_flags, sizeof(df::building_cagest::T_cage_flags) },
	{ DF_Type::building_chainst, sizeof(df::building_chainst) },
	{ DF_Type::building_chainst__T_chain_flags, sizeof(df::building_chainst::T_chain_flags) },
	{ DF_Type::building_chairst, sizeof(df::building_chairst) },
	{ DF_Type::building_civzonest, sizeof(df::building_civzonest) },
	{ DF_Type::building_civzonest__T_gather_flags, sizeof(df::building_civzonest::T_gather_flags) },
	{ DF_Type::building_civzonest__T_pit_flags, sizeof(df::building_civzonest::T_pit_flags) },
	{ DF_Type::building_civzonest__T_zone_flags, sizeof(df::building_civzonest::T_zone_flags) },
	{ DF_Type::building_coffinst, sizeof(df::building_coffinst) },
	{ DF_Type::building_coffinst__T_burial_mode, sizeof(df::building_coffinst::T_burial_mode) },
	{ DF_Type::building_constructionst, sizeof(df::building_constructionst) },
	{ DF_Type::building_def, sizeof(df::building_def) },
	{ DF_Type::building_def_furnacest, sizeof(df::building_def_furnacest) },
	{ DF_Type::building_def_item, sizeof(df::building_def_item) },
	{ DF_Type::building_def_workshopst, sizeof(df::building_def_workshopst) },
	{ DF_Type::building_design, sizeof(df::building_design) },
	{ DF_Type::building_design__T_flags, sizeof(df::building_design::T_flags) },
	{ DF_Type::building_display_furniturest, sizeof(df::building_display_furniturest) },
	{ DF_Type::building_doorst, sizeof(df::building_doorst) },
	{ DF_Type::building_drawbuffer, sizeof(df::building_drawbuffer) },
	{ DF_Type::building_extents, sizeof(df::building_extents) },
	{ DF_Type::building_farmplotst, sizeof(df::building_farmplotst) },
	{ DF_Type::building_flags, sizeof(df::building_flags) },
	{ DF_Type::building_floodgatest, sizeof(df::building_floodgatest) },
	{ DF_Type::building_furnacest, sizeof(df::building_furnacest) },
	{ DF_Type::building_gear_assemblyst, sizeof(df::building_gear_assemblyst) },
	{ DF_Type::building_gear_assemblyst__T_gear_flags, sizeof(df::building_gear_assemblyst::T_gear_flags) },
	{ DF_Type::building_grate_floorst, sizeof(df::building_grate_floorst) },
	{ DF_Type::building_grate_wallst, sizeof(df::building_grate_wallst) },
	{ DF_Type::building_handler, sizeof(df::building_handler) },
	{ DF_Type::building_hatchst, sizeof(df::building_hatchst) },
	{ DF_Type::building_hivest, sizeof(df::building_hivest) },
	{ DF_Type::building_instrumentst, sizeof(df::building_instrumentst) },
	{ DF_Type::building_nest_boxst, sizeof(df::building_nest_boxst) },
	{ DF_Type::building_nestst, sizeof(df::building_nestst) },
	{ DF_Type::building_offering_placest, sizeof(df::building_offering_placest) },
	{ DF_Type::building_road_dirtst, sizeof(df::building_road_dirtst) },
	{ DF_Type::building_road_pavedst, sizeof(df::building_road_pavedst) },
	{ DF_Type::building_roadst, sizeof(df::building_roadst) },
	{ DF_Type::building_rollersst, sizeof(df::building_rollersst) },
	{ DF_Type::building_screw_pumpst, sizeof(df::building_screw_pumpst) },
	{ DF_Type::building_shopst, sizeof(df::building_shopst) },
	{ DF_Type::building_shopst__T_shop_flags, sizeof(df::building_shopst::T_shop_flags) },
	{ DF_Type::building_siegeenginest, sizeof(df::building_siegeenginest) },
	{ DF_Type::building_siegeenginest__T_action, sizeof(df::building_siegeenginest::T_action) },
	{ DF_Type::building_siegeenginest__T_facing, sizeof(df::building_siegeenginest::T_facing) },
	{ DF_Type::building_slabst, sizeof(df::building_slabst) },
	{ DF_Type::building_squad_use, sizeof(df::building_squad_use) },
	{ DF_Type::building_statuest, sizeof(df::building_statuest) },
	{ DF_Type::building_stockpilest, sizeof(df::building_stockpilest) },
	{ DF_Type::building_supportst, sizeof(df::building_supportst) },
	{ DF_Type::building_supportst__T_support_flags, sizeof(df::building_supportst::T_support_flags) },
	{ DF_Type::building_tablest, sizeof(df::building_tablest) },
	{ DF_Type::building_tablest__T_table_flags, sizeof(df::building_tablest::T_table_flags) },
	{ DF_Type::building_traction_benchst, sizeof(df::building_traction_benchst) },
	{ DF_Type::building_tradedepotst, sizeof(df::building_tradedepotst) },
	{ DF_Type::building_tradedepotst__T_trade_flags, sizeof(df::building_tradedepotst::T_trade_flags) },
	{ DF_Type::building_trapst, sizeof(df::building_trapst) },
	{ DF_Type::building_trapst__T_stop_flags, sizeof(df::building_trapst::T_stop_flags) },
	{ DF_Type::building_type, sizeof(df::enums::building_type::building_type) },
	{ DF_Type::building_users, sizeof(df::building_users) },
	{ DF_Type::building_wagonst, sizeof(df::building_wagonst) },
	{ DF_Type::building_water_wheelst, sizeof(df::building_water_wheelst) },
	{ DF_Type::building_weaponrackst, sizeof(df::building_weaponrackst) },
	{ DF_Type::building_weaponst, sizeof(df::building_weaponst) },
	{ DF_Type::building_wellst, sizeof(df::building_wellst) },
	{ DF_Type::building_wellst__T_well_flags, sizeof(df::building_wellst::T_well_flags) },
	{ DF_Type::building_windmillst, sizeof(df::building_windmillst) },
	{ DF_Type::building_window_gemst, sizeof(df::building_window_gemst) },
	{ DF_Type::building_window_glassst, sizeof(df::building_window_glassst) },
	{ DF_Type::building_windowst, sizeof(df::building_windowst) },
	{ DF_Type::building_workshopst, sizeof(df::building_workshopst) },
	{ DF_Type::buildings_other_id, sizeof(df::enums::buildings_other_id::buildings_other_id) },
	{ DF_Type::builtin_mats, sizeof(df::enums::builtin_mats::builtin_mats) },
	{ DF_Type::burrow, sizeof(df::burrow) },
	{ DF_Type::campfire, sizeof(df::campfire) },
	{ DF_Type::caravan_state, sizeof(df::caravan_state) },
	{ DF_Type::caravan_state__T_flags, sizeof(df::caravan_state::T_flags) },
	{ DF_Type::caravan_state__T_trade_state, sizeof(df::caravan_state::T_trade_state) },
	{ DF_Type::caste_attack, sizeof(df::caste_attack) },
	{ DF_Type::caste_attack__T_flags, sizeof(df::caste_attack::T_flags) },
	{ DF_Type::caste_body_info, sizeof(df::caste_body_info) },
	{ DF_Type::caste_body_info__T_extra_butcher_objects, sizeof(df::caste_body_info::T_extra_butcher_objects) },
	{ DF_Type::caste_body_info__T_flags, sizeof(df::caste_body_info::T_flags) },
	{ DF_Type::caste_body_info__T_interactions, sizeof(df::caste_body_info::T_interactions) },
	{ DF_Type::caste_body_info__T_interactions__T_type, sizeof(df::caste_body_info::T_interactions::T_type) },
	{ DF_Type::caste_clothing_item, sizeof(df::caste_clothing_item) },
	{ DF_Type::caste_raw, sizeof(df::caste_raw) },
	{ DF_Type::caste_raw__T_anon_1, sizeof(df::caste_raw::T_anon_1) },
	{ DF_Type::caste_raw__T_attributes, sizeof(df::caste_raw::T_attributes) },
	{ DF_Type::caste_raw__T_bp_appearance, sizeof(df::caste_raw::T_bp_appearance) },
	{ DF_Type::caste_raw__T_caste_profession_name, sizeof(df::caste_raw::T_caste_profession_name) },
	{ DF_Type::caste_raw__T_extracts, sizeof(df::caste_raw::T_extracts) },
	{ DF_Type::caste_raw__T_lair_hunter_speech, sizeof(df::caste_raw::T_lair_hunter_speech) },
	{ DF_Type::caste_raw__T_misc, sizeof(df::caste_raw::T_misc) },
	{ DF_Type::caste_raw__T_personality, sizeof(df::caste_raw::T_personality) },
	{ DF_Type::caste_raw__T_secretion, sizeof(df::caste_raw::T_secretion) },
	{ DF_Type::caste_raw__T_shearable_tissue_layer, sizeof(df::caste_raw::T_shearable_tissue_layer) },
	{ DF_Type::caste_raw__T_sound, sizeof(df::caste_raw::T_sound) },
	{ DF_Type::caste_raw__T_unk29, sizeof(df::caste_raw::T_unk29) },
	{ DF_Type::caste_raw__T_unknown2, sizeof(df::caste_raw::T_unknown2) },
	{ DF_Type::caste_raw_flags, sizeof(df::enums::caste_raw_flags::caste_raw_flags) },
	{ DF_Type::cave_column, sizeof(df::cave_column) },
	{ DF_Type::cave_column_link, sizeof(df::cave_column_link) },
	{ DF_Type::cave_column_rectangle, sizeof(df::cave_column_rectangle) },
	{ DF_Type::cie_add_tag_mask1, sizeof(df::cie_add_tag_mask1) },
	{ DF_Type::cie_add_tag_mask2, sizeof(df::cie_add_tag_mask2) },
	{ DF_Type::civzone_type, sizeof(df::enums::civzone_type::civzone_type) },
	{ DF_Type::coin_batch, sizeof(df::coin_batch) },
	{ DF_Type::coin_batch__T_image_back, sizeof(df::coin_batch::T_image_back) },
	{ DF_Type::coin_batch__T_image_front, sizeof(df::coin_batch::T_image_front) },
	{ DF_Type::color_modifier_raw, sizeof(df::color_modifier_raw) },
	{ DF_Type::combat_report_event_type, sizeof(df::enums::combat_report_event_type::combat_report_event_type) },
	{ DF_Type::conflict_level, sizeof(df::enums::conflict_level::conflict_level) },
	{ DF_Type::construction, sizeof(df::construction) },
	{ DF_Type::construction_flags, sizeof(df::construction_flags) },
	{ DF_Type::construction_type, sizeof(df::enums::construction_type::construction_type) },
	{ DF_Type::conversation, sizeof(df::conversation) },
	{ DF_Type::conversation__T_speech, sizeof(df::conversation::T_speech) },
	{ DF_Type::conversation__T_state, sizeof(df::conversation::T_state) },
	{ DF_Type::conversation_menu, sizeof(df::enums::conversation_menu::conversation_menu) },
	{ DF_Type::coord, sizeof(df::coord) },
	{ DF_Type::coord2d, sizeof(df::coord2d) },
	{ DF_Type::coord2d_path, sizeof(df::coord2d_path) },
	{ DF_Type::coord_path, sizeof(df::coord_path) },
	{ DF_Type::coord_rect, sizeof(df::coord_rect) },
	{ DF_Type::corpse_material_type, sizeof(df::enums::corpse_material_type::corpse_material_type) },
	{ DF_Type::craft_material_class, sizeof(df::enums::craft_material_class::craft_material_class) },
	{ DF_Type::creation_zone_pwg_alteration_campst, sizeof(df::creation_zone_pwg_alteration_campst) },
	{ DF_Type::creation_zone_pwg_alteration_location_deathst, sizeof(df::creation_zone_pwg_alteration_location_deathst) },
	{ DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1, sizeof(df::creation_zone_pwg_alteration_location_deathst::T_unk_1) },
	{ DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1, sizeof(df::creation_zone_pwg_alteration_location_deathst::T_unk_1::T_anon_1) },
	{ DF_Type::creation_zone_pwg_alteration_srb_ruinedst, sizeof(df::creation_zone_pwg_alteration_srb_ruinedst) },
	{ DF_Type::creation_zone_pwg_alteration_srp_ruinedst, sizeof(df::creation_zone_pwg_alteration_srp_ruinedst) },
	{ DF_Type::creation_zone_pwg_alteration_type, sizeof(df::enums::creation_zone_pwg_alteration_type::creation_zone_pwg_alteration_type) },
	{ DF_Type::creation_zone_pwg_alterationst, sizeof(df::creation_zone_pwg_alterationst) },
	{ DF_Type::creature_graphics_appointment, sizeof(df::creature_graphics_appointment) },
	{ DF_Type::creature_graphics_role, sizeof(df::enums::creature_graphics_role::creature_graphics_role) },
	{ DF_Type::creature_handler, sizeof(df::creature_handler) },
	{ DF_Type::creature_interaction, sizeof(df::creature_interaction) },
	{ DF_Type::creature_interaction__T_flags, sizeof(df::creature_interaction::T_flags) },
	{ DF_Type::creature_interaction_effect, sizeof(df::creature_interaction_effect) },
	{ DF_Type::creature_interaction_effect__T_counter_trigger, sizeof(df::creature_interaction_effect::T_counter_trigger) },
	{ DF_Type::creature_interaction_effect_add_simple_flagst, sizeof(df::creature_interaction_effect_add_simple_flagst) },
	{ DF_Type::creature_interaction_effect_bleedingst, sizeof(df::creature_interaction_effect_bleedingst) },
	{ DF_Type::creature_interaction_effect_blistersst, sizeof(df::creature_interaction_effect_blistersst) },
	{ DF_Type::creature_interaction_effect_body_appearance_modifierst, sizeof(df::creature_interaction_effect_body_appearance_modifierst) },
	{ DF_Type::creature_interaction_effect_body_mat_interactionst, sizeof(df::creature_interaction_effect_body_mat_interactionst) },
	{ DF_Type::creature_interaction_effect_body_transformationst, sizeof(df::creature_interaction_effect_body_transformationst) },
	{ DF_Type::creature_interaction_effect_bp_appearance_modifierst, sizeof(df::creature_interaction_effect_bp_appearance_modifierst) },
	{ DF_Type::creature_interaction_effect_bruisingst, sizeof(df::creature_interaction_effect_bruisingst) },
	{ DF_Type::creature_interaction_effect_can_do_interactionst, sizeof(df::creature_interaction_effect_can_do_interactionst) },
	{ DF_Type::creature_interaction_effect_change_personalityst, sizeof(df::creature_interaction_effect_change_personalityst) },
	{ DF_Type::creature_interaction_effect_close_open_woundsst, sizeof(df::creature_interaction_effect_close_open_woundsst) },
	{ DF_Type::creature_interaction_effect_cough_bloodst, sizeof(df::creature_interaction_effect_cough_bloodst) },
	{ DF_Type::creature_interaction_effect_cure_infectionsst, sizeof(df::creature_interaction_effect_cure_infectionsst) },
	{ DF_Type::creature_interaction_effect_cure_infectionst, sizeof(df::creature_interaction_effect_cure_infectionst) },
	{ DF_Type::creature_interaction_effect_display_namest, sizeof(df::creature_interaction_effect_display_namest) },
	{ DF_Type::creature_interaction_effect_display_symbolst, sizeof(df::creature_interaction_effect_display_symbolst) },
	{ DF_Type::creature_interaction_effect_dizzinessst, sizeof(df::creature_interaction_effect_dizzinessst) },
	{ DF_Type::creature_interaction_effect_drowsinessst, sizeof(df::creature_interaction_effect_drowsinessst) },
	{ DF_Type::creature_interaction_effect_erratic_behaviorst, sizeof(df::creature_interaction_effect_erratic_behaviorst) },
	{ DF_Type::creature_interaction_effect_feel_emotionst, sizeof(df::creature_interaction_effect_feel_emotionst) },
	{ DF_Type::creature_interaction_effect_feverst, sizeof(df::creature_interaction_effect_feverst) },
	{ DF_Type::creature_interaction_effect_flags, sizeof(df::creature_interaction_effect_flags) },
	{ DF_Type::creature_interaction_effect_flash_symbolst, sizeof(df::creature_interaction_effect_flash_symbolst) },
	{ DF_Type::creature_interaction_effect_heal_nervesst, sizeof(df::creature_interaction_effect_heal_nervesst) },
	{ DF_Type::creature_interaction_effect_heal_tissuesst, sizeof(df::creature_interaction_effect_heal_tissuesst) },
	{ DF_Type::creature_interaction_effect_impair_functionst, sizeof(df::creature_interaction_effect_impair_functionst) },
	{ DF_Type::creature_interaction_effect_material_force_adjustst, sizeof(df::creature_interaction_effect_material_force_adjustst) },
	{ DF_Type::creature_interaction_effect_ment_att_changest, sizeof(df::creature_interaction_effect_ment_att_changest) },
	{ DF_Type::creature_interaction_effect_nauseast, sizeof(df::creature_interaction_effect_nauseast) },
	{ DF_Type::creature_interaction_effect_necrosisst, sizeof(df::creature_interaction_effect_necrosisst) },
	{ DF_Type::creature_interaction_effect_numbnessst, sizeof(df::creature_interaction_effect_numbnessst) },
	{ DF_Type::creature_interaction_effect_oozingst, sizeof(df::creature_interaction_effect_oozingst) },
	{ DF_Type::creature_interaction_effect_painst, sizeof(df::creature_interaction_effect_painst) },
	{ DF_Type::creature_interaction_effect_paralysisst, sizeof(df::creature_interaction_effect_paralysisst) },
	{ DF_Type::creature_interaction_effect_phys_att_changest, sizeof(df::creature_interaction_effect_phys_att_changest) },
	{ DF_Type::creature_interaction_effect_reduce_dizzinessst, sizeof(df::creature_interaction_effect_reduce_dizzinessst) },
	{ DF_Type::creature_interaction_effect_reduce_feverst, sizeof(df::creature_interaction_effect_reduce_feverst) },
	{ DF_Type::creature_interaction_effect_reduce_nauseast, sizeof(df::creature_interaction_effect_reduce_nauseast) },
	{ DF_Type::creature_interaction_effect_reduce_painst, sizeof(df::creature_interaction_effect_reduce_painst) },
	{ DF_Type::creature_interaction_effect_reduce_paralysisst, sizeof(df::creature_interaction_effect_reduce_paralysisst) },
	{ DF_Type::creature_interaction_effect_reduce_swellingst, sizeof(df::creature_interaction_effect_reduce_swellingst) },
	{ DF_Type::creature_interaction_effect_regrow_partsst, sizeof(df::creature_interaction_effect_regrow_partsst) },
	{ DF_Type::creature_interaction_effect_remove_simple_flagst, sizeof(df::creature_interaction_effect_remove_simple_flagst) },
	{ DF_Type::creature_interaction_effect_sense_creature_classst, sizeof(df::creature_interaction_effect_sense_creature_classst) },
	{ DF_Type::creature_interaction_effect_skill_roll_adjustst, sizeof(df::creature_interaction_effect_skill_roll_adjustst) },
	{ DF_Type::creature_interaction_effect_special_attack_interactionst, sizeof(df::creature_interaction_effect_special_attack_interactionst) },
	{ DF_Type::creature_interaction_effect_speed_changest, sizeof(df::creature_interaction_effect_speed_changest) },
	{ DF_Type::creature_interaction_effect_stop_bleedingst, sizeof(df::creature_interaction_effect_stop_bleedingst) },
	{ DF_Type::creature_interaction_effect_swellingst, sizeof(df::creature_interaction_effect_swellingst) },
	{ DF_Type::creature_interaction_effect_target, sizeof(df::creature_interaction_effect_target) },
	{ DF_Type::creature_interaction_effect_target_mode, sizeof(df::enums::creature_interaction_effect_target_mode::creature_interaction_effect_target_mode) },
	{ DF_Type::creature_interaction_effect_type, sizeof(df::enums::creature_interaction_effect_type::creature_interaction_effect_type) },
	{ DF_Type::creature_interaction_effect_unconsciousnessst, sizeof(df::creature_interaction_effect_unconsciousnessst) },
	{ DF_Type::creature_interaction_effect_vomit_bloodst, sizeof(df::creature_interaction_effect_vomit_bloodst) },
	{ DF_Type::creature_interaction_target_flags, sizeof(df::creature_interaction_target_flags) },
	{ DF_Type::creature_raw, sizeof(df::creature_raw) },
	{ DF_Type::creature_raw__T_graphics, sizeof(df::creature_raw::T_graphics) },
	{ DF_Type::creature_raw__T_hive_product, sizeof(df::creature_raw::T_hive_product) },
	{ DF_Type::creature_raw__T_profession_name, sizeof(df::creature_raw::T_profession_name) },
	{ DF_Type::creature_raw_flags, sizeof(df::enums::creature_raw_flags::creature_raw_flags) },
	{ DF_Type::creature_variation, sizeof(df::creature_variation) },
	{ DF_Type::creature_variation_convert_tag, sizeof(df::creature_variation_convert_tag) },
	{ DF_Type::crime, sizeof(df::crime) },
	{ DF_Type::crime__T_convict_data, sizeof(df::crime::T_convict_data) },
	{ DF_Type::crime__T_counterintelligence, sizeof(df::crime::T_counterintelligence) },
	{ DF_Type::crime__T_flags, sizeof(df::crime::T_flags) },
	{ DF_Type::crime__T_mode, sizeof(df::crime::T_mode) },
	{ DF_Type::crime__T_punishment, sizeof(df::crime::T_punishment) },
	{ DF_Type::crime__T_reports, sizeof(df::crime::T_reports) },
	{ DF_Type::crime__T_victim_data, sizeof(df::crime::T_victim_data) },
	{ DF_Type::crime_type, sizeof(df::enums::crime_type::crime_type) },
	{ DF_Type::cultural_identity, sizeof(df::cultural_identity) },
	{ DF_Type::cultural_identity__T_anon_1, sizeof(df::cultural_identity::T_anon_1) },
	{ DF_Type::cultural_identity__T_anon_2, sizeof(df::cultural_identity::T_anon_2) },
	{ DF_Type::cultural_identity__T_group_log, sizeof(df::cultural_identity::T_group_log) },
	{ DF_Type::cultural_identity__T_group_log__T_join_type, sizeof(df::cultural_identity::T_group_log::T_join_type) },
	{ DF_Type::cumulus_type, sizeof(df::enums::cumulus_type::cumulus_type) },
	{ DF_Type::curse_attr_change, sizeof(df::curse_attr_change) },
	{ DF_Type::d_init, sizeof(df::d_init) },
	{ DF_Type::d_init__T_store_dist, sizeof(df::d_init::T_store_dist) },
	{ DF_Type::d_init__T_wound_color, sizeof(df::d_init::T_wound_color) },
	{ DF_Type::d_init_embark_confirm, sizeof(df::enums::d_init_embark_confirm::d_init_embark_confirm) },
	{ DF_Type::d_init_flags1, sizeof(df::enums::d_init_flags1::d_init_flags1) },
	{ DF_Type::d_init_flags2, sizeof(df::enums::d_init_flags2::d_init_flags2) },
	{ DF_Type::d_init_flags3, sizeof(df::enums::d_init_flags3::d_init_flags3) },
	{ DF_Type::d_init_flags4, sizeof(df::enums::d_init_flags4::d_init_flags4) },
	{ DF_Type::d_init_idlers, sizeof(df::enums::d_init_idlers::d_init_idlers) },
	{ DF_Type::d_init_nickname, sizeof(df::enums::d_init_nickname::d_init_nickname) },
	{ DF_Type::d_init_tunnel, sizeof(df::enums::d_init_tunnel::d_init_tunnel) },
	{ DF_Type::d_init_z_view, sizeof(df::enums::d_init_z_view::d_init_z_view) },
	{ DF_Type::dance_form, sizeof(df::dance_form) },
	{ DF_Type::dance_form_sub1, sizeof(df::dance_form_sub1) },
	{ DF_Type::dance_form_sub2, sizeof(df::dance_form_sub2) },
	{ DF_Type::death_condition_type, sizeof(df::enums::death_condition_type::death_condition_type) },
	{ DF_Type::death_type, sizeof(df::enums::death_type::death_type) },
	{ DF_Type::deep_vein_hollow, sizeof(df::deep_vein_hollow) },
	{ DF_Type::descriptor_color, sizeof(df::descriptor_color) },
	{ DF_Type::descriptor_pattern, sizeof(df::descriptor_pattern) },
	{ DF_Type::descriptor_shape, sizeof(df::descriptor_shape) },
	{ DF_Type::descriptor_shape__T_gems_use, sizeof(df::descriptor_shape::T_gems_use) },
	{ DF_Type::dfhack_knowledge_scholar_flag, sizeof(df::enums::dfhack_knowledge_scholar_flag::dfhack_knowledge_scholar_flag) },
	{ DF_Type::dfhack_material_category, sizeof(df::dfhack_material_category) },
	{ DF_Type::dfhack_room_quality_level, sizeof(df::enums::dfhack_room_quality_level::dfhack_room_quality_level) },
	{ DF_Type::dipscript_info, sizeof(df::dipscript_info) },
	{ DF_Type::dipscript_popup, sizeof(df::dipscript_popup) },
	{ DF_Type::dipscript_popup__T_flags, sizeof(df::dipscript_popup::T_flags) },
	{ DF_Type::divination_set, sizeof(df::divination_set) },
	{ DF_Type::divination_set_roll, sizeof(df::divination_set_roll) },
	{ DF_Type::door_flags, sizeof(df::door_flags) },
	{ DF_Type::dye_info, sizeof(df::dye_info) },
	{ DF_Type::effect_info, sizeof(df::effect_info) },
	{ DF_Type::embark_feature, sizeof(df::embark_feature) },
	{ DF_Type::embark_finder_option, sizeof(df::enums::embark_finder_option::embark_finder_option) },
	{ DF_Type::embark_item_choice, sizeof(df::embark_item_choice) },
	{ DF_Type::embark_item_choice__T_list, sizeof(df::embark_item_choice::T_list) },
	{ DF_Type::embark_location, sizeof(df::embark_location) },
	{ DF_Type::embark_note, sizeof(df::embark_note) },
	{ DF_Type::embark_profile, sizeof(df::embark_profile) },
	{ DF_Type::emotion_type, sizeof(df::enums::emotion_type::emotion_type) },
	{ DF_Type::enabler__T_async_frombox, sizeof(df::enabler::T_async_frombox) },
	{ DF_Type::enabler__T_async_frombox__T_queue, sizeof(df::enabler::T_async_frombox::T_queue) },
	{ DF_Type::enabler__T_async_frombox__T_queue__T_msg, sizeof(df::enabler::T_async_frombox::T_queue::T_msg) },
	{ DF_Type::enabler__T_async_tobox, sizeof(df::enabler::T_async_tobox) },
	{ DF_Type::enabler__T_async_tobox__T_queue, sizeof(df::enabler::T_async_tobox::T_queue) },
	{ DF_Type::enabler__T_async_tobox__T_queue__T_cmd, sizeof(df::enabler::T_async_tobox::T_queue::T_cmd) },
	{ DF_Type::enabler__T_async_zoom, sizeof(df::enabler::T_async_zoom) },
	{ DF_Type::enabler__T_flag, sizeof(df::enabler::T_flag) },
	{ DF_Type::enabler__T_gputicks, sizeof(df::enabler::T_gputicks) },
	{ DF_Type::enabler__T_overridden_grid_sizes, sizeof(df::enabler::T_overridden_grid_sizes) },
	{ DF_Type::enabler__T_simticks, sizeof(df::enabler::T_simticks) },
	{ DF_Type::enabler__T_text_system, sizeof(df::enabler::T_text_system) },
	{ DF_Type::enabler__T_text_system__T_file_info, sizeof(df::enabler::T_text_system::T_file_info) },
	{ DF_Type::enabler__T_textures, sizeof(df::enabler::T_textures) },
	{ DF_Type::engraving, sizeof(df::engraving) },
	{ DF_Type::engraving_flags, sizeof(df::engraving_flags) },
	{ DF_Type::entity_action_type, sizeof(df::enums::entity_action_type::entity_action_type) },
	{ DF_Type::entity_activity_statistics, sizeof(df::entity_activity_statistics) },
	{ DF_Type::entity_activity_statistics__T_food, sizeof(df::entity_activity_statistics::T_food) },
	{ DF_Type::entity_activity_statistics__T_found_misc, sizeof(df::entity_activity_statistics::T_found_misc) },
	{ DF_Type::entity_activity_statistics__T_wealth, sizeof(df::entity_activity_statistics::T_wealth) },
	{ DF_Type::entity_animal_raw, sizeof(df::entity_animal_raw) },
	{ DF_Type::entity_animal_raw__T_flags, sizeof(df::entity_animal_raw::T_flags) },
	{ DF_Type::entity_buy_prices, sizeof(df::entity_buy_prices) },
	{ DF_Type::entity_buy_requests, sizeof(df::entity_buy_requests) },
	{ DF_Type::entity_claim_mask, sizeof(df::entity_claim_mask) },
	{ DF_Type::entity_claim_mask__T_map, sizeof(df::entity_claim_mask::T_map) },
	{ DF_Type::entity_entity_link, sizeof(df::entity_entity_link) },
	{ DF_Type::entity_entity_link_type, sizeof(df::enums::entity_entity_link_type::entity_entity_link_type) },
	{ DF_Type::entity_event, sizeof(df::entity_event) },
	{ DF_Type::entity_event__T_data, sizeof(df::entity_event::T_data) },
	{ DF_Type::entity_event__T_data__T_abandon, sizeof(df::entity_event::T_data::T_abandon) },
	{ DF_Type::entity_event__T_data__T_abduction, sizeof(df::entity_event::T_data::T_abduction) },
	{ DF_Type::entity_event__T_data__T_accept_peace_offer, sizeof(df::entity_event::T_data::T_accept_peace_offer) },
	{ DF_Type::entity_event__T_data__T_accept_tribute_demand, sizeof(df::entity_event::T_data::T_accept_tribute_demand) },
	{ DF_Type::entity_event__T_data__T_accept_tribute_offer, sizeof(df::entity_event::T_data::T_accept_tribute_offer) },
	{ DF_Type::entity_event__T_data__T_artifact_destroyed, sizeof(df::entity_event::T_data::T_artifact_destroyed) },
	{ DF_Type::entity_event__T_data__T_artifact_in_feature_layer, sizeof(df::entity_event::T_data::T_artifact_in_feature_layer) },
	{ DF_Type::entity_event__T_data__T_artifact_in_inventory, sizeof(df::entity_event::T_data::T_artifact_in_inventory) },
	{ DF_Type::entity_event__T_data__T_artifact_in_site, sizeof(df::entity_event::T_data::T_artifact_in_site) },
	{ DF_Type::entity_event__T_data__T_artifact_in_subregion, sizeof(df::entity_event::T_data::T_artifact_in_subregion) },
	{ DF_Type::entity_event__T_data__T_artifact_not_in_feature_layer, sizeof(df::entity_event::T_data::T_artifact_not_in_feature_layer) },
	{ DF_Type::entity_event__T_data__T_artifact_not_in_inventory, sizeof(df::entity_event::T_data::T_artifact_not_in_inventory) },
	{ DF_Type::entity_event__T_data__T_artifact_not_in_site, sizeof(df::entity_event::T_data::T_artifact_not_in_site) },
	{ DF_Type::entity_event__T_data__T_artifact_not_in_subregion, sizeof(df::entity_event::T_data::T_artifact_not_in_subregion) },
	{ DF_Type::entity_event__T_data__T_beast, sizeof(df::entity_event::T_data::T_beast) },
	{ DF_Type::entity_event__T_data__T_cease_tribute_offer, sizeof(df::entity_event::T_data::T_cease_tribute_offer) },
	{ DF_Type::entity_event__T_data__T_claim, sizeof(df::entity_event::T_data::T_claim) },
	{ DF_Type::entity_event__T_data__T_flee, sizeof(df::entity_event::T_data::T_flee) },
	{ DF_Type::entity_event__T_data__T_founded, sizeof(df::entity_event::T_data::T_founded) },
	{ DF_Type::entity_event__T_data__T_founding, sizeof(df::entity_event::T_data::T_founding) },
	{ DF_Type::entity_event__T_data__T_group, sizeof(df::entity_event::T_data::T_group) },
	{ DF_Type::entity_event__T_data__T_harass, sizeof(df::entity_event::T_data::T_harass) },
	{ DF_Type::entity_event__T_data__T_incident, sizeof(df::entity_event::T_data::T_incident) },
	{ DF_Type::entity_event__T_data__T_insurrection, sizeof(df::entity_event::T_data::T_insurrection) },
	{ DF_Type::entity_event__T_data__T_insurrection_end, sizeof(df::entity_event::T_data::T_insurrection_end) },
	{ DF_Type::entity_event__T_data__T_insurrection_end__T_result, sizeof(df::entity_event::T_data::T_insurrection_end::T_result) },
	{ DF_Type::entity_event__T_data__T_invasion, sizeof(df::entity_event::T_data::T_invasion) },
	{ DF_Type::entity_event__T_data__T_leave, sizeof(df::entity_event::T_data::T_leave) },
	{ DF_Type::entity_event__T_data__T_occupation, sizeof(df::entity_event::T_data::T_occupation) },
	{ DF_Type::entity_event__T_data__T_reclaimed, sizeof(df::entity_event::T_data::T_reclaimed) },
	{ DF_Type::entity_event__T_data__T_reclaiming, sizeof(df::entity_event::T_data::T_reclaiming) },
	{ DF_Type::entity_event__T_data__T_refuse_peace_offer, sizeof(df::entity_event::T_data::T_refuse_peace_offer) },
	{ DF_Type::entity_event__T_data__T_refuse_tribute_demand, sizeof(df::entity_event::T_data::T_refuse_tribute_demand) },
	{ DF_Type::entity_event__T_data__T_refuse_tribute_offer, sizeof(df::entity_event::T_data::T_refuse_tribute_offer) },
	{ DF_Type::entity_event__T_data__T_succession, sizeof(df::entity_event::T_data::T_succession) },
	{ DF_Type::entity_event_type, sizeof(df::enums::entity_event_type::entity_event_type) },
	{ DF_Type::entity_material_category, sizeof(df::enums::entity_material_category::entity_material_category) },
	{ DF_Type::entity_name_type, sizeof(df::enums::entity_name_type::entity_name_type) },
	{ DF_Type::entity_occasion, sizeof(df::entity_occasion) },
	{ DF_Type::entity_occasion_info, sizeof(df::entity_occasion_info) },
	{ DF_Type::entity_occasion_schedule, sizeof(df::entity_occasion_schedule) },
	{ DF_Type::entity_occasion_schedule_feature, sizeof(df::entity_occasion_schedule_feature) },
	{ DF_Type::entity_population, sizeof(df::entity_population) },
	{ DF_Type::entity_population_unk4, sizeof(df::entity_population_unk4) },
	{ DF_Type::entity_population_unk4__T_anon_1, sizeof(df::entity_population_unk4::T_anon_1) },
	{ DF_Type::entity_population_unk4__T_anon_2, sizeof(df::entity_population_unk4::T_anon_2) },
	{ DF_Type::entity_population_unk4__T_anon_3, sizeof(df::entity_population_unk4::T_anon_3) },
	{ DF_Type::entity_position, sizeof(df::entity_position) },
	{ DF_Type::entity_position_assignment, sizeof(df::entity_position_assignment) },
	{ DF_Type::entity_position_flags, sizeof(df::enums::entity_position_flags::entity_position_flags) },
	{ DF_Type::entity_position_raw, sizeof(df::entity_position_raw) },
	{ DF_Type::entity_position_raw_flags, sizeof(df::enums::entity_position_raw_flags::entity_position_raw_flags) },
	{ DF_Type::entity_position_responsibility, sizeof(df::enums::entity_position_responsibility::entity_position_responsibility) },
	{ DF_Type::entity_raw, sizeof(df::entity_raw) },
	{ DF_Type::entity_raw__T_equipment, sizeof(df::entity_raw::T_equipment) },
	{ DF_Type::entity_raw__T_jobs, sizeof(df::entity_raw::T_jobs) },
	{ DF_Type::entity_raw__T_land_holder_trigger, sizeof(df::entity_raw::T_land_holder_trigger) },
	{ DF_Type::entity_raw__T_progress_trigger, sizeof(df::entity_raw::T_progress_trigger) },
	{ DF_Type::entity_raw__T_scholar, sizeof(df::entity_raw::T_scholar) },
	{ DF_Type::entity_raw__T_symbols, sizeof(df::entity_raw::T_symbols) },
	{ DF_Type::entity_raw__T_tissue_styles, sizeof(df::entity_raw::T_tissue_styles) },
	{ DF_Type::entity_raw__T_workshops, sizeof(df::entity_raw::T_workshops) },
	{ DF_Type::entity_raw_flags, sizeof(df::enums::entity_raw_flags::entity_raw_flags) },
	{ DF_Type::entity_recipe, sizeof(df::entity_recipe) },
	{ DF_Type::entity_sell_category, sizeof(df::enums::entity_sell_category::entity_sell_category) },
	{ DF_Type::entity_sell_prices, sizeof(df::entity_sell_prices) },
	{ DF_Type::entity_sell_requests, sizeof(df::entity_sell_requests) },
	{ DF_Type::entity_site_link, sizeof(df::entity_site_link) },
	{ DF_Type::entity_site_link__T_unk_7, sizeof(df::entity_site_link::T_unk_7) },
	{ DF_Type::entity_site_link_flags, sizeof(df::entity_site_link_flags) },
	{ DF_Type::entity_site_link_status_flags, sizeof(df::entity_site_link_status_flags) },
	{ DF_Type::entity_site_link_type, sizeof(df::enums::entity_site_link_type::entity_site_link_type) },
	{ DF_Type::entity_tissue_style, sizeof(df::entity_tissue_style) },
	{ DF_Type::entity_uniform, sizeof(df::entity_uniform) },
	{ DF_Type::entity_uniform_item, sizeof(df::entity_uniform_item) },
	{ DF_Type::entity_unk_v47_1, sizeof(df::entity_unk_v47_1) },
	{ DF_Type::environment_type, sizeof(df::enums::environment_type::environment_type) },
	{ DF_Type::era_type, sizeof(df::enums::era_type::era_type) },
	{ DF_Type::ethic_response, sizeof(df::enums::ethic_response::ethic_response) },
	{ DF_Type::ethic_type, sizeof(df::enums::ethic_type::ethic_type) },
	{ DF_Type::export_map_type, sizeof(df::enums::export_map_type::export_map_type) },
	{ DF_Type::feature, sizeof(df::feature) },
	{ DF_Type::feature_alteration, sizeof(df::feature_alteration) },
	{ DF_Type::feature_alteration_new_lava_fill_zst, sizeof(df::feature_alteration_new_lava_fill_zst) },
	{ DF_Type::feature_alteration_new_pop_maxst, sizeof(df::feature_alteration_new_pop_maxst) },
	{ DF_Type::feature_alteration_type, sizeof(df::enums::feature_alteration_type::feature_alteration_type) },
	{ DF_Type::feature_cavest, sizeof(df::feature_cavest) },
	{ DF_Type::feature_deep_special_tubest, sizeof(df::feature_deep_special_tubest) },
	{ DF_Type::feature_deep_surface_portalst, sizeof(df::feature_deep_surface_portalst) },
	{ DF_Type::feature_init, sizeof(df::feature_init) },
	{ DF_Type::feature_init_cavest, sizeof(df::feature_init_cavest) },
	{ DF_Type::feature_init_deep_special_tubest, sizeof(df::feature_init_deep_special_tubest) },
	{ DF_Type::feature_init_deep_surface_portalst, sizeof(df::feature_init_deep_surface_portalst) },
	{ DF_Type::feature_init_flags, sizeof(df::enums::feature_init_flags::feature_init_flags) },
	{ DF_Type::feature_init_magma_core_from_layerst, sizeof(df::feature_init_magma_core_from_layerst) },
	{ DF_Type::feature_init_magma_poolst, sizeof(df::feature_init_magma_poolst) },
	{ DF_Type::feature_init_outdoor_riverst, sizeof(df::feature_init_outdoor_riverst) },
	{ DF_Type::feature_init_pitst, sizeof(df::feature_init_pitst) },
	{ DF_Type::feature_init_subterranean_from_layerst, sizeof(df::feature_init_subterranean_from_layerst) },
	{ DF_Type::feature_init_underworld_from_layerst, sizeof(df::feature_init_underworld_from_layerst) },
	{ DF_Type::feature_init_volcanost, sizeof(df::feature_init_volcanost) },
	{ DF_Type::feature_magma_core_from_layerst, sizeof(df::feature_magma_core_from_layerst) },
	{ DF_Type::feature_magma_poolst, sizeof(df::feature_magma_poolst) },
	{ DF_Type::feature_outdoor_riverst, sizeof(df::feature_outdoor_riverst) },
	{ DF_Type::feature_pitst, sizeof(df::feature_pitst) },
	{ DF_Type::feature_subterranean_from_layerst, sizeof(df::feature_subterranean_from_layerst) },
	{ DF_Type::feature_type, sizeof(df::enums::feature_type::feature_type) },
	{ DF_Type::feature_underworld_from_layerst, sizeof(df::feature_underworld_from_layerst) },
	{ DF_Type::feature_volcanost, sizeof(df::feature_volcanost) },
	{ DF_Type::file_compressorst, sizeof(df::file_compressorst) },
	{ DF_Type::fire, sizeof(df::fire) },
	{ DF_Type::flow_guide, sizeof(df::flow_guide) },
	{ DF_Type::flow_guide_item_cloudst, sizeof(df::flow_guide_item_cloudst) },
	{ DF_Type::flow_guide_trailing_flowst, sizeof(df::flow_guide_trailing_flowst) },
	{ DF_Type::flow_guide_type, sizeof(df::enums::flow_guide_type::flow_guide_type) },
	{ DF_Type::flow_info, sizeof(df::flow_info) },
	{ DF_Type::flow_reuse_pool, sizeof(df::flow_reuse_pool) },
	{ DF_Type::flow_reuse_pool__T_flags, sizeof(df::flow_reuse_pool::T_flags) },
	{ DF_Type::flow_type, sizeof(df::enums::flow_type::flow_type) },
	{ DF_Type::fog_type, sizeof(df::enums::fog_type::fog_type) },
	{ DF_Type::fortress_type, sizeof(df::enums::fortress_type::fortress_type) },
	{ DF_Type::front_type, sizeof(df::enums::front_type::front_type) },
	{ DF_Type::furnace_type, sizeof(df::enums::furnace_type::furnace_type) },
	{ DF_Type::furniture_type, sizeof(df::enums::furniture_type::furniture_type) },
	{ DF_Type::gait_info, sizeof(df::gait_info) },
	{ DF_Type::gait_info__T_flags, sizeof(df::gait_info::T_flags) },
	{ DF_Type::gait_type, sizeof(df::enums::gait_type::gait_type) },
	{ DF_Type::game_mode, sizeof(df::enums::game_mode::game_mode) },
	{ DF_Type::game_type, sizeof(df::enums::game_type::game_type) },
	{ DF_Type::gate_flags, sizeof(df::gate_flags) },
	{ DF_Type::general_ref, sizeof(df::general_ref) },
	{ DF_Type::general_ref_abstract_buildingst, sizeof(df::general_ref_abstract_buildingst) },
	{ DF_Type::general_ref_activity_eventst, sizeof(df::general_ref_activity_eventst) },
	{ DF_Type::general_ref_artifact, sizeof(df::general_ref_artifact) },
	{ DF_Type::general_ref_building, sizeof(df::general_ref_building) },
	{ DF_Type::general_ref_building_cagedst, sizeof(df::general_ref_building_cagedst) },
	{ DF_Type::general_ref_building_chainst, sizeof(df::general_ref_building_chainst) },
	{ DF_Type::general_ref_building_civzone_assignedst, sizeof(df::general_ref_building_civzone_assignedst) },
	{ DF_Type::general_ref_building_destinationst, sizeof(df::general_ref_building_destinationst) },
	{ DF_Type::general_ref_building_display_furniturest, sizeof(df::general_ref_building_display_furniturest) },
	{ DF_Type::general_ref_building_holderst, sizeof(df::general_ref_building_holderst) },
	{ DF_Type::general_ref_building_nest_boxst, sizeof(df::general_ref_building_nest_boxst) },
	{ DF_Type::general_ref_building_triggerst, sizeof(df::general_ref_building_triggerst) },
	{ DF_Type::general_ref_building_triggertargetst, sizeof(df::general_ref_building_triggertargetst) },
	{ DF_Type::general_ref_building_use_target_1st, sizeof(df::general_ref_building_use_target_1st) },
	{ DF_Type::general_ref_building_use_target_2st, sizeof(df::general_ref_building_use_target_2st) },
	{ DF_Type::general_ref_building_well_tag, sizeof(df::general_ref_building_well_tag) },
	{ DF_Type::general_ref_coinbatch, sizeof(df::general_ref_coinbatch) },
	{ DF_Type::general_ref_contained_in_itemst, sizeof(df::general_ref_contained_in_itemst) },
	{ DF_Type::general_ref_contains_itemst, sizeof(df::general_ref_contains_itemst) },
	{ DF_Type::general_ref_contains_unitst, sizeof(df::general_ref_contains_unitst) },
	{ DF_Type::general_ref_creaturest, sizeof(df::general_ref_creaturest) },
	{ DF_Type::general_ref_dance_formst, sizeof(df::general_ref_dance_formst) },
	{ DF_Type::general_ref_entity, sizeof(df::general_ref_entity) },
	{ DF_Type::general_ref_entity_art_image, sizeof(df::general_ref_entity_art_image) },
	{ DF_Type::general_ref_entity_itemownerst, sizeof(df::general_ref_entity_itemownerst) },
	{ DF_Type::general_ref_entity_offeredst, sizeof(df::general_ref_entity_offeredst) },
	{ DF_Type::general_ref_entity_popst, sizeof(df::general_ref_entity_popst) },
	{ DF_Type::general_ref_entity_stolenst, sizeof(df::general_ref_entity_stolenst) },
	{ DF_Type::general_ref_feature_layerst, sizeof(df::general_ref_feature_layerst) },
	{ DF_Type::general_ref_historical_eventst, sizeof(df::general_ref_historical_eventst) },
	{ DF_Type::general_ref_historical_figurest, sizeof(df::general_ref_historical_figurest) },
	{ DF_Type::general_ref_interactionst, sizeof(df::general_ref_interactionst) },
	{ DF_Type::general_ref_is_artifactst, sizeof(df::general_ref_is_artifactst) },
	{ DF_Type::general_ref_is_nemesisst, sizeof(df::general_ref_is_nemesisst) },
	{ DF_Type::general_ref_item, sizeof(df::general_ref_item) },
	{ DF_Type::general_ref_item_type, sizeof(df::general_ref_item_type) },
	{ DF_Type::general_ref_knowledge_scholar_flagst, sizeof(df::general_ref_knowledge_scholar_flagst) },
	{ DF_Type::general_ref_languagest, sizeof(df::general_ref_languagest) },
	{ DF_Type::general_ref_locationst, sizeof(df::general_ref_locationst) },
	{ DF_Type::general_ref_mapsquare, sizeof(df::general_ref_mapsquare) },
	{ DF_Type::general_ref_musical_formst, sizeof(df::general_ref_musical_formst) },
	{ DF_Type::general_ref_nemesis, sizeof(df::general_ref_nemesis) },
	{ DF_Type::general_ref_poetic_formst, sizeof(df::general_ref_poetic_formst) },
	{ DF_Type::general_ref_projectile, sizeof(df::general_ref_projectile) },
	{ DF_Type::general_ref_sitest, sizeof(df::general_ref_sitest) },
	{ DF_Type::general_ref_spherest, sizeof(df::general_ref_spherest) },
	{ DF_Type::general_ref_subregionst, sizeof(df::general_ref_subregionst) },
	{ DF_Type::general_ref_type, sizeof(df::enums::general_ref_type::general_ref_type) },
	{ DF_Type::general_ref_unit, sizeof(df::general_ref_unit) },
	{ DF_Type::general_ref_unit_beateest, sizeof(df::general_ref_unit_beateest) },
	{ DF_Type::general_ref_unit_cageest, sizeof(df::general_ref_unit_cageest) },
	{ DF_Type::general_ref_unit_climberst, sizeof(df::general_ref_unit_climberst) },
	{ DF_Type::general_ref_unit_foodreceiverst, sizeof(df::general_ref_unit_foodreceiverst) },
	{ DF_Type::general_ref_unit_geldeest, sizeof(df::general_ref_unit_geldeest) },
	{ DF_Type::general_ref_unit_holderst, sizeof(df::general_ref_unit_holderst) },
	{ DF_Type::general_ref_unit_infantst, sizeof(df::general_ref_unit_infantst) },
	{ DF_Type::general_ref_unit_interrogateest, sizeof(df::general_ref_unit_interrogateest) },
	{ DF_Type::general_ref_unit_itemownerst, sizeof(df::general_ref_unit_itemownerst) },
	{ DF_Type::general_ref_unit_itemownerst__T_flags, sizeof(df::general_ref_unit_itemownerst::T_flags) },
	{ DF_Type::general_ref_unit_kidnapeest, sizeof(df::general_ref_unit_kidnapeest) },
	{ DF_Type::general_ref_unit_milkeest, sizeof(df::general_ref_unit_milkeest) },
	{ DF_Type::general_ref_unit_patientst, sizeof(df::general_ref_unit_patientst) },
	{ DF_Type::general_ref_unit_reporteest, sizeof(df::general_ref_unit_reporteest) },
	{ DF_Type::general_ref_unit_riderst, sizeof(df::general_ref_unit_riderst) },
	{ DF_Type::general_ref_unit_sheareest, sizeof(df::general_ref_unit_sheareest) },
	{ DF_Type::general_ref_unit_slaughtereest, sizeof(df::general_ref_unit_slaughtereest) },
	{ DF_Type::general_ref_unit_suckeest, sizeof(df::general_ref_unit_suckeest) },
	{ DF_Type::general_ref_unit_tradebringerst, sizeof(df::general_ref_unit_tradebringerst) },
	{ DF_Type::general_ref_unit_traineest, sizeof(df::general_ref_unit_traineest) },
	{ DF_Type::general_ref_unit_workerst, sizeof(df::general_ref_unit_workerst) },
	{ DF_Type::general_ref_value_levelst, sizeof(df::general_ref_value_levelst) },
	{ DF_Type::general_ref_written_contentst, sizeof(df::general_ref_written_contentst) },
	{ DF_Type::geo_layer_type, sizeof(df::enums::geo_layer_type::geo_layer_type) },
	{ DF_Type::ghost_goal, sizeof(df::enums::ghost_goal::ghost_goal) },
	{ DF_Type::ghost_type, sizeof(df::enums::ghost_type::ghost_type) },
	{ DF_Type::gloves_flags, sizeof(df::enums::gloves_flags::gloves_flags) },
	{ DF_Type::glowing_barrier, sizeof(df::glowing_barrier) },
	{ DF_Type::goal_type, sizeof(df::enums::goal_type::goal_type) },
	{ DF_Type::graphic, sizeof(df::graphic) },
	{ DF_Type::guild_id, sizeof(df::enums::guild_id::guild_id) },
	{ DF_Type::hauler_type, sizeof(df::enums::hauler_type::hauler_type) },
	{ DF_Type::hauling_route, sizeof(df::hauling_route) },
	{ DF_Type::hauling_stop, sizeof(df::hauling_stop) },
	{ DF_Type::health_view_bits1, sizeof(df::health_view_bits1) },
	{ DF_Type::health_view_bits2, sizeof(df::health_view_bits2) },
	{ DF_Type::health_view_bits3, sizeof(df::health_view_bits3) },
	{ DF_Type::helm_flags, sizeof(df::enums::helm_flags::helm_flags) },
	{ DF_Type::hillock_house_type, sizeof(df::enums::hillock_house_type::hillock_house_type) },
	{ DF_Type::histfig_body_state, sizeof(df::enums::histfig_body_state::histfig_body_state) },
	{ DF_Type::histfig_entity_link, sizeof(df::histfig_entity_link) },
	{ DF_Type::histfig_entity_link_criminalst, sizeof(df::histfig_entity_link_criminalst) },
	{ DF_Type::histfig_entity_link_enemyst, sizeof(df::histfig_entity_link_enemyst) },
	{ DF_Type::histfig_entity_link_former_memberst, sizeof(df::histfig_entity_link_former_memberst) },
	{ DF_Type::histfig_entity_link_former_mercenaryst, sizeof(df::histfig_entity_link_former_mercenaryst) },
	{ DF_Type::histfig_entity_link_former_occupationst, sizeof(df::histfig_entity_link_former_occupationst) },
	{ DF_Type::histfig_entity_link_former_positionst, sizeof(df::histfig_entity_link_former_positionst) },
	{ DF_Type::histfig_entity_link_former_prisonerst, sizeof(df::histfig_entity_link_former_prisonerst) },
	{ DF_Type::histfig_entity_link_former_slavest, sizeof(df::histfig_entity_link_former_slavest) },
	{ DF_Type::histfig_entity_link_former_squadst, sizeof(df::histfig_entity_link_former_squadst) },
	{ DF_Type::histfig_entity_link_memberst, sizeof(df::histfig_entity_link_memberst) },
	{ DF_Type::histfig_entity_link_mercenaryst, sizeof(df::histfig_entity_link_mercenaryst) },
	{ DF_Type::histfig_entity_link_occupationst, sizeof(df::histfig_entity_link_occupationst) },
	{ DF_Type::histfig_entity_link_position_claimst, sizeof(df::histfig_entity_link_position_claimst) },
	{ DF_Type::histfig_entity_link_positionst, sizeof(df::histfig_entity_link_positionst) },
	{ DF_Type::histfig_entity_link_prisonerst, sizeof(df::histfig_entity_link_prisonerst) },
	{ DF_Type::histfig_entity_link_slavest, sizeof(df::histfig_entity_link_slavest) },
	{ DF_Type::histfig_entity_link_squadst, sizeof(df::histfig_entity_link_squadst) },
	{ DF_Type::histfig_entity_link_type, sizeof(df::enums::histfig_entity_link_type::histfig_entity_link_type) },
	{ DF_Type::histfig_flags, sizeof(df::enums::histfig_flags::histfig_flags) },
	{ DF_Type::histfig_hf_link, sizeof(df::histfig_hf_link) },
	{ DF_Type::histfig_hf_link_apprenticest, sizeof(df::histfig_hf_link_apprenticest) },
	{ DF_Type::histfig_hf_link_childst, sizeof(df::histfig_hf_link_childst) },
	{ DF_Type::histfig_hf_link_companionst, sizeof(df::histfig_hf_link_companionst) },
	{ DF_Type::histfig_hf_link_deceased_spousest, sizeof(df::histfig_hf_link_deceased_spousest) },
	{ DF_Type::histfig_hf_link_deityst, sizeof(df::histfig_hf_link_deityst) },
	{ DF_Type::histfig_hf_link_fatherst, sizeof(df::histfig_hf_link_fatherst) },
	{ DF_Type::histfig_hf_link_former_apprenticest, sizeof(df::histfig_hf_link_former_apprenticest) },
	{ DF_Type::histfig_hf_link_former_masterst, sizeof(df::histfig_hf_link_former_masterst) },
	{ DF_Type::histfig_hf_link_former_spousest, sizeof(df::histfig_hf_link_former_spousest) },
	{ DF_Type::histfig_hf_link_imprisonerst, sizeof(df::histfig_hf_link_imprisonerst) },
	{ DF_Type::histfig_hf_link_loverst, sizeof(df::histfig_hf_link_loverst) },
	{ DF_Type::histfig_hf_link_masterst, sizeof(df::histfig_hf_link_masterst) },
	{ DF_Type::histfig_hf_link_motherst, sizeof(df::histfig_hf_link_motherst) },
	{ DF_Type::histfig_hf_link_pet_ownerst, sizeof(df::histfig_hf_link_pet_ownerst) },
	{ DF_Type::histfig_hf_link_prisonerst, sizeof(df::histfig_hf_link_prisonerst) },
	{ DF_Type::histfig_hf_link_spousest, sizeof(df::histfig_hf_link_spousest) },
	{ DF_Type::histfig_hf_link_type, sizeof(df::enums::histfig_hf_link_type::histfig_hf_link_type) },
	{ DF_Type::histfig_relationship_type, sizeof(df::enums::histfig_relationship_type::histfig_relationship_type) },
	{ DF_Type::histfig_site_link, sizeof(df::histfig_site_link) },
	{ DF_Type::histfig_site_link_hangoutst, sizeof(df::histfig_site_link_hangoutst) },
	{ DF_Type::histfig_site_link_home_site_abstract_buildingst, sizeof(df::histfig_site_link_home_site_abstract_buildingst) },
	{ DF_Type::histfig_site_link_home_site_realization_buildingst, sizeof(df::histfig_site_link_home_site_realization_buildingst) },
	{ DF_Type::histfig_site_link_home_site_realization_sulst, sizeof(df::histfig_site_link_home_site_realization_sulst) },
	{ DF_Type::histfig_site_link_home_site_saved_civzonest, sizeof(df::histfig_site_link_home_site_saved_civzonest) },
	{ DF_Type::histfig_site_link_lairst, sizeof(df::histfig_site_link_lairst) },
	{ DF_Type::histfig_site_link_occupationst, sizeof(df::histfig_site_link_occupationst) },
	{ DF_Type::histfig_site_link_prison_abstract_buildingst, sizeof(df::histfig_site_link_prison_abstract_buildingst) },
	{ DF_Type::histfig_site_link_prison_site_building_profilest, sizeof(df::histfig_site_link_prison_site_building_profilest) },
	{ DF_Type::histfig_site_link_seat_of_powerst, sizeof(df::histfig_site_link_seat_of_powerst) },
	{ DF_Type::histfig_site_link_type, sizeof(df::enums::histfig_site_link_type::histfig_site_link_type) },
	{ DF_Type::historical_entity, sizeof(df::historical_entity) },
	{ DF_Type::historical_entity__T_claims, sizeof(df::historical_entity::T_claims) },
	{ DF_Type::historical_entity__T_derived_resources, sizeof(df::historical_entity::T_derived_resources) },
	{ DF_Type::historical_entity__T_flags, sizeof(df::historical_entity::T_flags) },
	{ DF_Type::historical_entity__T_guild_professions, sizeof(df::historical_entity::T_guild_professions) },
	{ DF_Type::historical_entity__T_positions, sizeof(df::historical_entity::T_positions) },
	{ DF_Type::historical_entity__T_relations, sizeof(df::historical_entity::T_relations) },
	{ DF_Type::historical_entity__T_relations__T_constructions, sizeof(df::historical_entity::T_relations::T_constructions) },
	{ DF_Type::historical_entity__T_relations__T_diplomacy, sizeof(df::historical_entity::T_relations::T_diplomacy) },
	{ DF_Type::historical_entity__T_resources, sizeof(df::historical_entity::T_resources) },
	{ DF_Type::historical_entity__T_resources__T_animals, sizeof(df::historical_entity::T_resources::T_animals) },
	{ DF_Type::historical_entity__T_resources__T_metal, sizeof(df::historical_entity::T_resources::T_metal) },
	{ DF_Type::historical_entity__T_resources__T_misc_mat, sizeof(df::historical_entity::T_resources::T_misc_mat) },
	{ DF_Type::historical_entity__T_resources__T_organic, sizeof(df::historical_entity::T_resources::T_organic) },
	{ DF_Type::historical_entity__T_resources__T_refuse, sizeof(df::historical_entity::T_resources::T_refuse) },
	{ DF_Type::historical_entity__T_resources__T_unk13, sizeof(df::historical_entity::T_resources::T_unk13) },
	{ DF_Type::historical_entity__T_resources__T_wood_products, sizeof(df::historical_entity::T_resources::T_wood_products) },
	{ DF_Type::historical_entity__T_tissue_styles, sizeof(df::historical_entity::T_tissue_styles) },
	{ DF_Type::historical_entity__T_training_knowledge, sizeof(df::historical_entity::T_training_knowledge) },
	{ DF_Type::historical_entity__T_unk_v47_1, sizeof(df::historical_entity::T_unk_v47_1) },
	{ DF_Type::historical_entity__T_unknown1d, sizeof(df::historical_entity::T_unknown1d) },
	{ DF_Type::historical_entity__T_unknown1e, sizeof(df::historical_entity::T_unknown1e) },
	{ DF_Type::historical_entity__T_unknown2, sizeof(df::historical_entity::T_unknown2) },
	{ DF_Type::historical_entity__T_unknown2__T_unk28, sizeof(df::historical_entity::T_unknown2::T_unk28) },
	{ DF_Type::historical_entity__T_unknown2__T_unk29, sizeof(df::historical_entity::T_unknown2::T_unk29) },
	{ DF_Type::historical_entity_type, sizeof(df::enums::historical_entity_type::historical_entity_type) },
	{ DF_Type::historical_figure, sizeof(df::historical_figure) },
	{ DF_Type::historical_figure__T_unk_fc, sizeof(df::historical_figure::T_unk_fc) },
	{ DF_Type::historical_figure__T_unk_v47_2, sizeof(df::historical_figure::T_unk_v47_2) },
	{ DF_Type::historical_figure__T_vague_relationships, sizeof(df::historical_figure::T_vague_relationships) },
	{ DF_Type::historical_figure_info, sizeof(df::historical_figure_info) },
	{ DF_Type::historical_figure_info__T_books, sizeof(df::historical_figure_info::T_books) },
	{ DF_Type::historical_figure_info__T_books__T_flags, sizeof(df::historical_figure_info::T_books::T_flags) },
	{ DF_Type::historical_figure_info__T_curse, sizeof(df::historical_figure_info::T_curse) },
	{ DF_Type::historical_figure_info__T_curse__T_anon_1, sizeof(df::historical_figure_info::T_curse::T_anon_1) },
	{ DF_Type::historical_figure_info__T_curse__T_experiments, sizeof(df::historical_figure_info::T_curse::T_experiments) },
	{ DF_Type::historical_figure_info__T_known_info, sizeof(df::historical_figure_info::T_known_info) },
	{ DF_Type::historical_figure_info__T_known_info__T_anon_1, sizeof(df::historical_figure_info::T_known_info::T_anon_1) },
	{ DF_Type::historical_figure_info__T_known_info__T_anon_6, sizeof(df::historical_figure_info::T_known_info::T_anon_6) },
	{ DF_Type::historical_figure_info__T_known_info__T_knowledge, sizeof(df::historical_figure_info::T_known_info::T_knowledge) },
	{ DF_Type::historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal, sizeof(df::historical_figure_info::T_known_info::T_knowledge::T_knowledge_goal) },
	{ DF_Type::historical_figure_info__T_known_info__T_unk_a8, sizeof(df::historical_figure_info::T_known_info::T_unk_a8) },
	{ DF_Type::historical_figure_info__T_masterpieces, sizeof(df::historical_figure_info::T_masterpieces) },
	{ DF_Type::historical_figure_info__T_personality, sizeof(df::historical_figure_info::T_personality) },
	{ DF_Type::historical_figure_info__T_relationships, sizeof(df::historical_figure_info::T_relationships) },
	{ DF_Type::historical_figure_info__T_relationships__T_anon_1, sizeof(df::historical_figure_info::T_relationships::T_anon_1) },
	{ DF_Type::historical_figure_info__T_relationships__T_artifact_claims, sizeof(df::historical_figure_info::T_relationships::T_artifact_claims) },
	{ DF_Type::historical_figure_info__T_relationships__T_hf_historical, sizeof(df::historical_figure_info::T_relationships::T_hf_historical) },
	{ DF_Type::historical_figure_info__T_relationships__T_hf_visual, sizeof(df::historical_figure_info::T_relationships::T_hf_visual) },
	{ DF_Type::historical_figure_info__T_relationships__T_intrigues, sizeof(df::historical_figure_info::T_relationships::T_intrigues) },
	{ DF_Type::historical_figure_info__T_relationships__T_intrigues__T_intrigue, sizeof(df::historical_figure_info::T_relationships::T_intrigues::T_intrigue) },
	{ DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots, sizeof(df::historical_figure_info::T_relationships::T_intrigues::T_plots) },
	{ DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data, sizeof(df::historical_figure_info::T_relationships::T_intrigues::T_plots::T_plot_data) },
	{ DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Infiltrate_Society, sizeof(df::historical_figure_info::T_relationships::T_intrigues::T_plots::T_plot_data::T_Infiltrate_Society) },
	{ DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Sabotage_Actor, sizeof(df::historical_figure_info::T_relationships::T_intrigues::T_plots::T_plot_data::T_Sabotage_Actor) },
	{ DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type, sizeof(df::historical_figure_info::T_relationships::T_intrigues::T_plots::T_plot_type) },
	{ DF_Type::historical_figure_info__T_reputation, sizeof(df::historical_figure_info::T_reputation) },
	{ DF_Type::historical_figure_info__T_reputation__T_anon_1, sizeof(df::historical_figure_info::T_reputation::T_anon_1) },
	{ DF_Type::historical_figure_info__T_reputation__T_unk_2c, sizeof(df::historical_figure_info::T_reputation::T_unk_2c) },
	{ DF_Type::historical_figure_info__T_reputation__T_unk_2c__T_anon_12, sizeof(df::historical_figure_info::T_reputation::T_unk_2c::T_anon_12) },
	{ DF_Type::historical_figure_info__T_reputation__T_wanted, sizeof(df::historical_figure_info::T_reputation::T_wanted) },
	{ DF_Type::historical_figure_info__T_reputation__T_wanted__T_unk, sizeof(df::historical_figure_info::T_reputation::T_wanted::T_unk) },
	{ DF_Type::historical_figure_info__T_skills, sizeof(df::historical_figure_info::T_skills) },
	{ DF_Type::historical_figure_info__T_skills__T_employment_held, sizeof(df::historical_figure_info::T_skills::T_employment_held) },
	{ DF_Type::historical_figure_info__T_skills__T_employment_held__T_employment, sizeof(df::historical_figure_info::T_skills::T_employment_held::T_employment) },
	{ DF_Type::historical_figure_info__T_whereabouts, sizeof(df::historical_figure_info::T_whereabouts) },
	{ DF_Type::historical_figure_info__T_wounds, sizeof(df::historical_figure_info::T_wounds) },
	{ DF_Type::historical_kills, sizeof(df::historical_kills) },
	{ DF_Type::history_era, sizeof(df::history_era) },
	{ DF_Type::history_era__T_details, sizeof(df::history_era::T_details) },
	{ DF_Type::history_era__T_title, sizeof(df::history_era::T_title) },
	{ DF_Type::history_event, sizeof(df::history_event) },
	{ DF_Type::history_event_add_entity_site_profile_flagst, sizeof(df::history_event_add_entity_site_profile_flagst) },
	{ DF_Type::history_event_add_hf_entity_honorst, sizeof(df::history_event_add_hf_entity_honorst) },
	{ DF_Type::history_event_add_hf_entity_linkst, sizeof(df::history_event_add_hf_entity_linkst) },
	{ DF_Type::history_event_add_hf_hf_linkst, sizeof(df::history_event_add_hf_hf_linkst) },
	{ DF_Type::history_event_add_hf_site_linkst, sizeof(df::history_event_add_hf_site_linkst) },
	{ DF_Type::history_event_agreement_concludedst, sizeof(df::history_event_agreement_concludedst) },
	{ DF_Type::history_event_agreement_formedst, sizeof(df::history_event_agreement_formedst) },
	{ DF_Type::history_event_agreements_voidedst, sizeof(df::history_event_agreements_voidedst) },
	{ DF_Type::history_event_artifact_claim_formedst, sizeof(df::history_event_artifact_claim_formedst) },
	{ DF_Type::history_event_artifact_copiedst, sizeof(df::history_event_artifact_copiedst) },
	{ DF_Type::history_event_artifact_copiedst__T_flags2, sizeof(df::history_event_artifact_copiedst::T_flags2) },
	{ DF_Type::history_event_artifact_createdst, sizeof(df::history_event_artifact_createdst) },
	{ DF_Type::history_event_artifact_createdst__T_flags2, sizeof(df::history_event_artifact_createdst::T_flags2) },
	{ DF_Type::history_event_artifact_destroyedst, sizeof(df::history_event_artifact_destroyedst) },
	{ DF_Type::history_event_artifact_droppedst, sizeof(df::history_event_artifact_droppedst) },
	{ DF_Type::history_event_artifact_foundst, sizeof(df::history_event_artifact_foundst) },
	{ DF_Type::history_event_artifact_givenst, sizeof(df::history_event_artifact_givenst) },
	{ DF_Type::history_event_artifact_hiddenst, sizeof(df::history_event_artifact_hiddenst) },
	{ DF_Type::history_event_artifact_lostst, sizeof(df::history_event_artifact_lostst) },
	{ DF_Type::history_event_artifact_possessedst, sizeof(df::history_event_artifact_possessedst) },
	{ DF_Type::history_event_artifact_recoveredst, sizeof(df::history_event_artifact_recoveredst) },
	{ DF_Type::history_event_artifact_storedst, sizeof(df::history_event_artifact_storedst) },
	{ DF_Type::history_event_artifact_transformedst, sizeof(df::history_event_artifact_transformedst) },
	{ DF_Type::history_event_assume_identityst, sizeof(df::history_event_assume_identityst) },
	{ DF_Type::history_event_body_abusedst, sizeof(df::history_event_body_abusedst) },
	{ DF_Type::history_event_body_abusedst__T_abuse_data, sizeof(df::history_event_body_abusedst::T_abuse_data) },
	{ DF_Type::history_event_body_abusedst__T_abuse_data__T_Animated, sizeof(df::history_event_body_abusedst::T_abuse_data::T_Animated) },
	{ DF_Type::history_event_body_abusedst__T_abuse_data__T_Flayed, sizeof(df::history_event_body_abusedst::T_abuse_data::T_Flayed) },
	{ DF_Type::history_event_body_abusedst__T_abuse_data__T_Hung, sizeof(df::history_event_body_abusedst::T_abuse_data::T_Hung) },
	{ DF_Type::history_event_body_abusedst__T_abuse_data__T_Impaled, sizeof(df::history_event_body_abusedst::T_abuse_data::T_Impaled) },
	{ DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled, sizeof(df::history_event_body_abusedst::T_abuse_data::T_Piled) },
	{ DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type, sizeof(df::history_event_body_abusedst::T_abuse_data::T_Piled::T_pile_type) },
	{ DF_Type::history_event_body_abusedst__T_abuse_type, sizeof(df::history_event_body_abusedst::T_abuse_type) },
	{ DF_Type::history_event_building_profile_acquiredst, sizeof(df::history_event_building_profile_acquiredst) },
	{ DF_Type::history_event_ceremonyst, sizeof(df::history_event_ceremonyst) },
	{ DF_Type::history_event_change_creature_typest, sizeof(df::history_event_change_creature_typest) },
	{ DF_Type::history_event_change_hf_body_statest, sizeof(df::history_event_change_hf_body_statest) },
	{ DF_Type::history_event_change_hf_jobst, sizeof(df::history_event_change_hf_jobst) },
	{ DF_Type::history_event_change_hf_moodst, sizeof(df::history_event_change_hf_moodst) },
	{ DF_Type::history_event_change_hf_statest, sizeof(df::history_event_change_hf_statest) },
	{ DF_Type::history_event_change_hf_statest__T_state, sizeof(df::history_event_change_hf_statest::T_state) },
	{ DF_Type::history_event_circumstance_info, sizeof(df::history_event_circumstance_info) },
	{ DF_Type::history_event_circumstance_info__T_data, sizeof(df::history_event_circumstance_info::T_data) },
	{ DF_Type::history_event_collection, sizeof(df::history_event_collection) },
	{ DF_Type::history_event_collection_abductionst, sizeof(df::history_event_collection_abductionst) },
	{ DF_Type::history_event_collection_battlest, sizeof(df::history_event_collection_battlest) },
	{ DF_Type::history_event_collection_battlest__T_attacker_merc_type, sizeof(df::history_event_collection_battlest::T_attacker_merc_type) },
	{ DF_Type::history_event_collection_beast_attackst, sizeof(df::history_event_collection_beast_attackst) },
	{ DF_Type::history_event_collection_ceremonyst, sizeof(df::history_event_collection_ceremonyst) },
	{ DF_Type::history_event_collection_competitionst, sizeof(df::history_event_collection_competitionst) },
	{ DF_Type::history_event_collection_duelst, sizeof(df::history_event_collection_duelst) },
	{ DF_Type::history_event_collection_entity_overthrownst, sizeof(df::history_event_collection_entity_overthrownst) },
	{ DF_Type::history_event_collection_insurrectionst, sizeof(df::history_event_collection_insurrectionst) },
	{ DF_Type::history_event_collection_journeyst, sizeof(df::history_event_collection_journeyst) },
	{ DF_Type::history_event_collection_occasionst, sizeof(df::history_event_collection_occasionst) },
	{ DF_Type::history_event_collection_performancest, sizeof(df::history_event_collection_performancest) },
	{ DF_Type::history_event_collection_persecutionst, sizeof(df::history_event_collection_persecutionst) },
	{ DF_Type::history_event_collection_processionst, sizeof(df::history_event_collection_processionst) },
	{ DF_Type::history_event_collection_purgest, sizeof(df::history_event_collection_purgest) },
	{ DF_Type::history_event_collection_raidst, sizeof(df::history_event_collection_raidst) },
	{ DF_Type::history_event_collection_site_conqueredst, sizeof(df::history_event_collection_site_conqueredst) },
	{ DF_Type::history_event_collection_theftst, sizeof(df::history_event_collection_theftst) },
	{ DF_Type::history_event_collection_type, sizeof(df::enums::history_event_collection_type::history_event_collection_type) },
	{ DF_Type::history_event_collection_warst, sizeof(df::history_event_collection_warst) },
	{ DF_Type::history_event_collection_warst__T_unk, sizeof(df::history_event_collection_warst::T_unk) },
	{ DF_Type::history_event_competitionst, sizeof(df::history_event_competitionst) },
	{ DF_Type::history_event_context, sizeof(df::history_event_context) },
	{ DF_Type::history_event_context__T_unk_10, sizeof(df::history_event_context::T_unk_10) },
	{ DF_Type::history_event_create_entity_positionst, sizeof(df::history_event_create_entity_positionst) },
	{ DF_Type::history_event_created_buildingst, sizeof(df::history_event_created_buildingst) },
	{ DF_Type::history_event_created_sitest, sizeof(df::history_event_created_sitest) },
	{ DF_Type::history_event_created_world_constructionst, sizeof(df::history_event_created_world_constructionst) },
	{ DF_Type::history_event_creature_devouredst, sizeof(df::history_event_creature_devouredst) },
	{ DF_Type::history_event_dance_form_createdst, sizeof(df::history_event_dance_form_createdst) },
	{ DF_Type::history_event_diplomat_lostst, sizeof(df::history_event_diplomat_lostst) },
	{ DF_Type::history_event_entity_actionst, sizeof(df::history_event_entity_actionst) },
	{ DF_Type::history_event_entity_alliance_formedst, sizeof(df::history_event_entity_alliance_formedst) },
	{ DF_Type::history_event_entity_breach_feature_layerst, sizeof(df::history_event_entity_breach_feature_layerst) },
	{ DF_Type::history_event_entity_createdst, sizeof(df::history_event_entity_createdst) },
	{ DF_Type::history_event_entity_dissolvedst, sizeof(df::history_event_entity_dissolvedst) },
	{ DF_Type::history_event_entity_equipment_purchasest, sizeof(df::history_event_entity_equipment_purchasest) },
	{ DF_Type::history_event_entity_expels_hfst, sizeof(df::history_event_entity_expels_hfst) },
	{ DF_Type::history_event_entity_fled_sitest, sizeof(df::history_event_entity_fled_sitest) },
	{ DF_Type::history_event_entity_incorporatedst, sizeof(df::history_event_entity_incorporatedst) },
	{ DF_Type::history_event_entity_lawst, sizeof(df::history_event_entity_lawst) },
	{ DF_Type::history_event_entity_lawst__T_add_flags, sizeof(df::history_event_entity_lawst::T_add_flags) },
	{ DF_Type::history_event_entity_lawst__T_remove_flags, sizeof(df::history_event_entity_lawst::T_remove_flags) },
	{ DF_Type::history_event_entity_overthrownst, sizeof(df::history_event_entity_overthrownst) },
	{ DF_Type::history_event_entity_persecutedst, sizeof(df::history_event_entity_persecutedst) },
	{ DF_Type::history_event_entity_rampaged_in_sitest, sizeof(df::history_event_entity_rampaged_in_sitest) },
	{ DF_Type::history_event_entity_razed_buildingst, sizeof(df::history_event_entity_razed_buildingst) },
	{ DF_Type::history_event_entity_searched_sitest, sizeof(df::history_event_entity_searched_sitest) },
	{ DF_Type::history_event_failed_frame_attemptst, sizeof(df::history_event_failed_frame_attemptst) },
	{ DF_Type::history_event_failed_intrigue_corruptionst, sizeof(df::history_event_failed_intrigue_corruptionst) },
	{ DF_Type::history_event_first_contact_failedst, sizeof(df::history_event_first_contact_failedst) },
	{ DF_Type::history_event_first_contactst, sizeof(df::history_event_first_contactst) },
	{ DF_Type::history_event_flags, sizeof(df::enums::history_event_flags::history_event_flags) },
	{ DF_Type::history_event_gamblest, sizeof(df::history_event_gamblest) },
	{ DF_Type::history_event_hf_act_on_artifactst, sizeof(df::history_event_hf_act_on_artifactst) },
	{ DF_Type::history_event_hf_act_on_artifactst__T_action, sizeof(df::history_event_hf_act_on_artifactst::T_action) },
	{ DF_Type::history_event_hf_act_on_buildingst, sizeof(df::history_event_hf_act_on_buildingst) },
	{ DF_Type::history_event_hf_act_on_buildingst__T_action, sizeof(df::history_event_hf_act_on_buildingst::T_action) },
	{ DF_Type::history_event_hf_attacked_sitest, sizeof(df::history_event_hf_attacked_sitest) },
	{ DF_Type::history_event_hf_confrontedst, sizeof(df::history_event_hf_confrontedst) },
	{ DF_Type::history_event_hf_convictedst, sizeof(df::history_event_hf_convictedst) },
	{ DF_Type::history_event_hf_convictedst__T_plot_flags, sizeof(df::history_event_hf_convictedst::T_plot_flags) },
	{ DF_Type::history_event_hf_convictedst__T_punishment_flags, sizeof(df::history_event_hf_convictedst::T_punishment_flags) },
	{ DF_Type::history_event_hf_destroyed_sitest, sizeof(df::history_event_hf_destroyed_sitest) },
	{ DF_Type::history_event_hf_does_interactionst, sizeof(df::history_event_hf_does_interactionst) },
	{ DF_Type::history_event_hf_enslavedst, sizeof(df::history_event_hf_enslavedst) },
	{ DF_Type::history_event_hf_freedst, sizeof(df::history_event_hf_freedst) },
	{ DF_Type::history_event_hf_gains_secret_goalst, sizeof(df::history_event_hf_gains_secret_goalst) },
	{ DF_Type::history_event_hf_interrogatedst, sizeof(df::history_event_hf_interrogatedst) },
	{ DF_Type::history_event_hf_interrogatedst__T_interrogation_flags, sizeof(df::history_event_hf_interrogatedst::T_interrogation_flags) },
	{ DF_Type::history_event_hf_learns_secretst, sizeof(df::history_event_hf_learns_secretst) },
	{ DF_Type::history_event_hf_preachst, sizeof(df::history_event_hf_preachst) },
	{ DF_Type::history_event_hf_ransomedst, sizeof(df::history_event_hf_ransomedst) },
	{ DF_Type::history_event_hf_razed_buildingst, sizeof(df::history_event_hf_razed_buildingst) },
	{ DF_Type::history_event_hf_recruited_unit_type_for_entityst, sizeof(df::history_event_hf_recruited_unit_type_for_entityst) },
	{ DF_Type::history_event_hf_relationship_deniedst, sizeof(df::history_event_hf_relationship_deniedst) },
	{ DF_Type::history_event_hfs_formed_intrigue_relationshipst, sizeof(df::history_event_hfs_formed_intrigue_relationshipst) },
	{ DF_Type::history_event_hfs_formed_reputation_relationshipst, sizeof(df::history_event_hfs_formed_reputation_relationshipst) },
	{ DF_Type::history_event_hist_figure_abductedst, sizeof(df::history_event_hist_figure_abductedst) },
	{ DF_Type::history_event_hist_figure_diedst, sizeof(df::history_event_hist_figure_diedst) },
	{ DF_Type::history_event_hist_figure_new_petst, sizeof(df::history_event_hist_figure_new_petst) },
	{ DF_Type::history_event_hist_figure_reach_summitst, sizeof(df::history_event_hist_figure_reach_summitst) },
	{ DF_Type::history_event_hist_figure_reunionst, sizeof(df::history_event_hist_figure_reunionst) },
	{ DF_Type::history_event_hist_figure_revivedst, sizeof(df::history_event_hist_figure_revivedst) },
	{ DF_Type::history_event_hist_figure_revivedst__T_flags2, sizeof(df::history_event_hist_figure_revivedst::T_flags2) },
	{ DF_Type::history_event_hist_figure_simple_actionst, sizeof(df::history_event_hist_figure_simple_actionst) },
	{ DF_Type::history_event_hist_figure_simple_battle_eventst, sizeof(df::history_event_hist_figure_simple_battle_eventst) },
	{ DF_Type::history_event_hist_figure_travelst, sizeof(df::history_event_hist_figure_travelst) },
	{ DF_Type::history_event_hist_figure_travelst__T_reason, sizeof(df::history_event_hist_figure_travelst::T_reason) },
	{ DF_Type::history_event_hist_figure_woundedst, sizeof(df::history_event_hist_figure_woundedst) },
	{ DF_Type::history_event_hist_figure_woundedst__T_flags2, sizeof(df::history_event_hist_figure_woundedst::T_flags2) },
	{ DF_Type::history_event_hist_figure_woundedst__T_injury_type, sizeof(df::history_event_hist_figure_woundedst::T_injury_type) },
	{ DF_Type::history_event_insurrection_endedst, sizeof(df::history_event_insurrection_endedst) },
	{ DF_Type::history_event_insurrection_startedst, sizeof(df::history_event_insurrection_startedst) },
	{ DF_Type::history_event_item_stolenst, sizeof(df::history_event_item_stolenst) },
	{ DF_Type::history_event_knowledge_discoveredst, sizeof(df::history_event_knowledge_discoveredst) },
	{ DF_Type::history_event_masterpiece_created_arch_constructst, sizeof(df::history_event_masterpiece_created_arch_constructst) },
	{ DF_Type::history_event_masterpiece_created_arch_designst, sizeof(df::history_event_masterpiece_created_arch_designst) },
	{ DF_Type::history_event_masterpiece_created_dye_itemst, sizeof(df::history_event_masterpiece_created_dye_itemst) },
	{ DF_Type::history_event_masterpiece_created_engravingst, sizeof(df::history_event_masterpiece_created_engravingst) },
	{ DF_Type::history_event_masterpiece_created_foodst, sizeof(df::history_event_masterpiece_created_foodst) },
	{ DF_Type::history_event_masterpiece_created_item_improvementst, sizeof(df::history_event_masterpiece_created_item_improvementst) },
	{ DF_Type::history_event_masterpiece_created_itemst, sizeof(df::history_event_masterpiece_created_itemst) },
	{ DF_Type::history_event_masterpiece_createdst, sizeof(df::history_event_masterpiece_createdst) },
	{ DF_Type::history_event_masterpiece_lostst, sizeof(df::history_event_masterpiece_lostst) },
	{ DF_Type::history_event_merchantst, sizeof(df::history_event_merchantst) },
	{ DF_Type::history_event_modified_buildingst, sizeof(df::history_event_modified_buildingst) },
	{ DF_Type::history_event_modified_buildingst__T_modification, sizeof(df::history_event_modified_buildingst::T_modification) },
	{ DF_Type::history_event_musical_form_createdst, sizeof(df::history_event_musical_form_createdst) },
	{ DF_Type::history_event_performancest, sizeof(df::history_event_performancest) },
	{ DF_Type::history_event_poetic_form_createdst, sizeof(df::history_event_poetic_form_createdst) },
	{ DF_Type::history_event_processionst, sizeof(df::history_event_processionst) },
	{ DF_Type::history_event_reason, sizeof(df::enums::history_event_reason::history_event_reason) },
	{ DF_Type::history_event_reason_info, sizeof(df::history_event_reason_info) },
	{ DF_Type::history_event_reason_info__T_data, sizeof(df::history_event_reason_info::T_data) },
	{ DF_Type::history_event_reclaim_sitest, sizeof(df::history_event_reclaim_sitest) },
	{ DF_Type::history_event_reclaim_sitest__T_flags2, sizeof(df::history_event_reclaim_sitest::T_flags2) },
	{ DF_Type::history_event_regionpop_incorporated_into_entityst, sizeof(df::history_event_regionpop_incorporated_into_entityst) },
	{ DF_Type::history_event_remove_hf_entity_linkst, sizeof(df::history_event_remove_hf_entity_linkst) },
	{ DF_Type::history_event_remove_hf_hf_linkst, sizeof(df::history_event_remove_hf_hf_linkst) },
	{ DF_Type::history_event_remove_hf_site_linkst, sizeof(df::history_event_remove_hf_site_linkst) },
	{ DF_Type::history_event_replaced_buildingst, sizeof(df::history_event_replaced_buildingst) },
	{ DF_Type::history_event_sabotagest, sizeof(df::history_event_sabotagest) },
	{ DF_Type::history_event_simple_battle_subtype, sizeof(df::enums::history_event_simple_battle_subtype::history_event_simple_battle_subtype) },
	{ DF_Type::history_event_site_diedst, sizeof(df::history_event_site_diedst) },
	{ DF_Type::history_event_site_diedst__T_flags2, sizeof(df::history_event_site_diedst::T_flags2) },
	{ DF_Type::history_event_site_disputest, sizeof(df::history_event_site_disputest) },
	{ DF_Type::history_event_site_retiredst, sizeof(df::history_event_site_retiredst) },
	{ DF_Type::history_event_site_retiredst__T_flags2, sizeof(df::history_event_site_retiredst::T_flags2) },
	{ DF_Type::history_event_site_surrenderedst, sizeof(df::history_event_site_surrenderedst) },
	{ DF_Type::history_event_sneak_into_sitest, sizeof(df::history_event_sneak_into_sitest) },
	{ DF_Type::history_event_spotted_leaving_sitest, sizeof(df::history_event_spotted_leaving_sitest) },
	{ DF_Type::history_event_squad_vs_squadst, sizeof(df::history_event_squad_vs_squadst) },
	{ DF_Type::history_event_tactical_situationst, sizeof(df::history_event_tactical_situationst) },
	{ DF_Type::history_event_tactical_situationst__T_tactics_flags, sizeof(df::history_event_tactical_situationst::T_tactics_flags) },
	{ DF_Type::history_event_topicagreement_concludedst, sizeof(df::history_event_topicagreement_concludedst) },
	{ DF_Type::history_event_topicagreement_madest, sizeof(df::history_event_topicagreement_madest) },
	{ DF_Type::history_event_topicagreement_rejectedst, sizeof(df::history_event_topicagreement_rejectedst) },
	{ DF_Type::history_event_tradest, sizeof(df::history_event_tradest) },
	{ DF_Type::history_event_type, sizeof(df::enums::history_event_type::history_event_type) },
	{ DF_Type::history_event_war_attacked_sitest, sizeof(df::history_event_war_attacked_sitest) },
	{ DF_Type::history_event_war_attacked_sitest__T_unk_1, sizeof(df::history_event_war_attacked_sitest::T_unk_1) },
	{ DF_Type::history_event_war_destroyed_sitest, sizeof(df::history_event_war_destroyed_sitest) },
	{ DF_Type::history_event_war_field_battlest, sizeof(df::history_event_war_field_battlest) },
	{ DF_Type::history_event_war_peace_acceptedst, sizeof(df::history_event_war_peace_acceptedst) },
	{ DF_Type::history_event_war_peace_rejectedst, sizeof(df::history_event_war_peace_rejectedst) },
	{ DF_Type::history_event_war_plundered_sitest, sizeof(df::history_event_war_plundered_sitest) },
	{ DF_Type::history_event_war_site_new_leaderst, sizeof(df::history_event_war_site_new_leaderst) },
	{ DF_Type::history_event_war_site_taken_overst, sizeof(df::history_event_war_site_taken_overst) },
	{ DF_Type::history_event_war_site_tribute_forcedst, sizeof(df::history_event_war_site_tribute_forcedst) },
	{ DF_Type::history_event_war_site_tribute_forcedst__T_tribute_flags, sizeof(df::history_event_war_site_tribute_forcedst::T_tribute_flags) },
	{ DF_Type::history_event_written_content_composedst, sizeof(df::history_event_written_content_composedst) },
	{ DF_Type::history_hit_item, sizeof(df::history_hit_item) },
	{ DF_Type::hive_flags, sizeof(df::hive_flags) },
	{ DF_Type::honors_type, sizeof(df::honors_type) },
	{ DF_Type::honors_type__T_flags, sizeof(df::honors_type::T_flags) },
	{ DF_Type::honors_type__T_required_skill_type, sizeof(df::honors_type::T_required_skill_type) },
	{ DF_Type::hospital_supplies, sizeof(df::hospital_supplies) },
	{ DF_Type::hospital_supplies__T_supplies_needed, sizeof(df::hospital_supplies::T_supplies_needed) },
	{ DF_Type::identity, sizeof(df::identity) },
	{ DF_Type::identity_type, sizeof(df::enums::identity_type::identity_type) },
	{ DF_Type::identity_unk_94, sizeof(df::identity_unk_94) },
	{ DF_Type::image_set, sizeof(df::image_set) },
	{ DF_Type::image_set__T_unk_vec1, sizeof(df::image_set::T_unk_vec1) },
	{ DF_Type::improvement_type, sizeof(df::enums::improvement_type::improvement_type) },
	{ DF_Type::incident, sizeof(df::incident) },
	{ DF_Type::incident__T_data, sizeof(df::incident::T_data) },
	{ DF_Type::incident__T_flags, sizeof(df::incident::T_flags) },
	{ DF_Type::incident__T_type, sizeof(df::incident::T_type) },
	{ DF_Type::incident_hfid, sizeof(df::incident_hfid) },
	{ DF_Type::incident_sub10, sizeof(df::incident_sub10) },
	{ DF_Type::incident_sub6_performance, sizeof(df::incident_sub6_performance) },
	{ DF_Type::incident_sub6_performance__T_participants, sizeof(df::incident_sub6_performance::T_participants) },
	{ DF_Type::incident_sub7, sizeof(df::incident_sub7) },
	{ DF_Type::incident_sub8, sizeof(df::incident_sub8) },
	{ DF_Type::incident_sub9, sizeof(df::incident_sub9) },
	{ DF_Type::inclusion_type, sizeof(df::enums::inclusion_type::inclusion_type) },
	{ DF_Type::init, sizeof(df::init) },
	{ DF_Type::init_display, sizeof(df::init_display) },
	{ DF_Type::init_display__T_windowed, sizeof(df::init_display::T_windowed) },
	{ DF_Type::init_display_flags, sizeof(df::enums::init_display_flags::init_display_flags) },
	{ DF_Type::init_font, sizeof(df::init_font) },
	{ DF_Type::init_font__T_use_ttf, sizeof(df::init_font::T_use_ttf) },
	{ DF_Type::init_input, sizeof(df::init_input) },
	{ DF_Type::init_input_flags, sizeof(df::enums::init_input_flags::init_input_flags) },
	{ DF_Type::init_media, sizeof(df::init_media) },
	{ DF_Type::init_media_flags, sizeof(df::enums::init_media_flags::init_media_flags) },
	{ DF_Type::init_window, sizeof(df::init_window) },
	{ DF_Type::init_window_flags, sizeof(df::enums::init_window_flags::init_window_flags) },
	{ DF_Type::inorganic_flags, sizeof(df::enums::inorganic_flags::inorganic_flags) },
	{ DF_Type::inorganic_raw, sizeof(df::inorganic_raw) },
	{ DF_Type::inorganic_raw__T_environment, sizeof(df::inorganic_raw::T_environment) },
	{ DF_Type::inorganic_raw__T_environment_spec, sizeof(df::inorganic_raw::T_environment_spec) },
	{ DF_Type::inorganic_raw__T_metal_ore, sizeof(df::inorganic_raw::T_metal_ore) },
	{ DF_Type::inorganic_raw__T_thread_metal, sizeof(df::inorganic_raw::T_thread_metal) },
	{ DF_Type::instrument_flags, sizeof(df::enums::instrument_flags::instrument_flags) },
	{ DF_Type::instrument_piece, sizeof(df::instrument_piece) },
	{ DF_Type::instrument_piece__T_flags, sizeof(df::instrument_piece::T_flags) },
	{ DF_Type::instrument_register, sizeof(df::instrument_register) },
	{ DF_Type::insurrection_outcome, sizeof(df::enums::insurrection_outcome::insurrection_outcome) },
	{ DF_Type::interaction, sizeof(df::interaction) },
	{ DF_Type::interaction_effect, sizeof(df::interaction_effect) },
	{ DF_Type::interaction_effect__T_flags, sizeof(df::interaction_effect::T_flags) },
	{ DF_Type::interaction_effect_add_syndromest, sizeof(df::interaction_effect_add_syndromest) },
	{ DF_Type::interaction_effect_animatest, sizeof(df::interaction_effect_animatest) },
	{ DF_Type::interaction_effect_change_item_qualityst, sizeof(df::interaction_effect_change_item_qualityst) },
	{ DF_Type::interaction_effect_change_weatherst, sizeof(df::interaction_effect_change_weatherst) },
	{ DF_Type::interaction_effect_cleanst, sizeof(df::interaction_effect_cleanst) },
	{ DF_Type::interaction_effect_contactst, sizeof(df::interaction_effect_contactst) },
	{ DF_Type::interaction_effect_create_itemst, sizeof(df::interaction_effect_create_itemst) },
	{ DF_Type::interaction_effect_hidest, sizeof(df::interaction_effect_hidest) },
	{ DF_Type::interaction_effect_location_hint, sizeof(df::enums::interaction_effect_location_hint::interaction_effect_location_hint) },
	{ DF_Type::interaction_effect_material_emissionst, sizeof(df::interaction_effect_material_emissionst) },
	{ DF_Type::interaction_effect_propel_unitst, sizeof(df::interaction_effect_propel_unitst) },
	{ DF_Type::interaction_effect_resurrectst, sizeof(df::interaction_effect_resurrectst) },
	{ DF_Type::interaction_effect_summon_unitst, sizeof(df::interaction_effect_summon_unitst) },
	{ DF_Type::interaction_effect_type, sizeof(df::enums::interaction_effect_type::interaction_effect_type) },
	{ DF_Type::interaction_flags, sizeof(df::enums::interaction_flags::interaction_flags) },
	{ DF_Type::interaction_instance, sizeof(df::interaction_instance) },
	{ DF_Type::interaction_source, sizeof(df::interaction_source) },
	{ DF_Type::interaction_source_attackst, sizeof(df::interaction_source_attackst) },
	{ DF_Type::interaction_source_creature_actionst, sizeof(df::interaction_source_creature_actionst) },
	{ DF_Type::interaction_source_deityst, sizeof(df::interaction_source_deityst) },
	{ DF_Type::interaction_source_disturbancest, sizeof(df::interaction_source_disturbancest) },
	{ DF_Type::interaction_source_experimentst, sizeof(df::interaction_source_experimentst) },
	{ DF_Type::interaction_source_ingestionst, sizeof(df::interaction_source_ingestionst) },
	{ DF_Type::interaction_source_regionst, sizeof(df::interaction_source_regionst) },
	{ DF_Type::interaction_source_regionst__T_region_flags, sizeof(df::interaction_source_regionst::T_region_flags) },
	{ DF_Type::interaction_source_secretst, sizeof(df::interaction_source_secretst) },
	{ DF_Type::interaction_source_secretst__T_learn_flags, sizeof(df::interaction_source_secretst::T_learn_flags) },
	{ DF_Type::interaction_source_type, sizeof(df::enums::interaction_source_type::interaction_source_type) },
	{ DF_Type::interaction_source_underground_specialst, sizeof(df::interaction_source_underground_specialst) },
	{ DF_Type::interaction_source_usage_hint, sizeof(df::enums::interaction_source_usage_hint::interaction_source_usage_hint) },
	{ DF_Type::interaction_target, sizeof(df::interaction_target) },
	{ DF_Type::interaction_target_corpsest, sizeof(df::interaction_target_corpsest) },
	{ DF_Type::interaction_target_creaturest, sizeof(df::interaction_target_creaturest) },
	{ DF_Type::interaction_target_info, sizeof(df::interaction_target_info) },
	{ DF_Type::interaction_target_info__T_restrictions, sizeof(df::interaction_target_info::T_restrictions) },
	{ DF_Type::interaction_target_location_type, sizeof(df::enums::interaction_target_location_type::interaction_target_location_type) },
	{ DF_Type::interaction_target_locationst, sizeof(df::interaction_target_locationst) },
	{ DF_Type::interaction_target_materialst, sizeof(df::interaction_target_materialst) },
	{ DF_Type::interaction_target_materialst__T_restrictions, sizeof(df::interaction_target_materialst::T_restrictions) },
	{ DF_Type::interaction_target_type, sizeof(df::enums::interaction_target_type::interaction_target_type) },
	{ DF_Type::interface_breakdown_types, sizeof(df::enums::interface_breakdown_types::interface_breakdown_types) },
	{ DF_Type::interface_button, sizeof(df::interface_button) },
	{ DF_Type::interface_button_building_category_selectorst, sizeof(df::interface_button_building_category_selectorst) },
	{ DF_Type::interface_button_building_custom_category_selectorst, sizeof(df::interface_button_building_custom_category_selectorst) },
	{ DF_Type::interface_button_building_material_selectorst, sizeof(df::interface_button_building_material_selectorst) },
	{ DF_Type::interface_button_building_new_jobst, sizeof(df::interface_button_building_new_jobst) },
	{ DF_Type::interface_button_buildingst, sizeof(df::interface_button_buildingst) },
	{ DF_Type::interface_button_construction_building_selectorst, sizeof(df::interface_button_construction_building_selectorst) },
	{ DF_Type::interface_button_construction_category_selectorst, sizeof(df::interface_button_construction_category_selectorst) },
	{ DF_Type::interface_button_construction_category_selectorst__T_category_id, sizeof(df::interface_button_construction_category_selectorst::T_category_id) },
	{ DF_Type::interface_button_construction_donest, sizeof(df::interface_button_construction_donest) },
	{ DF_Type::interface_button_constructionst, sizeof(df::interface_button_constructionst) },
	{ DF_Type::interface_key, sizeof(df::enums::interface_key::interface_key) },
	{ DF_Type::interfacest, sizeof(df::interfacest) },
	{ DF_Type::interrogation_report, sizeof(df::interrogation_report) },
	{ DF_Type::invasion_info, sizeof(df::invasion_info) },
	{ DF_Type::invasion_info__T_flags, sizeof(df::invasion_info::T_flags) },
	{ DF_Type::item, sizeof(df::item) },
	{ DF_Type::item_actual, sizeof(df::item_actual) },
	{ DF_Type::item_ammost, sizeof(df::item_ammost) },
	{ DF_Type::item_amuletst, sizeof(df::item_amuletst) },
	{ DF_Type::item_animaltrapst, sizeof(df::item_animaltrapst) },
	{ DF_Type::item_anvilst, sizeof(df::item_anvilst) },
	{ DF_Type::item_armorst, sizeof(df::item_armorst) },
	{ DF_Type::item_armorstandst, sizeof(df::item_armorstandst) },
	{ DF_Type::item_backpackst, sizeof(df::item_backpackst) },
	{ DF_Type::item_ballistaarrowheadst, sizeof(df::item_ballistaarrowheadst) },
	{ DF_Type::item_ballistapartsst, sizeof(df::item_ballistapartsst) },
	{ DF_Type::item_barrelst, sizeof(df::item_barrelst) },
	{ DF_Type::item_barst, sizeof(df::item_barst) },
	{ DF_Type::item_bedst, sizeof(df::item_bedst) },
	{ DF_Type::item_binst, sizeof(df::item_binst) },
	{ DF_Type::item_blocksst, sizeof(df::item_blocksst) },
	{ DF_Type::item_body_component, sizeof(df::item_body_component) },
	{ DF_Type::item_body_component__T_appearance, sizeof(df::item_body_component::T_appearance) },
	{ DF_Type::item_body_component__T_body, sizeof(df::item_body_component::T_body) },
	{ DF_Type::item_body_component__T_bone1, sizeof(df::item_body_component::T_bone1) },
	{ DF_Type::item_body_component__T_bone2, sizeof(df::item_body_component::T_bone2) },
	{ DF_Type::item_body_component__T_corpse_flags, sizeof(df::item_body_component::T_corpse_flags) },
	{ DF_Type::item_bookst, sizeof(df::item_bookst) },
	{ DF_Type::item_boulderst, sizeof(df::item_boulderst) },
	{ DF_Type::item_boxst, sizeof(df::item_boxst) },
	{ DF_Type::item_braceletst, sizeof(df::item_braceletst) },
	{ DF_Type::item_branchst, sizeof(df::item_branchst) },
	{ DF_Type::item_bucketst, sizeof(df::item_bucketst) },
	{ DF_Type::item_cabinetst, sizeof(df::item_cabinetst) },
	{ DF_Type::item_cagest, sizeof(df::item_cagest) },
	{ DF_Type::item_catapultpartsst, sizeof(df::item_catapultpartsst) },
	{ DF_Type::item_chainst, sizeof(df::item_chainst) },
	{ DF_Type::item_chairst, sizeof(df::item_chairst) },
	{ DF_Type::item_cheesest, sizeof(df::item_cheesest) },
	{ DF_Type::item_clothst, sizeof(df::item_clothst) },
	{ DF_Type::item_coffinst, sizeof(df::item_coffinst) },
	{ DF_Type::item_coinst, sizeof(df::item_coinst) },
	{ DF_Type::item_constructed, sizeof(df::item_constructed) },
	{ DF_Type::item_corpsepiecest, sizeof(df::item_corpsepiecest) },
	{ DF_Type::item_corpsest, sizeof(df::item_corpsest) },
	{ DF_Type::item_crafted, sizeof(df::item_crafted) },
	{ DF_Type::item_critter, sizeof(df::item_critter) },
	{ DF_Type::item_crownst, sizeof(df::item_crownst) },
	{ DF_Type::item_crutchst, sizeof(df::item_crutchst) },
	{ DF_Type::item_doorst, sizeof(df::item_doorst) },
	{ DF_Type::item_drinkst, sizeof(df::item_drinkst) },
	{ DF_Type::item_earringst, sizeof(df::item_earringst) },
	{ DF_Type::item_eggst, sizeof(df::item_eggst) },
	{ DF_Type::item_eggst__T_egg_flags, sizeof(df::item_eggst::T_egg_flags) },
	{ DF_Type::item_figurinest, sizeof(df::item_figurinest) },
	{ DF_Type::item_filter_spec, sizeof(df::item_filter_spec) },
	{ DF_Type::item_fish_rawst, sizeof(df::item_fish_rawst) },
	{ DF_Type::item_fishst, sizeof(df::item_fishst) },
	{ DF_Type::item_flags, sizeof(df::item_flags) },
	{ DF_Type::item_flags2, sizeof(df::item_flags2) },
	{ DF_Type::item_flaskst, sizeof(df::item_flaskst) },
	{ DF_Type::item_floodgatest, sizeof(df::item_floodgatest) },
	{ DF_Type::item_foodst, sizeof(df::item_foodst) },
	{ DF_Type::item_foodst__T_ingredients, sizeof(df::item_foodst::T_ingredients) },
	{ DF_Type::item_gemst, sizeof(df::item_gemst) },
	{ DF_Type::item_globst, sizeof(df::item_globst) },
	{ DF_Type::item_glovesst, sizeof(df::item_glovesst) },
	{ DF_Type::item_gobletst, sizeof(df::item_gobletst) },
	{ DF_Type::item_gratest, sizeof(df::item_gratest) },
	{ DF_Type::item_hatch_coverst, sizeof(df::item_hatch_coverst) },
	{ DF_Type::item_helmst, sizeof(df::item_helmst) },
	{ DF_Type::item_history_info, sizeof(df::item_history_info) },
	{ DF_Type::item_instrumentst, sizeof(df::item_instrumentst) },
	{ DF_Type::item_kill_info, sizeof(df::item_kill_info) },
	{ DF_Type::item_liquid, sizeof(df::item_liquid) },
	{ DF_Type::item_liquid_miscst, sizeof(df::item_liquid_miscst) },
	{ DF_Type::item_liquipowder, sizeof(df::item_liquipowder) },
	{ DF_Type::item_magicness, sizeof(df::item_magicness) },
	{ DF_Type::item_magicness_type, sizeof(df::enums::item_magicness_type::item_magicness_type) },
	{ DF_Type::item_matstate, sizeof(df::item_matstate) },
	{ DF_Type::item_meatst, sizeof(df::item_meatst) },
	{ DF_Type::item_millstonest, sizeof(df::item_millstonest) },
	{ DF_Type::item_orthopedic_castst, sizeof(df::item_orthopedic_castst) },
	{ DF_Type::item_pantsst, sizeof(df::item_pantsst) },
	{ DF_Type::item_petst, sizeof(df::item_petst) },
	{ DF_Type::item_petst__T_pet_flags, sizeof(df::item_petst::T_pet_flags) },
	{ DF_Type::item_pipe_sectionst, sizeof(df::item_pipe_sectionst) },
	{ DF_Type::item_plant_growthst, sizeof(df::item_plant_growthst) },
	{ DF_Type::item_plantst, sizeof(df::item_plantst) },
	{ DF_Type::item_powder, sizeof(df::item_powder) },
	{ DF_Type::item_powder_miscst, sizeof(df::item_powder_miscst) },
	{ DF_Type::item_quality, sizeof(df::enums::item_quality::item_quality) },
	{ DF_Type::item_quernst, sizeof(df::item_quernst) },
	{ DF_Type::item_quiverst, sizeof(df::item_quiverst) },
	{ DF_Type::item_remainsst, sizeof(df::item_remainsst) },
	{ DF_Type::item_ringst, sizeof(df::item_ringst) },
	{ DF_Type::item_rockst, sizeof(df::item_rockst) },
	{ DF_Type::item_roughst, sizeof(df::item_roughst) },
	{ DF_Type::item_scepterst, sizeof(df::item_scepterst) },
	{ DF_Type::item_seedsst, sizeof(df::item_seedsst) },
	{ DF_Type::item_sheetst, sizeof(df::item_sheetst) },
	{ DF_Type::item_shieldst, sizeof(df::item_shieldst) },
	{ DF_Type::item_shoesst, sizeof(df::item_shoesst) },
	{ DF_Type::item_siegeammost, sizeof(df::item_siegeammost) },
	{ DF_Type::item_skin_tannedst, sizeof(df::item_skin_tannedst) },
	{ DF_Type::item_slabst, sizeof(df::item_slabst) },
	{ DF_Type::item_smallgemst, sizeof(df::item_smallgemst) },
	{ DF_Type::item_splintst, sizeof(df::item_splintst) },
	{ DF_Type::item_statuest, sizeof(df::item_statuest) },
	{ DF_Type::item_stockpile_ref, sizeof(df::item_stockpile_ref) },
	{ DF_Type::item_tablest, sizeof(df::item_tablest) },
	{ DF_Type::item_threadst, sizeof(df::item_threadst) },
	{ DF_Type::item_toolst, sizeof(df::item_toolst) },
	{ DF_Type::item_totemst, sizeof(df::item_totemst) },
	{ DF_Type::item_toyst, sizeof(df::item_toyst) },
	{ DF_Type::item_traction_benchst, sizeof(df::item_traction_benchst) },
	{ DF_Type::item_trapcompst, sizeof(df::item_trapcompst) },
	{ DF_Type::item_trappartsst, sizeof(df::item_trappartsst) },
	{ DF_Type::item_type, sizeof(df::enums::item_type::item_type) },
	{ DF_Type::item_verminst, sizeof(df::item_verminst) },
	{ DF_Type::item_weaponrackst, sizeof(df::item_weaponrackst) },
	{ DF_Type::item_weaponst, sizeof(df::item_weaponst) },
	{ DF_Type::item_windowst, sizeof(df::item_windowst) },
	{ DF_Type::item_woodst, sizeof(df::item_woodst) },
	{ DF_Type::itemdef, sizeof(df::itemdef) },
	{ DF_Type::itemdef_ammost, sizeof(df::itemdef_ammost) },
	{ DF_Type::itemdef_armorst, sizeof(df::itemdef_armorst) },
	{ DF_Type::itemdef_flags, sizeof(df::enums::itemdef_flags::itemdef_flags) },
	{ DF_Type::itemdef_foodst, sizeof(df::itemdef_foodst) },
	{ DF_Type::itemdef_glovesst, sizeof(df::itemdef_glovesst) },
	{ DF_Type::itemdef_helmst, sizeof(df::itemdef_helmst) },
	{ DF_Type::itemdef_instrumentst, sizeof(df::itemdef_instrumentst) },
	{ DF_Type::itemdef_pantsst, sizeof(df::itemdef_pantsst) },
	{ DF_Type::itemdef_shieldst, sizeof(df::itemdef_shieldst) },
	{ DF_Type::itemdef_shoesst, sizeof(df::itemdef_shoesst) },
	{ DF_Type::itemdef_siegeammost, sizeof(df::itemdef_siegeammost) },
	{ DF_Type::itemdef_toolst, sizeof(df::itemdef_toolst) },
	{ DF_Type::itemdef_toolst__T_default_improvements, sizeof(df::itemdef_toolst::T_default_improvements) },
	{ DF_Type::itemdef_toyst, sizeof(df::itemdef_toyst) },
	{ DF_Type::itemdef_trapcompst, sizeof(df::itemdef_trapcompst) },
	{ DF_Type::itemdef_weaponst, sizeof(df::itemdef_weaponst) },
	{ DF_Type::itemimprovement, sizeof(df::itemimprovement) },
	{ DF_Type::itemimprovement_art_imagest, sizeof(df::itemimprovement_art_imagest) },
	{ DF_Type::itemimprovement_bandsst, sizeof(df::itemimprovement_bandsst) },
	{ DF_Type::itemimprovement_clothst, sizeof(df::itemimprovement_clothst) },
	{ DF_Type::itemimprovement_coveredst, sizeof(df::itemimprovement_coveredst) },
	{ DF_Type::itemimprovement_coveredst__T_cover_flags, sizeof(df::itemimprovement_coveredst::T_cover_flags) },
	{ DF_Type::itemimprovement_illustrationst, sizeof(df::itemimprovement_illustrationst) },
	{ DF_Type::itemimprovement_instrument_piecest, sizeof(df::itemimprovement_instrument_piecest) },
	{ DF_Type::itemimprovement_itemspecificst, sizeof(df::itemimprovement_itemspecificst) },
	{ DF_Type::itemimprovement_pagesst, sizeof(df::itemimprovement_pagesst) },
	{ DF_Type::itemimprovement_rings_hangingst, sizeof(df::itemimprovement_rings_hangingst) },
	{ DF_Type::itemimprovement_sewn_imagest, sizeof(df::itemimprovement_sewn_imagest) },
	{ DF_Type::itemimprovement_sewn_imagest__T_cloth, sizeof(df::itemimprovement_sewn_imagest::T_cloth) },
	{ DF_Type::itemimprovement_specific_type, sizeof(df::enums::itemimprovement_specific_type::itemimprovement_specific_type) },
	{ DF_Type::itemimprovement_spikesst, sizeof(df::itemimprovement_spikesst) },
	{ DF_Type::itemimprovement_threadst, sizeof(df::itemimprovement_threadst) },
	{ DF_Type::itemimprovement_writingst, sizeof(df::itemimprovement_writingst) },
	{ DF_Type::items_other_id, sizeof(df::enums::items_other_id::items_other_id) },
	{ DF_Type::job, sizeof(df::job) },
	{ DF_Type::job_art_specification, sizeof(df::job_art_specification) },
	{ DF_Type::job_art_specification__T_type, sizeof(df::job_art_specification::T_type) },
	{ DF_Type::job_flags, sizeof(df::job_flags) },
	{ DF_Type::job_handler, sizeof(df::job_handler) },
	{ DF_Type::job_handler__T_anon_1, sizeof(df::job_handler::T_anon_1) },
	{ DF_Type::job_handler__T_postings, sizeof(df::job_handler::T_postings) },
	{ DF_Type::job_handler__T_postings__T_flags, sizeof(df::job_handler::T_postings::T_flags) },
	{ DF_Type::job_item, sizeof(df::job_item) },
	{ DF_Type::job_item_filter, sizeof(df::job_item_filter) },
	{ DF_Type::job_item_flags1, sizeof(df::job_item_flags1) },
	{ DF_Type::job_item_flags2, sizeof(df::job_item_flags2) },
	{ DF_Type::job_item_flags3, sizeof(df::job_item_flags3) },
	{ DF_Type::job_item_ref, sizeof(df::job_item_ref) },
	{ DF_Type::job_item_ref__T_role, sizeof(df::job_item_ref::T_role) },
	{ DF_Type::job_item_vector_id, sizeof(df::enums::job_item_vector_id::job_item_vector_id) },
	{ DF_Type::job_list_link, sizeof(df::job_list_link) },
	{ DF_Type::job_material_category, sizeof(df::job_material_category) },
	{ DF_Type::job_skill, sizeof(df::enums::job_skill::job_skill) },
	{ DF_Type::job_skill_class, sizeof(df::enums::job_skill_class::job_skill_class) },
	{ DF_Type::job_subtype_surgery, sizeof(df::enums::job_subtype_surgery::job_subtype_surgery) },
	{ DF_Type::job_type, sizeof(df::enums::job_type::job_type) },
	{ DF_Type::job_type_class, sizeof(df::enums::job_type_class::job_type_class) },
	{ DF_Type::justification, sizeof(df::enums::justification::justification) },
	{ DF_Type::KeybindingScreen, sizeof(df::KeybindingScreen) },
	{ DF_Type::KeybindingScreen__T_mode, sizeof(df::KeybindingScreen::T_mode) },
	{ DF_Type::kitchen_exc_type, sizeof(df::enums::kitchen_exc_type::kitchen_exc_type) },
	{ DF_Type::kitchen_pref_flag, sizeof(df::kitchen_pref_flag) },
	{ DF_Type::knowledge_scholar_category_flag, sizeof(df::knowledge_scholar_category_flag) },
	{ DF_Type::knowledge_scholar_category_flag__T_flag_data, sizeof(df::knowledge_scholar_category_flag::T_flag_data) },
	{ DF_Type::knowledge_scholar_category_flag__T_flag_type, sizeof(df::knowledge_scholar_category_flag::T_flag_type) },
	{ DF_Type::knowledge_scholar_flags_0, sizeof(df::knowledge_scholar_flags_0) },
	{ DF_Type::knowledge_scholar_flags_1, sizeof(df::knowledge_scholar_flags_1) },
	{ DF_Type::knowledge_scholar_flags_10, sizeof(df::knowledge_scholar_flags_10) },
	{ DF_Type::knowledge_scholar_flags_11, sizeof(df::knowledge_scholar_flags_11) },
	{ DF_Type::knowledge_scholar_flags_12, sizeof(df::knowledge_scholar_flags_12) },
	{ DF_Type::knowledge_scholar_flags_13, sizeof(df::knowledge_scholar_flags_13) },
	{ DF_Type::knowledge_scholar_flags_2, sizeof(df::knowledge_scholar_flags_2) },
	{ DF_Type::knowledge_scholar_flags_3, sizeof(df::knowledge_scholar_flags_3) },
	{ DF_Type::knowledge_scholar_flags_4, sizeof(df::knowledge_scholar_flags_4) },
	{ DF_Type::knowledge_scholar_flags_5, sizeof(df::knowledge_scholar_flags_5) },
	{ DF_Type::knowledge_scholar_flags_6, sizeof(df::knowledge_scholar_flags_6) },
	{ DF_Type::knowledge_scholar_flags_7, sizeof(df::knowledge_scholar_flags_7) },
	{ DF_Type::knowledge_scholar_flags_8, sizeof(df::knowledge_scholar_flags_8) },
	{ DF_Type::knowledge_scholar_flags_9, sizeof(df::knowledge_scholar_flags_9) },
	{ DF_Type::lair_type, sizeof(df::enums::lair_type::lair_type) },
	{ DF_Type::language_name, sizeof(df::language_name) },
	{ DF_Type::language_name_category, sizeof(df::enums::language_name_category::language_name_category) },
	{ DF_Type::language_symbol, sizeof(df::language_symbol) },
	{ DF_Type::language_translation, sizeof(df::language_translation) },
	{ DF_Type::language_word, sizeof(df::language_word) },
	{ DF_Type::language_word_flags, sizeof(df::language_word_flags) },
	{ DF_Type::language_word_table, sizeof(df::language_word_table) },
	{ DF_Type::large_integer, sizeof(df::large_integer) },
	{ DF_Type::large_integer__T_u, sizeof(df::large_integer::T_u) },
	{ DF_Type::layer_object, sizeof(df::layer_object) },
	{ DF_Type::layer_object_buttonst, sizeof(df::layer_object_buttonst) },
	{ DF_Type::layer_object_listst, sizeof(df::layer_object_listst) },
	{ DF_Type::layer_type, sizeof(df::enums::layer_type::layer_type) },
	{ DF_Type::lever_target_type, sizeof(df::enums::lever_target_type::lever_target_type) },
	{ DF_Type::loadgame_save_info, sizeof(df::loadgame_save_info) },
	{ DF_Type::local_population, sizeof(df::local_population) },
	{ DF_Type::local_population__T_flags, sizeof(df::local_population::T_flags) },
	{ DF_Type::location_scribe_jobs, sizeof(df::location_scribe_jobs) },
	{ DF_Type::machine, sizeof(df::machine) },
	{ DF_Type::machine__T_components, sizeof(df::machine::T_components) },
	{ DF_Type::machine__T_flags, sizeof(df::machine::T_flags) },
	{ DF_Type::machine_conn_modes, sizeof(df::machine_conn_modes) },
	{ DF_Type::machine_handler, sizeof(df::machine_handler) },
	{ DF_Type::machine_info, sizeof(df::machine_info) },
	{ DF_Type::machine_info__T_flags, sizeof(df::machine_info::T_flags) },
	{ DF_Type::machine_standardst, sizeof(df::machine_standardst) },
	{ DF_Type::machine_tile_set, sizeof(df::machine_tile_set) },
	{ DF_Type::machine_type, sizeof(df::enums::machine_type::machine_type) },
	{ DF_Type::MacroScreenLoad, sizeof(df::MacroScreenLoad) },
	{ DF_Type::MacroScreenSave, sizeof(df::MacroScreenSave) },
	{ DF_Type::manager_order, sizeof(df::manager_order) },
	{ DF_Type::manager_order__T_frequency, sizeof(df::manager_order::T_frequency) },
	{ DF_Type::manager_order_condition_item, sizeof(df::manager_order_condition_item) },
	{ DF_Type::manager_order_condition_item__T_compare_type, sizeof(df::manager_order_condition_item::T_compare_type) },
	{ DF_Type::manager_order_condition_order, sizeof(df::manager_order_condition_order) },
	{ DF_Type::manager_order_condition_order__T_condition, sizeof(df::manager_order_condition_order::T_condition) },
	{ DF_Type::manager_order_status, sizeof(df::manager_order_status) },
	{ DF_Type::manager_order_template, sizeof(df::manager_order_template) },
	{ DF_Type::mandate, sizeof(df::mandate) },
	{ DF_Type::mandate__T_mode, sizeof(df::mandate::T_mode) },
	{ DF_Type::mandate__T_punishment, sizeof(df::mandate::T_punishment) },
	{ DF_Type::map_block, sizeof(df::map_block) },
	{ DF_Type::map_block_column, sizeof(df::map_block_column) },
	{ DF_Type::map_block_column__T_unmined_glyphs, sizeof(df::map_block_column::T_unmined_glyphs) },
	{ DF_Type::map_renderer, sizeof(df::map_renderer) },
	{ DF_Type::map_renderer__T_anon_4, sizeof(df::map_renderer::T_anon_4) },
	{ DF_Type::map_viewport, sizeof(df::map_viewport) },
	{ DF_Type::masterpiece_loss_type, sizeof(df::enums::masterpiece_loss_type::masterpiece_loss_type) },
	{ DF_Type::material, sizeof(df::material) },
	{ DF_Type::material_common, sizeof(df::material_common) },
	{ DF_Type::material_common__T_hardens_with_water, sizeof(df::material_common::T_hardens_with_water) },
	{ DF_Type::material_common__T_heat, sizeof(df::material_common::T_heat) },
	{ DF_Type::material_common__T_reaction_product, sizeof(df::material_common::T_reaction_product) },
	{ DF_Type::material_common__T_strength, sizeof(df::material_common::T_strength) },
	{ DF_Type::material_flags, sizeof(df::enums::material_flags::material_flags) },
	{ DF_Type::material_template, sizeof(df::material_template) },
	{ DF_Type::material_vec_ref, sizeof(df::material_vec_ref) },
	{ DF_Type::matgloss_list, sizeof(df::matgloss_list) },
	{ DF_Type::matgloss_list__T_unk_0, sizeof(df::matgloss_list::T_unk_0) },
	{ DF_Type::matter_state, sizeof(df::enums::matter_state::matter_state) },
	{ DF_Type::meeting_context, sizeof(df::meeting_context) },
	{ DF_Type::meeting_diplomat_info, sizeof(df::meeting_diplomat_info) },
	{ DF_Type::meeting_diplomat_info__T_flags, sizeof(df::meeting_diplomat_info::T_flags) },
	{ DF_Type::meeting_event, sizeof(df::meeting_event) },
	{ DF_Type::meeting_event_type, sizeof(df::enums::meeting_event_type::meeting_event_type) },
	{ DF_Type::meeting_topic, sizeof(df::enums::meeting_topic::meeting_topic) },
	{ DF_Type::meeting_variable, sizeof(df::meeting_variable) },
	{ DF_Type::mental_attribute_type, sizeof(df::enums::mental_attribute_type::mental_attribute_type) },
	{ DF_Type::mental_picture, sizeof(df::mental_picture) },
	{ DF_Type::mental_picture__T_unk, sizeof(df::mental_picture::T_unk) },
	{ DF_Type::mental_picture_element_hfst, sizeof(df::mental_picture_element_hfst) },
	{ DF_Type::mental_picture_element_regionst, sizeof(df::mental_picture_element_regionst) },
	{ DF_Type::mental_picture_element_sitest, sizeof(df::mental_picture_element_sitest) },
	{ DF_Type::mental_picture_element_type, sizeof(df::enums::mental_picture_element_type::mental_picture_element_type) },
	{ DF_Type::mental_picture_elementst, sizeof(df::mental_picture_elementst) },
	{ DF_Type::mental_picture_property_actionst, sizeof(df::mental_picture_property_actionst) },
	{ DF_Type::mental_picture_property_adjectivest, sizeof(df::mental_picture_property_adjectivest) },
	{ DF_Type::mental_picture_property_color_patternst, sizeof(df::mental_picture_property_color_patternst) },
	{ DF_Type::mental_picture_property_datest, sizeof(df::mental_picture_property_datest) },
	{ DF_Type::mental_picture_property_emotionst, sizeof(df::mental_picture_property_emotionst) },
	{ DF_Type::mental_picture_property_positionst, sizeof(df::mental_picture_property_positionst) },
	{ DF_Type::mental_picture_property_shapest, sizeof(df::mental_picture_property_shapest) },
	{ DF_Type::mental_picture_property_timest, sizeof(df::mental_picture_property_timest) },
	{ DF_Type::mental_picture_property_toolst, sizeof(df::mental_picture_property_toolst) },
	{ DF_Type::mental_picture_property_type, sizeof(df::enums::mental_picture_property_type::mental_picture_property_type) },
	{ DF_Type::mental_picture_propertyst, sizeof(df::mental_picture_propertyst) },
	{ DF_Type::misc_trait_type, sizeof(df::enums::misc_trait_type::misc_trait_type) },
	{ DF_Type::mission, sizeof(df::mission) },
	{ DF_Type::mission__T_details, sizeof(df::mission::T_details) },
	{ DF_Type::mission__T_details__T_raid, sizeof(df::mission::T_details::T_raid) },
	{ DF_Type::mission__T_details__T_raid__T_raid_flags, sizeof(df::mission::T_details::T_raid::T_raid_flags) },
	{ DF_Type::mission__T_details__T_raid__T_raid_type, sizeof(df::mission::T_details::T_raid::T_raid_type) },
	{ DF_Type::mission__T_details__T_recovery, sizeof(df::mission::T_details::T_recovery) },
	{ DF_Type::mission__T_details__T_request, sizeof(df::mission::T_details::T_request) },
	{ DF_Type::mission__T_details__T_rescue, sizeof(df::mission::T_details::T_rescue) },
	{ DF_Type::mission__T_type, sizeof(df::mission::T_type) },
	{ DF_Type::mission_campaign_report, sizeof(df::mission_campaign_report) },
	{ DF_Type::mission_report, sizeof(df::mission_report) },
	{ DF_Type::monument_type, sizeof(df::enums::monument_type::monument_type) },
	{ DF_Type::mood_type, sizeof(df::enums::mood_type::mood_type) },
	{ DF_Type::mountain_peak_flags, sizeof(df::enums::mountain_peak_flags::mountain_peak_flags) },
	{ DF_Type::moving_party, sizeof(df::moving_party) },
	{ DF_Type::moving_party__T_members, sizeof(df::moving_party::T_members) },
	{ DF_Type::musical_form, sizeof(df::musical_form) },
	{ DF_Type::musical_form__T_flags, sizeof(df::musical_form::T_flags) },
	{ DF_Type::musical_form_feature, sizeof(df::musical_form_feature) },
	{ DF_Type::musical_form_instruments, sizeof(df::musical_form_instruments) },
	{ DF_Type::musical_form_instruments__T_substitutions, sizeof(df::musical_form_instruments::T_substitutions) },
	{ DF_Type::musical_form_interval, sizeof(df::musical_form_interval) },
	{ DF_Type::musical_form_interval__T_flags, sizeof(df::musical_form_interval::T_flags) },
	{ DF_Type::musical_form_melodies, sizeof(df::musical_form_melodies) },
	{ DF_Type::musical_form_pitch_style, sizeof(df::enums::musical_form_pitch_style::musical_form_pitch_style) },
	{ DF_Type::musical_form_purpose, sizeof(df::enums::musical_form_purpose::musical_form_purpose) },
	{ DF_Type::musical_form_style, sizeof(df::enums::musical_form_style::musical_form_style) },
	{ DF_Type::musical_form_sub4, sizeof(df::musical_form_sub4) },
	{ DF_Type::musical_form_vocals, sizeof(df::musical_form_vocals) },
	{ DF_Type::need_type, sizeof(df::enums::need_type::need_type) },
	{ DF_Type::nemesis_flags, sizeof(df::enums::nemesis_flags::nemesis_flags) },
	{ DF_Type::nemesis_offload, sizeof(df::nemesis_offload) },
	{ DF_Type::nemesis_record, sizeof(df::nemesis_record) },
	{ DF_Type::next_global_id, sizeof(df::enums::next_global_id::next_global_id) },
	{ DF_Type::occasion_schedule_feature, sizeof(df::enums::occasion_schedule_feature::occasion_schedule_feature) },
	{ DF_Type::occasion_schedule_type, sizeof(df::enums::occasion_schedule_type::occasion_schedule_type) },
	{ DF_Type::occupation, sizeof(df::occupation) },
	{ DF_Type::occupation_sub1, sizeof(df::occupation_sub1) },
	{ DF_Type::occupation_type, sizeof(df::enums::occupation_type::occupation_type) },
	{ DF_Type::ocean_wave, sizeof(df::ocean_wave) },
	{ DF_Type::organic_mat_category, sizeof(df::enums::organic_mat_category::organic_mat_category) },
	{ DF_Type::orientation_flags, sizeof(df::orientation_flags) },
	{ DF_Type::pants_flags, sizeof(df::enums::pants_flags::pants_flags) },
	{ DF_Type::part_of_speech, sizeof(df::enums::part_of_speech::part_of_speech) },
	{ DF_Type::party_info, sizeof(df::party_info) },
	{ DF_Type::pattern_type, sizeof(df::enums::pattern_type::pattern_type) },
	{ DF_Type::performance_event_type, sizeof(df::enums::performance_event_type::performance_event_type) },
	{ DF_Type::performance_participant_type, sizeof(df::enums::performance_participant_type::performance_participant_type) },
	{ DF_Type::performance_play_orderst, sizeof(df::performance_play_orderst) },
	{ DF_Type::performance_play_orderst__T_anon_4, sizeof(df::performance_play_orderst::T_anon_4) },
	{ DF_Type::personality_facet_type, sizeof(df::enums::personality_facet_type::personality_facet_type) },
	{ DF_Type::physical_attribute_type, sizeof(df::enums::physical_attribute_type::physical_attribute_type) },
	{ DF_Type::pitch_choice_type, sizeof(df::enums::pitch_choice_type::pitch_choice_type) },
	{ DF_Type::plant, sizeof(df::plant) },
	{ DF_Type::plant__T_damage_flags, sizeof(df::plant::T_damage_flags) },
	{ DF_Type::plant_flags, sizeof(df::plant_flags) },
	{ DF_Type::plant_growth, sizeof(df::plant_growth) },
	{ DF_Type::plant_growth__T_behavior, sizeof(df::plant_growth::T_behavior) },
	{ DF_Type::plant_growth__T_locations, sizeof(df::plant_growth::T_locations) },
	{ DF_Type::plant_growth_print, sizeof(df::plant_growth_print) },
	{ DF_Type::plant_raw, sizeof(df::plant_raw) },
	{ DF_Type::plant_raw__T_colors, sizeof(df::plant_raw::T_colors) },
	{ DF_Type::plant_raw__T_material_defs, sizeof(df::plant_raw::T_material_defs) },
	{ DF_Type::plant_raw__T_stockpile_growth_flags, sizeof(df::plant_raw::T_stockpile_growth_flags) },
	{ DF_Type::plant_raw__T_tiles, sizeof(df::plant_raw::T_tiles) },
	{ DF_Type::plant_raw_flags, sizeof(df::enums::plant_raw_flags::plant_raw_flags) },
	{ DF_Type::plant_tree_info, sizeof(df::plant_tree_info) },
	{ DF_Type::plant_tree_tile, sizeof(df::plant_tree_tile) },
	{ DF_Type::plot_agreement, sizeof(df::plot_agreement) },
	{ DF_Type::plot_role_type, sizeof(df::enums::plot_role_type::plot_role_type) },
	{ DF_Type::plot_strategy_type, sizeof(df::enums::plot_strategy_type::plot_strategy_type) },
	{ DF_Type::poetic_form, sizeof(df::poetic_form) },
	{ DF_Type::poetic_form__T_flags, sizeof(df::poetic_form::T_flags) },
	{ DF_Type::poetic_form_action, sizeof(df::enums::poetic_form_action::poetic_form_action) },
	{ DF_Type::poetic_form_additional_feature, sizeof(df::enums::poetic_form_additional_feature::poetic_form_additional_feature) },
	{ DF_Type::poetic_form_caesura_position, sizeof(df::enums::poetic_form_caesura_position::poetic_form_caesura_position) },
	{ DF_Type::poetic_form_feature, sizeof(df::poetic_form_feature) },
	{ DF_Type::poetic_form_mood, sizeof(df::enums::poetic_form_mood::poetic_form_mood) },
	{ DF_Type::poetic_form_part, sizeof(df::poetic_form_part) },
	{ DF_Type::poetic_form_part__T_flags, sizeof(df::poetic_form_part::T_flags) },
	{ DF_Type::poetic_form_pattern, sizeof(df::enums::poetic_form_pattern::poetic_form_pattern) },
	{ DF_Type::poetic_form_perspective, sizeof(df::poetic_form_perspective) },
	{ DF_Type::poetic_form_perspective__T_type, sizeof(df::poetic_form_perspective::T_type) },
	{ DF_Type::poetic_form_subject, sizeof(df::enums::poetic_form_subject::poetic_form_subject) },
	{ DF_Type::poetic_form_subject_target, sizeof(df::poetic_form_subject_target) },
	{ DF_Type::poetic_form_subject_target__T_Concept, sizeof(df::poetic_form_subject_target::T_Concept) },
	{ DF_Type::poetic_form_subject_target__T_Histfig, sizeof(df::poetic_form_subject_target::T_Histfig) },
	{ DF_Type::popup_message, sizeof(df::popup_message) },
	{ DF_Type::power_info, sizeof(df::power_info) },
	{ DF_Type::pressure_plate_info, sizeof(df::pressure_plate_info) },
	{ DF_Type::pressure_plate_info__T_flags, sizeof(df::pressure_plate_info::T_flags) },
	{ DF_Type::profession, sizeof(df::enums::profession::profession) },
	{ DF_Type::proj_itemst, sizeof(df::proj_itemst) },
	{ DF_Type::proj_list_link, sizeof(df::proj_list_link) },
	{ DF_Type::proj_magicst, sizeof(df::proj_magicst) },
	{ DF_Type::proj_unitst, sizeof(df::proj_unitst) },
	{ DF_Type::projectile, sizeof(df::projectile) },
	{ DF_Type::projectile_flags, sizeof(df::projectile_flags) },
	{ DF_Type::projectile_type, sizeof(df::enums::projectile_type::projectile_type) },
	{ DF_Type::property_ownership, sizeof(df::property_ownership) },
	{ DF_Type::punishment, sizeof(df::punishment) },
	{ DF_Type::reaction, sizeof(df::reaction) },
	{ DF_Type::reaction__T_building, sizeof(df::reaction::T_building) },
	{ DF_Type::reaction_category, sizeof(df::reaction_category) },
	{ DF_Type::reaction_description, sizeof(df::reaction_description) },
	{ DF_Type::reaction_flags, sizeof(df::enums::reaction_flags::reaction_flags) },
	{ DF_Type::reaction_product, sizeof(df::reaction_product) },
	{ DF_Type::reaction_product_improvement_flags, sizeof(df::enums::reaction_product_improvement_flags::reaction_product_improvement_flags) },
	{ DF_Type::reaction_product_item_flags, sizeof(df::enums::reaction_product_item_flags::reaction_product_item_flags) },
	{ DF_Type::reaction_product_item_improvementst, sizeof(df::reaction_product_item_improvementst) },
	{ DF_Type::reaction_product_item_improvementst__T_get_material, sizeof(df::reaction_product_item_improvementst::T_get_material) },
	{ DF_Type::reaction_product_itemst, sizeof(df::reaction_product_itemst) },
	{ DF_Type::reaction_product_itemst__T_get_material, sizeof(df::reaction_product_itemst::T_get_material) },
	{ DF_Type::reaction_product_type, sizeof(df::enums::reaction_product_type::reaction_product_type) },
	{ DF_Type::reaction_reagent, sizeof(df::reaction_reagent) },
	{ DF_Type::reaction_reagent_flags, sizeof(df::reaction_reagent_flags) },
	{ DF_Type::reaction_reagent_itemst, sizeof(df::reaction_reagent_itemst) },
	{ DF_Type::reaction_reagent_type, sizeof(df::enums::reaction_reagent_type::reaction_reagent_type) },
	{ DF_Type::region_block_event_sphere_fieldst, sizeof(df::region_block_event_sphere_fieldst) },
	{ DF_Type::region_block_event_type, sizeof(df::enums::region_block_event_type::region_block_event_type) },
	{ DF_Type::region_block_eventst, sizeof(df::region_block_eventst) },
	{ DF_Type::region_map_entry, sizeof(df::region_map_entry) },
	{ DF_Type::region_map_entry__T_clouds, sizeof(df::region_map_entry::T_clouds) },
	{ DF_Type::region_map_entry__T_wind, sizeof(df::region_map_entry::T_wind) },
	{ DF_Type::region_map_entry_flags, sizeof(df::enums::region_map_entry_flags::region_map_entry_flags) },
	{ DF_Type::region_weather, sizeof(df::region_weather) },
	{ DF_Type::relationship_event, sizeof(df::relationship_event) },
	{ DF_Type::relationship_event_supplement, sizeof(df::relationship_event_supplement) },
	{ DF_Type::renderer, sizeof(df::renderer) },
	{ DF_Type::report, sizeof(df::report) },
	{ DF_Type::report__T_flags, sizeof(df::report::T_flags) },
	{ DF_Type::reputation_type, sizeof(df::enums::reputation_type::reputation_type) },
	{ DF_Type::resource_allotment_data, sizeof(df::resource_allotment_data) },
	{ DF_Type::resource_allotment_data__T_unk_654, sizeof(df::resource_allotment_data::T_unk_654) },
	{ DF_Type::resource_allotment_specifier, sizeof(df::resource_allotment_specifier) },
	{ DF_Type::resource_allotment_specifier_ammost, sizeof(df::resource_allotment_specifier_ammost) },
	{ DF_Type::resource_allotment_specifier_anvilst, sizeof(df::resource_allotment_specifier_anvilst) },
	{ DF_Type::resource_allotment_specifier_armor_bodyst, sizeof(df::resource_allotment_specifier_armor_bodyst) },
	{ DF_Type::resource_allotment_specifier_armor_bootsst, sizeof(df::resource_allotment_specifier_armor_bootsst) },
	{ DF_Type::resource_allotment_specifier_armor_glovesst, sizeof(df::resource_allotment_specifier_armor_glovesst) },
	{ DF_Type::resource_allotment_specifier_armor_helmst, sizeof(df::resource_allotment_specifier_armor_helmst) },
	{ DF_Type::resource_allotment_specifier_armor_pantsst, sizeof(df::resource_allotment_specifier_armor_pantsst) },
	{ DF_Type::resource_allotment_specifier_backpackst, sizeof(df::resource_allotment_specifier_backpackst) },
	{ DF_Type::resource_allotment_specifier_bagst, sizeof(df::resource_allotment_specifier_bagst) },
	{ DF_Type::resource_allotment_specifier_bedst, sizeof(df::resource_allotment_specifier_bedst) },
	{ DF_Type::resource_allotment_specifier_bonest, sizeof(df::resource_allotment_specifier_bonest) },
	{ DF_Type::resource_allotment_specifier_boxst, sizeof(df::resource_allotment_specifier_boxst) },
	{ DF_Type::resource_allotment_specifier_cabinetst, sizeof(df::resource_allotment_specifier_cabinetst) },
	{ DF_Type::resource_allotment_specifier_chairst, sizeof(df::resource_allotment_specifier_chairst) },
	{ DF_Type::resource_allotment_specifier_cheesest, sizeof(df::resource_allotment_specifier_cheesest) },
	{ DF_Type::resource_allotment_specifier_clothing_bodyst, sizeof(df::resource_allotment_specifier_clothing_bodyst) },
	{ DF_Type::resource_allotment_specifier_clothing_bootsst, sizeof(df::resource_allotment_specifier_clothing_bootsst) },
	{ DF_Type::resource_allotment_specifier_clothing_glovesst, sizeof(df::resource_allotment_specifier_clothing_glovesst) },
	{ DF_Type::resource_allotment_specifier_clothing_helmst, sizeof(df::resource_allotment_specifier_clothing_helmst) },
	{ DF_Type::resource_allotment_specifier_clothing_pantsst, sizeof(df::resource_allotment_specifier_clothing_pantsst) },
	{ DF_Type::resource_allotment_specifier_clothst, sizeof(df::resource_allotment_specifier_clothst) },
	{ DF_Type::resource_allotment_specifier_craftsst, sizeof(df::resource_allotment_specifier_craftsst) },
	{ DF_Type::resource_allotment_specifier_cropst, sizeof(df::resource_allotment_specifier_cropst) },
	{ DF_Type::resource_allotment_specifier_extractst, sizeof(df::resource_allotment_specifier_extractst) },
	{ DF_Type::resource_allotment_specifier_flaskst, sizeof(df::resource_allotment_specifier_flaskst) },
	{ DF_Type::resource_allotment_specifier_gemsst, sizeof(df::resource_allotment_specifier_gemsst) },
	{ DF_Type::resource_allotment_specifier_hornst, sizeof(df::resource_allotment_specifier_hornst) },
	{ DF_Type::resource_allotment_specifier_leatherst, sizeof(df::resource_allotment_specifier_leatherst) },
	{ DF_Type::resource_allotment_specifier_meatst, sizeof(df::resource_allotment_specifier_meatst) },
	{ DF_Type::resource_allotment_specifier_metalst, sizeof(df::resource_allotment_specifier_metalst) },
	{ DF_Type::resource_allotment_specifier_pearlst, sizeof(df::resource_allotment_specifier_pearlst) },
	{ DF_Type::resource_allotment_specifier_powderst, sizeof(df::resource_allotment_specifier_powderst) },
	{ DF_Type::resource_allotment_specifier_quiverst, sizeof(df::resource_allotment_specifier_quiverst) },
	{ DF_Type::resource_allotment_specifier_shellst, sizeof(df::resource_allotment_specifier_shellst) },
	{ DF_Type::resource_allotment_specifier_skinst, sizeof(df::resource_allotment_specifier_skinst) },
	{ DF_Type::resource_allotment_specifier_soapst, sizeof(df::resource_allotment_specifier_soapst) },
	{ DF_Type::resource_allotment_specifier_stonest, sizeof(df::resource_allotment_specifier_stonest) },
	{ DF_Type::resource_allotment_specifier_tablest, sizeof(df::resource_allotment_specifier_tablest) },
	{ DF_Type::resource_allotment_specifier_tallowst, sizeof(df::resource_allotment_specifier_tallowst) },
	{ DF_Type::resource_allotment_specifier_threadst, sizeof(df::resource_allotment_specifier_threadst) },
	{ DF_Type::resource_allotment_specifier_toothst, sizeof(df::resource_allotment_specifier_toothst) },
	{ DF_Type::resource_allotment_specifier_type, sizeof(df::enums::resource_allotment_specifier_type::resource_allotment_specifier_type) },
	{ DF_Type::resource_allotment_specifier_weapon_meleest, sizeof(df::resource_allotment_specifier_weapon_meleest) },
	{ DF_Type::resource_allotment_specifier_weapon_rangedst, sizeof(df::resource_allotment_specifier_weapon_rangedst) },
	{ DF_Type::resource_allotment_specifier_woodst, sizeof(df::resource_allotment_specifier_woodst) },
	{ DF_Type::rhythm, sizeof(df::rhythm) },
	{ DF_Type::rhythm_sub1, sizeof(df::rhythm_sub1) },
	{ DF_Type::rhythm_sub1__T_anon_1, sizeof(df::rhythm_sub1::T_anon_1) },
	{ DF_Type::rhythm_sub2, sizeof(df::rhythm_sub2) },
	{ DF_Type::room_rent_info, sizeof(df::room_rent_info) },
	{ DF_Type::room_rent_info__T_flags, sizeof(df::room_rent_info::T_flags) },
	{ DF_Type::route_stockpile_link, sizeof(df::route_stockpile_link) },
	{ DF_Type::route_stockpile_link__T_mode, sizeof(df::route_stockpile_link::T_mode) },
	{ DF_Type::scale, sizeof(df::scale) },
	{ DF_Type::scale__T_unk1, sizeof(df::scale::T_unk1) },
	{ DF_Type::scale_sub1, sizeof(df::scale_sub1) },
	{ DF_Type::scale_sub2, sizeof(df::scale_sub2) },
	{ DF_Type::schedule_info, sizeof(df::schedule_info) },
	{ DF_Type::schedule_slot, sizeof(df::schedule_slot) },
	{ DF_Type::screw_pump_direction, sizeof(df::enums::screw_pump_direction::screw_pump_direction) },
	{ DF_Type::scribejob, sizeof(df::scribejob) },
	{ DF_Type::script_step_conditionalst, sizeof(df::script_step_conditionalst) },
	{ DF_Type::script_step_conditionalst__T_condition, sizeof(df::script_step_conditionalst::T_condition) },
	{ DF_Type::script_step_constructtopiclistst, sizeof(df::script_step_constructtopiclistst) },
	{ DF_Type::script_step_dipeventst, sizeof(df::script_step_dipeventst) },
	{ DF_Type::script_step_diphistoryst, sizeof(df::script_step_diphistoryst) },
	{ DF_Type::script_step_discussst, sizeof(df::script_step_discussst) },
	{ DF_Type::script_step_eventst, sizeof(df::script_step_eventst) },
	{ DF_Type::script_step_invasionst, sizeof(df::script_step_invasionst) },
	{ DF_Type::script_step_setvarst, sizeof(df::script_step_setvarst) },
	{ DF_Type::script_step_simpleactionst, sizeof(df::script_step_simpleactionst) },
	{ DF_Type::script_step_textviewerst, sizeof(df::script_step_textviewerst) },
	{ DF_Type::script_step_topicdiscussionst, sizeof(df::script_step_topicdiscussionst) },
	{ DF_Type::script_stepst, sizeof(df::script_stepst) },
	{ DF_Type::script_var_longst, sizeof(df::script_var_longst) },
	{ DF_Type::script_var_unitst, sizeof(df::script_var_unitst) },
	{ DF_Type::script_varst, sizeof(df::script_varst) },
	{ DF_Type::setup_character_info, sizeof(df::setup_character_info) },
	{ DF_Type::setup_character_info__T_available_embark_items, sizeof(df::setup_character_info::T_available_embark_items) },
	{ DF_Type::setup_character_info__T_page, sizeof(df::setup_character_info::T_page) },
	{ DF_Type::setup_character_info__T_sel_trait_column, sizeof(df::setup_character_info::T_sel_trait_column) },
	{ DF_Type::setup_character_info__T_status, sizeof(df::setup_character_info::T_status) },
	{ DF_Type::shoes_flags, sizeof(df::enums::shoes_flags::shoes_flags) },
	{ DF_Type::shop_type, sizeof(df::enums::shop_type::shop_type) },
	{ DF_Type::siegeengine_type, sizeof(df::enums::siegeengine_type::siegeengine_type) },
	{ DF_Type::site_building_item, sizeof(df::site_building_item) },
	{ DF_Type::site_dispute_type, sizeof(df::enums::site_dispute_type::site_dispute_type) },
	{ DF_Type::site_realization_building, sizeof(df::site_realization_building) },
	{ DF_Type::site_realization_building__T_unk_4c, sizeof(df::site_realization_building::T_unk_4c) },
	{ DF_Type::site_realization_building_info_castle_courtyardst, sizeof(df::site_realization_building_info_castle_courtyardst) },
	{ DF_Type::site_realization_building_info_castle_towerst, sizeof(df::site_realization_building_info_castle_towerst) },
	{ DF_Type::site_realization_building_info_castle_wallst, sizeof(df::site_realization_building_info_castle_wallst) },
	{ DF_Type::site_realization_building_info_hillock_housest, sizeof(df::site_realization_building_info_hillock_housest) },
	{ DF_Type::site_realization_building_info_market_squarest, sizeof(df::site_realization_building_info_market_squarest) },
	{ DF_Type::site_realization_building_info_shop_housest, sizeof(df::site_realization_building_info_shop_housest) },
	{ DF_Type::site_realization_building_info_tree_housest, sizeof(df::site_realization_building_info_tree_housest) },
	{ DF_Type::site_realization_building_info_trenchesst, sizeof(df::site_realization_building_info_trenchesst) },
	{ DF_Type::site_realization_building_info_trenchesst__T_spokes, sizeof(df::site_realization_building_info_trenchesst::T_spokes) },
	{ DF_Type::site_realization_building_infost, sizeof(df::site_realization_building_infost) },
	{ DF_Type::site_realization_building_type, sizeof(df::enums::site_realization_building_type::site_realization_building_type) },
	{ DF_Type::site_realization_crossroads, sizeof(df::site_realization_crossroads) },
	{ DF_Type::site_reputation_info, sizeof(df::site_reputation_info) },
	{ DF_Type::site_reputation_report, sizeof(df::site_reputation_report) },
	{ DF_Type::site_shop_type, sizeof(df::enums::site_shop_type::site_shop_type) },
	{ DF_Type::site_type, sizeof(df::enums::site_type::site_type) },
	{ DF_Type::skill_rating, sizeof(df::enums::skill_rating::skill_rating) },
	{ DF_Type::slab_engraving_type, sizeof(df::enums::slab_engraving_type::slab_engraving_type) },
	{ DF_Type::sound_production_type, sizeof(df::enums::sound_production_type::sound_production_type) },
	{ DF_Type::spatter, sizeof(df::spatter) },
	{ DF_Type::spatter__T_flags, sizeof(df::spatter::T_flags) },
	{ DF_Type::spatter_common, sizeof(df::spatter_common) },
	{ DF_Type::spatter_common__T_base_flags, sizeof(df::spatter_common::T_base_flags) },
	{ DF_Type::special_mat_table, sizeof(df::special_mat_table) },
	{ DF_Type::specific_ref, sizeof(df::specific_ref) },
	{ DF_Type::specific_ref__T_data, sizeof(df::specific_ref::T_data) },
	{ DF_Type::specific_ref__T_data__T_wrestle, sizeof(df::specific_ref::T_data::T_wrestle) },
	{ DF_Type::specific_ref_type, sizeof(df::enums::specific_ref_type::specific_ref_type) },
	{ DF_Type::sphere_type, sizeof(df::enums::sphere_type::sphere_type) },
	{ DF_Type::spoils_report, sizeof(df::spoils_report) },
	{ DF_Type::squad, sizeof(df::squad) },
	{ DF_Type::squad__T_rooms, sizeof(df::squad::T_rooms) },
	{ DF_Type::squad_ammo_spec, sizeof(df::squad_ammo_spec) },
	{ DF_Type::squad_ammo_spec__T_flags, sizeof(df::squad_ammo_spec::T_flags) },
	{ DF_Type::squad_event_type, sizeof(df::enums::squad_event_type::squad_event_type) },
	{ DF_Type::squad_order, sizeof(df::squad_order) },
	{ DF_Type::squad_order_cannot_reason, sizeof(df::enums::squad_order_cannot_reason::squad_order_cannot_reason) },
	{ DF_Type::squad_order_cause_trouble_for_entityst, sizeof(df::squad_order_cause_trouble_for_entityst) },
	{ DF_Type::squad_order_defend_burrowsst, sizeof(df::squad_order_defend_burrowsst) },
	{ DF_Type::squad_order_drive_armies_from_sitest, sizeof(df::squad_order_drive_armies_from_sitest) },
	{ DF_Type::squad_order_drive_entity_off_sitest, sizeof(df::squad_order_drive_entity_off_sitest) },
	{ DF_Type::squad_order_kill_hfst, sizeof(df::squad_order_kill_hfst) },
	{ DF_Type::squad_order_kill_listst, sizeof(df::squad_order_kill_listst) },
	{ DF_Type::squad_order_movest, sizeof(df::squad_order_movest) },
	{ DF_Type::squad_order_patrol_routest, sizeof(df::squad_order_patrol_routest) },
	{ DF_Type::squad_order_raid_sitest, sizeof(df::squad_order_raid_sitest) },
	{ DF_Type::squad_order_rescue_hfst, sizeof(df::squad_order_rescue_hfst) },
	{ DF_Type::squad_order_retrieve_artifactst, sizeof(df::squad_order_retrieve_artifactst) },
	{ DF_Type::squad_order_trainst, sizeof(df::squad_order_trainst) },
	{ DF_Type::squad_order_type, sizeof(df::enums::squad_order_type::squad_order_type) },
	{ DF_Type::squad_position, sizeof(df::squad_position) },
	{ DF_Type::squad_schedule_entry, sizeof(df::squad_schedule_entry) },
	{ DF_Type::squad_schedule_order, sizeof(df::squad_schedule_order) },
	{ DF_Type::squad_uniform_spec, sizeof(df::squad_uniform_spec) },
	{ DF_Type::squad_use_flags, sizeof(df::squad_use_flags) },
	{ DF_Type::stockpile_category, sizeof(df::enums::stockpile_category::stockpile_category) },
	{ DF_Type::stockpile_group_set, sizeof(df::stockpile_group_set) },
	{ DF_Type::stockpile_links, sizeof(df::stockpile_links) },
	{ DF_Type::stockpile_list, sizeof(df::enums::stockpile_list::stockpile_list) },
	{ DF_Type::stockpile_settings, sizeof(df::stockpile_settings) },
	{ DF_Type::stockpile_settings__T_ammo, sizeof(df::stockpile_settings::T_ammo) },
	{ DF_Type::stockpile_settings__T_animals, sizeof(df::stockpile_settings::T_animals) },
	{ DF_Type::stockpile_settings__T_armor, sizeof(df::stockpile_settings::T_armor) },
	{ DF_Type::stockpile_settings__T_bars_blocks, sizeof(df::stockpile_settings::T_bars_blocks) },
	{ DF_Type::stockpile_settings__T_cloth, sizeof(df::stockpile_settings::T_cloth) },
	{ DF_Type::stockpile_settings__T_coins, sizeof(df::stockpile_settings::T_coins) },
	{ DF_Type::stockpile_settings__T_finished_goods, sizeof(df::stockpile_settings::T_finished_goods) },
	{ DF_Type::stockpile_settings__T_food, sizeof(df::stockpile_settings::T_food) },
	{ DF_Type::stockpile_settings__T_furniture, sizeof(df::stockpile_settings::T_furniture) },
	{ DF_Type::stockpile_settings__T_gems, sizeof(df::stockpile_settings::T_gems) },
	{ DF_Type::stockpile_settings__T_leather, sizeof(df::stockpile_settings::T_leather) },
	{ DF_Type::stockpile_settings__T_ore, sizeof(df::stockpile_settings::T_ore) },
	{ DF_Type::stockpile_settings__T_refuse, sizeof(df::stockpile_settings::T_refuse) },
	{ DF_Type::stockpile_settings__T_sheet, sizeof(df::stockpile_settings::T_sheet) },
	{ DF_Type::stockpile_settings__T_stone, sizeof(df::stockpile_settings::T_stone) },
	{ DF_Type::stockpile_settings__T_weapons, sizeof(df::stockpile_settings::T_weapons) },
	{ DF_Type::stockpile_settings__T_wood, sizeof(df::stockpile_settings::T_wood) },
	{ DF_Type::stop_depart_condition, sizeof(df::stop_depart_condition) },
	{ DF_Type::stop_depart_condition__T_direction, sizeof(df::stop_depart_condition::T_direction) },
	{ DF_Type::stop_depart_condition__T_flags, sizeof(df::stop_depart_condition::T_flags) },
	{ DF_Type::stop_depart_condition__T_mode, sizeof(df::stop_depart_condition::T_mode) },
	{ DF_Type::strain_type, sizeof(df::enums::strain_type::strain_type) },
	{ DF_Type::stratus_type, sizeof(df::enums::stratus_type::stratus_type) },
	{ DF_Type::syndrome, sizeof(df::syndrome) },
	{ DF_Type::syndrome_flags, sizeof(df::syndrome_flags) },
	{ DF_Type::T_cursor, sizeof(df::global::T_cursor) },
	{ DF_Type::T_selection_rect, sizeof(df::global::T_selection_rect) },
	{ DF_Type::tactical_situation, sizeof(df::enums::tactical_situation::tactical_situation) },
	{ DF_Type::talk_choice, sizeof(df::talk_choice) },
	{ DF_Type::talk_choice__T_unk, sizeof(df::talk_choice::T_unk) },
	{ DF_Type::talk_choice_type, sizeof(df::enums::talk_choice_type::talk_choice_type) },
	{ DF_Type::temperaturest, sizeof(df::temperaturest) },
	{ DF_Type::temple_deity_data, sizeof(df::temple_deity_data) },
	{ DF_Type::temple_deity_type, sizeof(df::enums::temple_deity_type::temple_deity_type) },
	{ DF_Type::text_info_element_longst, sizeof(df::text_info_element_longst) },
	{ DF_Type::text_info_element_stringst, sizeof(df::text_info_element_stringst) },
	{ DF_Type::text_info_elementst, sizeof(df::text_info_elementst) },
	{ DF_Type::texture_handler, sizeof(df::texture_handler) },
	{ DF_Type::tile_bitmask, sizeof(df::tile_bitmask) },
	{ DF_Type::tile_building_occ, sizeof(df::enums::tile_building_occ::tile_building_occ) },
	{ DF_Type::tile_designation, sizeof(df::tile_designation) },
	{ DF_Type::tile_dig_designation, sizeof(df::enums::tile_dig_designation::tile_dig_designation) },
	{ DF_Type::tile_liquid, sizeof(df::enums::tile_liquid::tile_liquid) },
	{ DF_Type::tile_liquid_flow, sizeof(df::tile_liquid_flow) },
	{ DF_Type::tile_liquid_flow_dir, sizeof(df::enums::tile_liquid_flow_dir::tile_liquid_flow_dir) },
	{ DF_Type::tile_occupancy, sizeof(df::tile_occupancy) },
	{ DF_Type::tile_page, sizeof(df::tile_page) },
	{ DF_Type::tile_traffic, sizeof(df::enums::tile_traffic::tile_traffic) },
	{ DF_Type::tiletype, sizeof(df::enums::tiletype::tiletype) },
	{ DF_Type::tiletype_material, sizeof(df::enums::tiletype_material::tiletype_material) },
	{ DF_Type::tiletype_shape, sizeof(df::enums::tiletype_shape::tiletype_shape) },
	{ DF_Type::tiletype_shape_basic, sizeof(df::enums::tiletype_shape_basic::tiletype_shape_basic) },
	{ DF_Type::tiletype_special, sizeof(df::enums::tiletype_special::tiletype_special) },
	{ DF_Type::tiletype_variant, sizeof(df::enums::tiletype_variant::tiletype_variant) },
	{ DF_Type::timbre_type, sizeof(df::enums::timbre_type::timbre_type) },
	{ DF_Type::timed_event, sizeof(df::timed_event) },
	{ DF_Type::timed_event_type, sizeof(df::enums::timed_event_type::timed_event_type) },
	{ DF_Type::tissue, sizeof(df::tissue) },
	{ DF_Type::tissue_flags, sizeof(df::enums::tissue_flags::tissue_flags) },
	{ DF_Type::tissue_style_raw, sizeof(df::tissue_style_raw) },
	{ DF_Type::tissue_style_type, sizeof(df::enums::tissue_style_type::tissue_style_type) },
	{ DF_Type::tissue_template, sizeof(df::tissue_template) },
	{ DF_Type::tool_flags, sizeof(df::enums::tool_flags::tool_flags) },
	{ DF_Type::tool_uses, sizeof(df::enums::tool_uses::tool_uses) },
	{ DF_Type::tower_shape, sizeof(df::tower_shape) },
	{ DF_Type::toy_flags, sizeof(df::enums::toy_flags::toy_flags) },
	{ DF_Type::training_assignment, sizeof(df::training_assignment) },
	{ DF_Type::training_assignment__T_flags, sizeof(df::training_assignment::T_flags) },
	{ DF_Type::training_knowledge_level, sizeof(df::enums::training_knowledge_level::training_knowledge_level) },
	{ DF_Type::trap_type, sizeof(df::enums::trap_type::trap_type) },
	{ DF_Type::trapcomp_flags, sizeof(df::enums::trapcomp_flags::trapcomp_flags) },
	{ DF_Type::tree_house_type, sizeof(df::enums::tree_house_type::tree_house_type) },
	{ DF_Type::tuning_type, sizeof(df::enums::tuning_type::tuning_type) },
	{ DF_Type::ui, sizeof(df::ui) },
	{ DF_Type::ui__T_alerts, sizeof(df::ui::T_alerts) },
	{ DF_Type::ui__T_alerts__T_list, sizeof(df::ui::T_alerts::T_list) },
	{ DF_Type::ui__T_becoming_capital, sizeof(df::ui::T_becoming_capital) },
	{ DF_Type::ui__T_burrows, sizeof(df::ui::T_burrows) },
	{ DF_Type::ui__T_economy_prices, sizeof(df::ui::T_economy_prices) },
	{ DF_Type::ui__T_economy_prices__T_price_adjustment, sizeof(df::ui::T_economy_prices::T_price_adjustment) },
	{ DF_Type::ui__T_economy_prices__T_price_setter, sizeof(df::ui::T_economy_prices::T_price_setter) },
	{ DF_Type::ui__T_equipment, sizeof(df::ui::T_equipment) },
	{ DF_Type::ui__T_equipment__T_update, sizeof(df::ui::T_equipment::T_update) },
	{ DF_Type::ui__T_hauling, sizeof(df::ui::T_hauling) },
	{ DF_Type::ui__T_invasions, sizeof(df::ui::T_invasions) },
	{ DF_Type::ui__T_kitchen, sizeof(df::ui::T_kitchen) },
	{ DF_Type::ui__T_main, sizeof(df::ui::T_main) },
	{ DF_Type::ui__T_main__T_dead_citizens, sizeof(df::ui::T_main::T_dead_citizens) },
	{ DF_Type::ui__T_map_edge, sizeof(df::ui::T_map_edge) },
	{ DF_Type::ui__T_squads, sizeof(df::ui::T_squads) },
	{ DF_Type::ui__T_stockpile, sizeof(df::ui::T_stockpile) },
	{ DF_Type::ui__T_tax_collection, sizeof(df::ui::T_tax_collection) },
	{ DF_Type::ui__T_unk23c8_flags, sizeof(df::ui::T_unk23c8_flags) },
	{ DF_Type::ui__T_unk2a8c, sizeof(df::ui::T_unk2a8c) },
	{ DF_Type::ui__T_waypoints, sizeof(df::ui::T_waypoints) },
	{ DF_Type::ui__T_waypoints__T_points, sizeof(df::ui::T_waypoints::T_points) },
	{ DF_Type::ui__T_waypoints__T_routes, sizeof(df::ui::T_waypoints::T_routes) },
	{ DF_Type::ui_advmode, sizeof(df::ui_advmode) },
	{ DF_Type::ui_advmode__T_assume_identity, sizeof(df::ui_advmode::T_assume_identity) },
	{ DF_Type::ui_advmode__T_companions, sizeof(df::ui_advmode::T_companions) },
	{ DF_Type::ui_advmode__T_conversation, sizeof(df::ui_advmode::T_conversation) },
	{ DF_Type::ui_advmode__T_conversation__T_choices, sizeof(df::ui_advmode::T_conversation::T_choices) },
	{ DF_Type::ui_advmode__T_conversation__T_targets, sizeof(df::ui_advmode::T_conversation::T_targets) },
	{ DF_Type::ui_advmode__T_conversation__T_targets__T_type, sizeof(df::ui_advmode::T_conversation::T_targets::T_type) },
	{ DF_Type::ui_advmode__T_interactions, sizeof(df::ui_advmode::T_interactions) },
	{ DF_Type::ui_advmode__T_show_menu, sizeof(df::ui_advmode::T_show_menu) },
	{ DF_Type::ui_advmode__T_travel_right_map, sizeof(df::ui_advmode::T_travel_right_map) },
	{ DF_Type::ui_advmode__T_unk_3124, sizeof(df::ui_advmode::T_unk_3124) },
	{ DF_Type::ui_advmode__T_unk_3170, sizeof(df::ui_advmode::T_unk_3170) },
	{ DF_Type::ui_advmode__T_unk_3170__T_unk_2, sizeof(df::ui_advmode::T_unk_3170::T_unk_2) },
	{ DF_Type::ui_advmode__T_unk_v40_1, sizeof(df::ui_advmode::T_unk_v40_1) },
	{ DF_Type::ui_advmode__T_unk_v40_2, sizeof(df::ui_advmode::T_unk_v40_2) },
	{ DF_Type::ui_advmode__T_unk_v40_3, sizeof(df::ui_advmode::T_unk_v40_3) },
	{ DF_Type::ui_advmode__T_unk_v40_4, sizeof(df::ui_advmode::T_unk_v40_4) },
	{ DF_Type::ui_advmode__T_unk_v40_4__T_unk_v40_4a, sizeof(df::ui_advmode::T_unk_v40_4::T_unk_v40_4a) },
	{ DF_Type::ui_advmode__T_unk_v40_5, sizeof(df::ui_advmode::T_unk_v40_5) },
	{ DF_Type::ui_advmode__T_unk_v42_1, sizeof(df::ui_advmode::T_unk_v42_1) },
	{ DF_Type::ui_advmode_menu, sizeof(df::enums::ui_advmode_menu::ui_advmode_menu) },
	{ DF_Type::ui_build_item_req, sizeof(df::ui_build_item_req) },
	{ DF_Type::ui_build_selector, sizeof(df::ui_build_selector) },
	{ DF_Type::ui_hotkey, sizeof(df::ui_hotkey) },
	{ DF_Type::ui_hotkey__T_cmd, sizeof(df::ui_hotkey::T_cmd) },
	{ DF_Type::ui_look_list, sizeof(df::ui_look_list) },
	{ DF_Type::ui_look_list__T_items, sizeof(df::ui_look_list::T_items) },
	{ DF_Type::ui_look_list__T_items__T_data, sizeof(df::ui_look_list::T_items::T_data) },
	{ DF_Type::ui_look_list__T_items__T_data__T_Magma, sizeof(df::ui_look_list::T_items::T_data::T_Magma) },
	{ DF_Type::ui_look_list__T_items__T_data__T_Spatter, sizeof(df::ui_look_list::T_items::T_data::T_Spatter) },
	{ DF_Type::ui_look_list__T_items__T_data__T_Water, sizeof(df::ui_look_list::T_items::T_data::T_Water) },
	{ DF_Type::ui_look_list__T_items__T_type, sizeof(df::ui_look_list::T_items::T_type) },
	{ DF_Type::ui_sidebar_menus, sizeof(df::ui_sidebar_menus) },
	{ DF_Type::ui_sidebar_menus__T_barracks, sizeof(df::ui_sidebar_menus::T_barracks) },
	{ DF_Type::ui_sidebar_menus__T_building, sizeof(df::ui_sidebar_menus::T_building) },
	{ DF_Type::ui_sidebar_menus__T_command_line, sizeof(df::ui_sidebar_menus::T_command_line) },
	{ DF_Type::ui_sidebar_menus__T_designation, sizeof(df::ui_sidebar_menus::T_designation) },
	{ DF_Type::ui_sidebar_menus__T_designation__T_mine_mode, sizeof(df::ui_sidebar_menus::T_designation::T_mine_mode) },
	{ DF_Type::ui_sidebar_menus__T_hospital, sizeof(df::ui_sidebar_menus::T_hospital) },
	{ DF_Type::ui_sidebar_menus__T_job_details, sizeof(df::ui_sidebar_menus::T_job_details) },
	{ DF_Type::ui_sidebar_menus__T_location, sizeof(df::ui_sidebar_menus::T_location) },
	{ DF_Type::ui_sidebar_menus__T_minimap, sizeof(df::ui_sidebar_menus::T_minimap) },
	{ DF_Type::ui_sidebar_menus__T_unit, sizeof(df::ui_sidebar_menus::T_unit) },
	{ DF_Type::ui_sidebar_menus__T_unit__T_expel_error, sizeof(df::ui_sidebar_menus::T_unit::T_expel_error) },
	{ DF_Type::ui_sidebar_menus__T_unit_cursor, sizeof(df::ui_sidebar_menus::T_unit_cursor) },
	{ DF_Type::ui_sidebar_menus__T_unit_skills, sizeof(df::ui_sidebar_menus::T_unit_skills) },
	{ DF_Type::ui_sidebar_menus__T_workshop_job, sizeof(df::ui_sidebar_menus::T_workshop_job) },
	{ DF_Type::ui_sidebar_menus__T_zone, sizeof(df::ui_sidebar_menus::T_zone) },
	{ DF_Type::ui_sidebar_menus__T_zone__T_mode, sizeof(df::ui_sidebar_menus::T_zone::T_mode) },
	{ DF_Type::ui_sidebar_mode, sizeof(df::enums::ui_sidebar_mode::ui_sidebar_mode) },
	{ DF_Type::ui_unit_view_mode, sizeof(df::ui_unit_view_mode) },
	{ DF_Type::ui_unit_view_mode__T_value, sizeof(df::ui_unit_view_mode::T_value) },
	{ DF_Type::undead_flags, sizeof(df::undead_flags) },
	{ DF_Type::uniform_category, sizeof(df::enums::uniform_category::uniform_category) },
	{ DF_Type::uniform_flags, sizeof(df::uniform_flags) },
	{ DF_Type::uniform_indiv_choice, sizeof(df::uniform_indiv_choice) },
	{ DF_Type::unit, sizeof(df::unit) },
	{ DF_Type::unit__T_animal, sizeof(df::unit::T_animal) },
	{ DF_Type::unit__T_appearance, sizeof(df::unit::T_appearance) },
	{ DF_Type::unit__T_body, sizeof(df::unit::T_body) },
	{ DF_Type::unit__T_counters, sizeof(df::unit::T_counters) },
	{ DF_Type::unit__T_counters2, sizeof(df::unit::T_counters2) },
	{ DF_Type::unit__T_counters__T_soldier_mood, sizeof(df::unit::T_counters::T_soldier_mood) },
	{ DF_Type::unit__T_curse, sizeof(df::unit::T_curse) },
	{ DF_Type::unit__T_enemy, sizeof(df::unit::T_enemy) },
	{ DF_Type::unit__T_enemy__T_undead, sizeof(df::unit::T_enemy::T_undead) },
	{ DF_Type::unit__T_enemy__T_unk_448, sizeof(df::unit::T_enemy::T_unk_448) },
	{ DF_Type::unit__T_enemy__T_unk_448__T_unk, sizeof(df::unit::T_enemy::T_unk_448::T_unk) },
	{ DF_Type::unit__T_enemy__T_unk_44c, sizeof(df::unit::T_enemy::T_unk_44c) },
	{ DF_Type::unit__T_enemy__T_unk_v40_sub3, sizeof(df::unit::T_enemy::T_unk_v40_sub3) },
	{ DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_2, sizeof(df::unit::T_enemy::T_unk_v40_sub3::T_unk_2) },
	{ DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_6, sizeof(df::unit::T_enemy::T_unk_v40_sub3::T_unk_6) },
	{ DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7, sizeof(df::unit::T_enemy::T_unk_v40_sub3::T_unk_7) },
	{ DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1, sizeof(df::unit::T_enemy::T_unk_v40_sub3::T_unk_7::T_unk_sub1) },
	{ DF_Type::unit__T_enemy__T_witness_reports, sizeof(df::unit::T_enemy::T_witness_reports) },
	{ DF_Type::unit__T_job, sizeof(df::unit::T_job) },
	{ DF_Type::unit__T_meeting, sizeof(df::unit::T_meeting) },
	{ DF_Type::unit__T_meeting__T_state, sizeof(df::unit::T_meeting::T_state) },
	{ DF_Type::unit__T_military, sizeof(df::unit::T_military) },
	{ DF_Type::unit__T_military__T_pickup_flags, sizeof(df::unit::T_military::T_pickup_flags) },
	{ DF_Type::unit__T_opponent, sizeof(df::unit::T_opponent) },
	{ DF_Type::unit__T_path, sizeof(df::unit::T_path) },
	{ DF_Type::unit__T_reports, sizeof(df::unit::T_reports) },
	{ DF_Type::unit__T_status, sizeof(df::unit::T_status) },
	{ DF_Type::unit__T_status2, sizeof(df::unit::T_status2) },
	{ DF_Type::unit__T_status__T_eat_history, sizeof(df::unit::T_status::T_eat_history) },
	{ DF_Type::unit__T_status__T_eat_history__T_drink, sizeof(df::unit::T_status::T_eat_history::T_drink) },
	{ DF_Type::unit__T_status__T_eat_history__T_food, sizeof(df::unit::T_status::T_eat_history::T_food) },
	{ DF_Type::unit__T_syndromes, sizeof(df::unit::T_syndromes) },
	{ DF_Type::unit__T_unknown7, sizeof(df::unit::T_unknown7) },
	{ DF_Type::unit_action, sizeof(df::unit_action) },
	{ DF_Type::unit_action__T_data, sizeof(df::unit_action::T_data) },
	{ DF_Type::unit_action_data_attack, sizeof(df::unit_action_data_attack) },
	{ DF_Type::unit_action_data_attack__T_flags, sizeof(df::unit_action_data_attack::T_flags) },
	{ DF_Type::unit_action_data_attack__T_unk_4, sizeof(df::unit_action_data_attack::T_unk_4) },
	{ DF_Type::unit_action_data_attack__T_unk_4__T_wrestle_type, sizeof(df::unit_action_data_attack::T_unk_4::T_wrestle_type) },
	{ DF_Type::unit_action_data_block, sizeof(df::unit_action_data_block) },
	{ DF_Type::unit_action_data_climb, sizeof(df::unit_action_data_climb) },
	{ DF_Type::unit_action_data_dodge, sizeof(df::unit_action_data_dodge) },
	{ DF_Type::unit_action_data_hold_item, sizeof(df::unit_action_data_hold_item) },
	{ DF_Type::unit_action_data_hold_terrain, sizeof(df::unit_action_data_hold_terrain) },
	{ DF_Type::unit_action_data_job, sizeof(df::unit_action_data_job) },
	{ DF_Type::unit_action_data_job2, sizeof(df::unit_action_data_job2) },
	{ DF_Type::unit_action_data_jump, sizeof(df::unit_action_data_jump) },
	{ DF_Type::unit_action_data_lie_down, sizeof(df::unit_action_data_lie_down) },
	{ DF_Type::unit_action_data_move, sizeof(df::unit_action_data_move) },
	{ DF_Type::unit_action_data_move__T_flags, sizeof(df::unit_action_data_move::T_flags) },
	{ DF_Type::unit_action_data_parry, sizeof(df::unit_action_data_parry) },
	{ DF_Type::unit_action_data_push_object, sizeof(df::unit_action_data_push_object) },
	{ DF_Type::unit_action_data_recover, sizeof(df::unit_action_data_recover) },
	{ DF_Type::unit_action_data_release_item, sizeof(df::unit_action_data_release_item) },
	{ DF_Type::unit_action_data_release_terrain, sizeof(df::unit_action_data_release_terrain) },
	{ DF_Type::unit_action_data_stand_up, sizeof(df::unit_action_data_stand_up) },
	{ DF_Type::unit_action_data_suck_blood, sizeof(df::unit_action_data_suck_blood) },
	{ DF_Type::unit_action_data_talk, sizeof(df::unit_action_data_talk) },
	{ DF_Type::unit_action_data_unsteady, sizeof(df::unit_action_data_unsteady) },
	{ DF_Type::unit_action_type, sizeof(df::enums::unit_action_type::unit_action_type) },
	{ DF_Type::unit_appearance, sizeof(df::unit_appearance) },
	{ DF_Type::unit_attribute, sizeof(df::unit_attribute) },
	{ DF_Type::unit_bp_health_flags, sizeof(df::unit_bp_health_flags) },
	{ DF_Type::unit_chunk, sizeof(df::unit_chunk) },
	{ DF_Type::unit_chunk__T_units, sizeof(df::unit_chunk::T_units) },
	{ DF_Type::unit_coin_debt, sizeof(df::unit_coin_debt) },
	{ DF_Type::unit_complaint, sizeof(df::unit_complaint) },
	{ DF_Type::unit_complaint__T_type, sizeof(df::unit_complaint::T_type) },
	{ DF_Type::unit_dance_skill, sizeof(df::unit_dance_skill) },
	{ DF_Type::unit_demand, sizeof(df::unit_demand) },
	{ DF_Type::unit_demand__T_place, sizeof(df::unit_demand::T_place) },
	{ DF_Type::unit_emotion_memory, sizeof(df::unit_emotion_memory) },
	{ DF_Type::unit_flags1, sizeof(df::unit_flags1) },
	{ DF_Type::unit_flags2, sizeof(df::unit_flags2) },
	{ DF_Type::unit_flags3, sizeof(df::unit_flags3) },
	{ DF_Type::unit_flags4, sizeof(df::unit_flags4) },
	{ DF_Type::unit_genes, sizeof(df::unit_genes) },
	{ DF_Type::unit_ghost_info, sizeof(df::unit_ghost_info) },
	{ DF_Type::unit_ghost_info__T_flags, sizeof(df::unit_ghost_info::T_flags) },
	{ DF_Type::unit_ghost_info__T_target, sizeof(df::unit_ghost_info::T_target) },
	{ DF_Type::unit_health_flags, sizeof(df::unit_health_flags) },
	{ DF_Type::unit_health_info, sizeof(df::unit_health_info) },
	{ DF_Type::unit_health_info__T_op_history, sizeof(df::unit_health_info::T_op_history) },
	{ DF_Type::unit_health_info__T_op_history__T_info, sizeof(df::unit_health_info::T_op_history::T_info) },
	{ DF_Type::unit_health_info__T_op_history__T_info__T_bandage, sizeof(df::unit_health_info::T_op_history::T_info::T_bandage) },
	{ DF_Type::unit_health_info__T_op_history__T_info__T_crutch, sizeof(df::unit_health_info::T_op_history::T_info::T_crutch) },
	{ DF_Type::unit_instrument_skill, sizeof(df::unit_instrument_skill) },
	{ DF_Type::unit_inventory_item, sizeof(df::unit_inventory_item) },
	{ DF_Type::unit_inventory_item__T_mode, sizeof(df::unit_inventory_item::T_mode) },
	{ DF_Type::unit_item_use, sizeof(df::unit_item_use) },
	{ DF_Type::unit_item_wrestle, sizeof(df::unit_item_wrestle) },
	{ DF_Type::unit_labor, sizeof(df::enums::unit_labor::unit_labor) },
	{ DF_Type::unit_labor_category, sizeof(df::enums::unit_labor_category::unit_labor_category) },
	{ DF_Type::unit_misc_trait, sizeof(df::unit_misc_trait) },
	{ DF_Type::unit_musical_skill, sizeof(df::unit_musical_skill) },
	{ DF_Type::unit_path_goal, sizeof(df::enums::unit_path_goal::unit_path_goal) },
	{ DF_Type::unit_personality, sizeof(df::unit_personality) },
	{ DF_Type::unit_personality__T_dreams, sizeof(df::unit_personality::T_dreams) },
	{ DF_Type::unit_personality__T_emotions, sizeof(df::unit_personality::T_emotions) },
	{ DF_Type::unit_personality__T_emotions__T_flags, sizeof(df::unit_personality::T_emotions::T_flags) },
	{ DF_Type::unit_personality__T_flags, sizeof(df::unit_personality::T_flags) },
	{ DF_Type::unit_personality__T_memories, sizeof(df::unit_personality::T_memories) },
	{ DF_Type::unit_personality__T_memories__T_reflected_on, sizeof(df::unit_personality::T_memories::T_reflected_on) },
	{ DF_Type::unit_personality__T_needs, sizeof(df::unit_personality::T_needs) },
	{ DF_Type::unit_personality__T_unk5, sizeof(df::unit_personality::T_unk5) },
	{ DF_Type::unit_personality__T_unk_v40_2, sizeof(df::unit_personality::T_unk_v40_2) },
	{ DF_Type::unit_personality__T_unk_v40_6, sizeof(df::unit_personality::T_unk_v40_6) },
	{ DF_Type::unit_personality__T_values, sizeof(df::unit_personality::T_values) },
	{ DF_Type::unit_poetic_skill, sizeof(df::unit_poetic_skill) },
	{ DF_Type::unit_preference, sizeof(df::unit_preference) },
	{ DF_Type::unit_preference__T_type, sizeof(df::unit_preference::T_type) },
	{ DF_Type::unit_relationship_type, sizeof(df::enums::unit_relationship_type::unit_relationship_type) },
	{ DF_Type::unit_report_type, sizeof(df::enums::unit_report_type::unit_report_type) },
	{ DF_Type::unit_request, sizeof(df::unit_request) },
	{ DF_Type::unit_request__T_type, sizeof(df::unit_request::T_type) },
	{ DF_Type::unit_skill, sizeof(df::unit_skill) },
	{ DF_Type::unit_soul, sizeof(df::unit_soul) },
	{ DF_Type::unit_soul__T_performance_skills, sizeof(df::unit_soul::T_performance_skills) },
	{ DF_Type::unit_station_type, sizeof(df::enums::unit_station_type::unit_station_type) },
	{ DF_Type::unit_storage_status, sizeof(df::unit_storage_status) },
	{ DF_Type::unit_syndrome, sizeof(df::unit_syndrome) },
	{ DF_Type::unit_syndrome__T_flags, sizeof(df::unit_syndrome::T_flags) },
	{ DF_Type::unit_syndrome__T_symptoms, sizeof(df::unit_syndrome::T_symptoms) },
	{ DF_Type::unit_syndrome__T_symptoms__T_flags, sizeof(df::unit_syndrome::T_symptoms::T_flags) },
	{ DF_Type::unit_thought_type, sizeof(df::enums::unit_thought_type::unit_thought_type) },
	{ DF_Type::unit_unk_138, sizeof(df::unit_unk_138) },
	{ DF_Type::unit_wound, sizeof(df::unit_wound) },
	{ DF_Type::unit_wound__T_flags, sizeof(df::unit_wound::T_flags) },
	{ DF_Type::unit_wound__T_parts, sizeof(df::unit_wound::T_parts) },
	{ DF_Type::units_other_id, sizeof(df::enums::units_other_id::units_other_id) },
	{ DF_Type::unk_scale_enum_type, sizeof(df::enums::unk_scale_enum_type::unk_scale_enum_type) },
	{ DF_Type::vague_relationship_type, sizeof(df::enums::vague_relationship_type::vague_relationship_type) },
	{ DF_Type::value_type, sizeof(df::enums::value_type::value_type) },
	{ DF_Type::vehicle, sizeof(df::vehicle) },
	{ DF_Type::vermin, sizeof(df::vermin) },
	{ DF_Type::vermin_flags, sizeof(df::vermin_flags) },
	{ DF_Type::viewscreen, sizeof(df::viewscreen) },
	{ DF_Type::viewscreen_adopt_regionst, sizeof(df::viewscreen_adopt_regionst) },
	{ DF_Type::viewscreen_adventure_logst, sizeof(df::viewscreen_adventure_logst) },
	{ DF_Type::viewscreen_adventure_logst__T_info_mode, sizeof(df::viewscreen_adventure_logst::T_info_mode) },
	{ DF_Type::viewscreen_adventure_logst__T_mode, sizeof(df::viewscreen_adventure_logst::T_mode) },
	{ DF_Type::viewscreen_adventure_logst__T_unk_68, sizeof(df::viewscreen_adventure_logst::T_unk_68) },
	{ DF_Type::viewscreen_announcelistst, sizeof(df::viewscreen_announcelistst) },
	{ DF_Type::viewscreen_assign_display_itemst, sizeof(df::viewscreen_assign_display_itemst) },
	{ DF_Type::viewscreen_assign_display_itemst__T_sel_column, sizeof(df::viewscreen_assign_display_itemst::T_sel_column) },
	{ DF_Type::viewscreen_barterst, sizeof(df::viewscreen_barterst) },
	{ DF_Type::viewscreen_buildinglistst, sizeof(df::viewscreen_buildinglistst) },
	{ DF_Type::viewscreen_buildingst, sizeof(df::viewscreen_buildingst) },
	{ DF_Type::viewscreen_choose_start_sitest, sizeof(df::viewscreen_choose_start_sitest) },
	{ DF_Type::viewscreen_choose_start_sitest__T_finder, sizeof(df::viewscreen_choose_start_sitest::T_finder) },
	{ DF_Type::viewscreen_choose_start_sitest__T_finder__T_finder_state, sizeof(df::viewscreen_choose_start_sitest::T_finder::T_finder_state) },
	{ DF_Type::viewscreen_choose_start_sitest__T_page, sizeof(df::viewscreen_choose_start_sitest::T_page) },
	{ DF_Type::viewscreen_civlistst, sizeof(df::viewscreen_civlistst) },
	{ DF_Type::viewscreen_civlistst__T_artifact_details, sizeof(df::viewscreen_civlistst::T_artifact_details) },
	{ DF_Type::viewscreen_civlistst__T_page, sizeof(df::viewscreen_civlistst::T_page) },
	{ DF_Type::viewscreen_civlistst__T_rumors, sizeof(df::viewscreen_civlistst::T_rumors) },
	{ DF_Type::viewscreen_civlistst__T_rumors__T_type, sizeof(df::viewscreen_civlistst::T_rumors::T_type) },
	{ DF_Type::viewscreen_civlistst__T_unk_cache, sizeof(df::viewscreen_civlistst::T_unk_cache) },
	{ DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp1, sizeof(df::viewscreen_civlistst::T_unk_cache::T_tmp1) },
	{ DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp2, sizeof(df::viewscreen_civlistst::T_unk_cache::T_tmp2) },
	{ DF_Type::viewscreen_counterintelligencest, sizeof(df::viewscreen_counterintelligencest) },
	{ DF_Type::viewscreen_createquotast, sizeof(df::viewscreen_createquotast) },
	{ DF_Type::viewscreen_customize_unitst, sizeof(df::viewscreen_customize_unitst) },
	{ DF_Type::viewscreen_dungeon_monsterstatusst, sizeof(df::viewscreen_dungeon_monsterstatusst) },
	{ DF_Type::viewscreen_dungeon_wrestlest, sizeof(df::viewscreen_dungeon_wrestlest) },
	{ DF_Type::viewscreen_dungeon_wrestlest__T_unk1, sizeof(df::viewscreen_dungeon_wrestlest::T_unk1) },
	{ DF_Type::viewscreen_dungeonmodest, sizeof(df::viewscreen_dungeonmodest) },
	{ DF_Type::viewscreen_dwarfmodest, sizeof(df::viewscreen_dwarfmodest) },
	{ DF_Type::viewscreen_entityst, sizeof(df::viewscreen_entityst) },
	{ DF_Type::viewscreen_export_graphical_mapst, sizeof(df::viewscreen_export_graphical_mapst) },
	{ DF_Type::viewscreen_export_graphical_mapst__T_rgb_buffer, sizeof(df::viewscreen_export_graphical_mapst::T_rgb_buffer) },
	{ DF_Type::viewscreen_export_regionst, sizeof(df::viewscreen_export_regionst) },
	{ DF_Type::viewscreen_export_regionst__T_unk1, sizeof(df::viewscreen_export_regionst::T_unk1) },
	{ DF_Type::viewscreen_game_cleanerst, sizeof(df::viewscreen_game_cleanerst) },
	{ DF_Type::viewscreen_game_cleanerst__T_state, sizeof(df::viewscreen_game_cleanerst::T_state) },
	{ DF_Type::viewscreen_image_creator_mode, sizeof(df::enums::viewscreen_image_creator_mode::viewscreen_image_creator_mode) },
	{ DF_Type::viewscreen_image_creatorst, sizeof(df::viewscreen_image_creatorst) },
	{ DF_Type::viewscreen_image_creatorst__T_artifacts, sizeof(df::viewscreen_image_creatorst::T_artifacts) },
	{ DF_Type::viewscreen_image_creatorst__T_entities, sizeof(df::viewscreen_image_creatorst::T_entities) },
	{ DF_Type::viewscreen_image_creatorst__T_histfigs, sizeof(df::viewscreen_image_creatorst::T_histfigs) },
	{ DF_Type::viewscreen_image_creatorst__T_objects, sizeof(df::viewscreen_image_creatorst::T_objects) },
	{ DF_Type::viewscreen_image_creatorst__T_plants, sizeof(df::viewscreen_image_creatorst::T_plants) },
	{ DF_Type::viewscreen_image_creatorst__T_relationships, sizeof(df::viewscreen_image_creatorst::T_relationships) },
	{ DF_Type::viewscreen_image_creatorst__T_shapes, sizeof(df::viewscreen_image_creatorst::T_shapes) },
	{ DF_Type::viewscreen_image_creatorst__T_sites, sizeof(df::viewscreen_image_creatorst::T_sites) },
	{ DF_Type::viewscreen_image_creatorst__T_trees, sizeof(df::viewscreen_image_creatorst::T_trees) },
	{ DF_Type::viewscreen_itemst, sizeof(df::viewscreen_itemst) },
	{ DF_Type::viewscreen_joblistst, sizeof(df::viewscreen_joblistst) },
	{ DF_Type::viewscreen_jobmanagementst, sizeof(df::viewscreen_jobmanagementst) },
	{ DF_Type::viewscreen_jobst, sizeof(df::viewscreen_jobst) },
	{ DF_Type::viewscreen_justicest, sizeof(df::viewscreen_justicest) },
	{ DF_Type::viewscreen_justicest__T_cur_column, sizeof(df::viewscreen_justicest::T_cur_column) },
	{ DF_Type::viewscreen_justicest__T_interrogate_status, sizeof(df::viewscreen_justicest::T_interrogate_status) },
	{ DF_Type::viewscreen_kitchenpref_page, sizeof(df::enums::viewscreen_kitchenpref_page::viewscreen_kitchenpref_page) },
	{ DF_Type::viewscreen_kitchenprefst, sizeof(df::viewscreen_kitchenprefst) },
	{ DF_Type::viewscreen_layer, sizeof(df::viewscreen_layer) },
	{ DF_Type::viewscreen_layer_arena_creaturest, sizeof(df::viewscreen_layer_arena_creaturest) },
	{ DF_Type::viewscreen_layer_assigntradest, sizeof(df::viewscreen_layer_assigntradest) },
	{ DF_Type::viewscreen_layer_choose_language_namest, sizeof(df::viewscreen_layer_choose_language_namest) },
	{ DF_Type::viewscreen_layer_choose_language_namest__T_current_component, sizeof(df::viewscreen_layer_choose_language_namest::T_current_component) },
	{ DF_Type::viewscreen_layer_currencyst, sizeof(df::viewscreen_layer_currencyst) },
	{ DF_Type::viewscreen_layer_export_play_mapst, sizeof(df::viewscreen_layer_export_play_mapst) },
	{ DF_Type::viewscreen_layer_militaryst, sizeof(df::viewscreen_layer_militaryst) },
	{ DF_Type::viewscreen_layer_militaryst__T_ammo, sizeof(df::viewscreen_layer_militaryst::T_ammo) },
	{ DF_Type::viewscreen_layer_militaryst__T_ammo__T_add_item, sizeof(df::viewscreen_layer_militaryst::T_ammo::T_add_item) },
	{ DF_Type::viewscreen_layer_militaryst__T_ammo__T_material, sizeof(df::viewscreen_layer_militaryst::T_ammo::T_material) },
	{ DF_Type::viewscreen_layer_militaryst__T_equip, sizeof(df::viewscreen_layer_militaryst::T_equip) },
	{ DF_Type::viewscreen_layer_militaryst__T_equip__T_add_item, sizeof(df::viewscreen_layer_militaryst::T_equip::T_add_item) },
	{ DF_Type::viewscreen_layer_militaryst__T_equip__T_assigned, sizeof(df::viewscreen_layer_militaryst::T_equip::T_assigned) },
	{ DF_Type::viewscreen_layer_militaryst__T_equip__T_color, sizeof(df::viewscreen_layer_militaryst::T_equip::T_color) },
	{ DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode, sizeof(df::viewscreen_layer_militaryst::T_equip::T_edit_mode) },
	{ DF_Type::viewscreen_layer_militaryst__T_equip__T_material, sizeof(df::viewscreen_layer_militaryst::T_equip::T_material) },
	{ DF_Type::viewscreen_layer_militaryst__T_equip__T_mode, sizeof(df::viewscreen_layer_militaryst::T_equip::T_mode) },
	{ DF_Type::viewscreen_layer_militaryst__T_equip__T_uniform, sizeof(df::viewscreen_layer_militaryst::T_equip::T_uniform) },
	{ DF_Type::viewscreen_layer_militaryst__T_page, sizeof(df::viewscreen_layer_militaryst::T_page) },
	{ DF_Type::viewscreen_layer_militaryst__T_positions, sizeof(df::viewscreen_layer_militaryst::T_positions) },
	{ DF_Type::viewscreen_layer_militaryst__T_squad_members, sizeof(df::viewscreen_layer_militaryst::T_squad_members) },
	{ DF_Type::viewscreen_layer_militaryst__T_squads, sizeof(df::viewscreen_layer_militaryst::T_squads) },
	{ DF_Type::viewscreen_layer_musicsoundst, sizeof(df::viewscreen_layer_musicsoundst) },
	{ DF_Type::viewscreen_layer_noblelistst, sizeof(df::viewscreen_layer_noblelistst) },
	{ DF_Type::viewscreen_layer_noblelistst__T_candidates, sizeof(df::viewscreen_layer_noblelistst::T_candidates) },
	{ DF_Type::viewscreen_layer_noblelistst__T_info, sizeof(df::viewscreen_layer_noblelistst::T_info) },
	{ DF_Type::viewscreen_layer_noblelistst__T_mode, sizeof(df::viewscreen_layer_noblelistst::T_mode) },
	{ DF_Type::viewscreen_layer_overall_healthst, sizeof(df::viewscreen_layer_overall_healthst) },
	{ DF_Type::viewscreen_layer_reactionst, sizeof(df::viewscreen_layer_reactionst) },
	{ DF_Type::viewscreen_layer_squad_schedulest, sizeof(df::viewscreen_layer_squad_schedulest) },
	{ DF_Type::viewscreen_layer_stockpilest, sizeof(df::viewscreen_layer_stockpilest) },
	{ DF_Type::viewscreen_layer_stone_restrictionst, sizeof(df::viewscreen_layer_stone_restrictionst) },
	{ DF_Type::viewscreen_layer_unit_actionst, sizeof(df::viewscreen_layer_unit_actionst) },
	{ DF_Type::viewscreen_layer_unit_healthst, sizeof(df::viewscreen_layer_unit_healthst) },
	{ DF_Type::viewscreen_layer_unit_relationshipst, sizeof(df::viewscreen_layer_unit_relationshipst) },
	{ DF_Type::viewscreen_layer_world_gen_param_presetst, sizeof(df::viewscreen_layer_world_gen_param_presetst) },
	{ DF_Type::viewscreen_layer_world_gen_paramst, sizeof(df::viewscreen_layer_world_gen_paramst) },
	{ DF_Type::viewscreen_layer_world_gen_paramst__T_unk1, sizeof(df::viewscreen_layer_world_gen_paramst::T_unk1) },
	{ DF_Type::viewscreen_legendsst, sizeof(df::viewscreen_legendsst) },
	{ DF_Type::viewscreen_legendsst__T_anon_7, sizeof(df::viewscreen_legendsst::T_anon_7) },
	{ DF_Type::viewscreen_legendsst__T_anon_7__T_anon_3, sizeof(df::viewscreen_legendsst::T_anon_7::T_anon_3) },
	{ DF_Type::viewscreen_legendsst__T_cur_page, sizeof(df::viewscreen_legendsst::T_cur_page) },
	{ DF_Type::viewscreen_loadgamest, sizeof(df::viewscreen_loadgamest) },
	{ DF_Type::viewscreen_loadgamest__T_cur_step, sizeof(df::viewscreen_loadgamest::T_cur_step) },
	{ DF_Type::viewscreen_locationsst, sizeof(df::viewscreen_locationsst) },
	{ DF_Type::viewscreen_locationsst__T_in_edit, sizeof(df::viewscreen_locationsst::T_in_edit) },
	{ DF_Type::viewscreen_locationsst__T_menu, sizeof(df::viewscreen_locationsst::T_menu) },
	{ DF_Type::viewscreen_meetingst, sizeof(df::viewscreen_meetingst) },
	{ DF_Type::viewscreen_movieplayerst, sizeof(df::viewscreen_movieplayerst) },
	{ DF_Type::viewscreen_new_regionst, sizeof(df::viewscreen_new_regionst) },
	{ DF_Type::viewscreen_new_regionst__T_worldgen_presets, sizeof(df::viewscreen_new_regionst::T_worldgen_presets) },
	{ DF_Type::viewscreen_noblest, sizeof(df::viewscreen_noblest) },
	{ DF_Type::viewscreen_optionst, sizeof(df::viewscreen_optionst) },
	{ DF_Type::viewscreen_optionst__T_options, sizeof(df::viewscreen_optionst::T_options) },
	{ DF_Type::viewscreen_overallstatusst, sizeof(df::viewscreen_overallstatusst) },
	{ DF_Type::viewscreen_overallstatusst__T_visible_pages, sizeof(df::viewscreen_overallstatusst::T_visible_pages) },
	{ DF_Type::viewscreen_petitionsst, sizeof(df::viewscreen_petitionsst) },
	{ DF_Type::viewscreen_petst, sizeof(df::viewscreen_petst) },
	{ DF_Type::viewscreen_petst__T_animal, sizeof(df::viewscreen_petst::T_animal) },
	{ DF_Type::viewscreen_petst__T_mode, sizeof(df::viewscreen_petst::T_mode) },
	{ DF_Type::viewscreen_petst__T_trainer_mode, sizeof(df::viewscreen_petst::T_trainer_mode) },
	{ DF_Type::viewscreen_pricest, sizeof(df::viewscreen_pricest) },
	{ DF_Type::viewscreen_reportlistst, sizeof(df::viewscreen_reportlistst) },
	{ DF_Type::viewscreen_requestagreementst, sizeof(df::viewscreen_requestagreementst) },
	{ DF_Type::viewscreen_savegamest, sizeof(df::viewscreen_savegamest) },
	{ DF_Type::viewscreen_selectitemst, sizeof(df::viewscreen_selectitemst) },
	{ DF_Type::viewscreen_setupadventurest, sizeof(df::viewscreen_setupadventurest) },
	{ DF_Type::viewscreen_setupadventurest__T_page, sizeof(df::viewscreen_setupadventurest::T_page) },
	{ DF_Type::viewscreen_setupadventurest__T_races_info, sizeof(df::viewscreen_setupadventurest::T_races_info) },
	{ DF_Type::viewscreen_setupadventurest__T_status, sizeof(df::viewscreen_setupadventurest::T_status) },
	{ DF_Type::viewscreen_setupdwarfgamest, sizeof(df::viewscreen_setupdwarfgamest) },
	{ DF_Type::viewscreen_setupdwarfgamest__T_animals, sizeof(df::viewscreen_setupdwarfgamest::T_animals) },
	{ DF_Type::viewscreen_setupdwarfgamest__T_choice_types, sizeof(df::viewscreen_setupdwarfgamest::T_choice_types) },
	{ DF_Type::viewscreen_setupdwarfgamest__T_mode, sizeof(df::viewscreen_setupdwarfgamest::T_mode) },
	{ DF_Type::viewscreen_setupdwarfgamest__T_unk_v43, sizeof(df::viewscreen_setupdwarfgamest::T_unk_v43) },
	{ DF_Type::viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9, sizeof(df::viewscreen_setupdwarfgamest::T_unk_v43::T_unk_v43_sub9) },
	{ DF_Type::viewscreen_storesst, sizeof(df::viewscreen_storesst) },
	{ DF_Type::viewscreen_textviewerst, sizeof(df::viewscreen_textviewerst) },
	{ DF_Type::viewscreen_textviewerst__T_formatted_text, sizeof(df::viewscreen_textviewerst::T_formatted_text) },
	{ DF_Type::viewscreen_textviewerst__T_formatted_text__T_flags, sizeof(df::viewscreen_textviewerst::T_formatted_text::T_flags) },
	{ DF_Type::viewscreen_titlest, sizeof(df::viewscreen_titlest) },
	{ DF_Type::viewscreen_titlest__T_menu_line_id, sizeof(df::viewscreen_titlest::T_menu_line_id) },
	{ DF_Type::viewscreen_titlest__T_sel_subpage, sizeof(df::viewscreen_titlest::T_sel_subpage) },
	{ DF_Type::viewscreen_titlest__T_start_savegames, sizeof(df::viewscreen_titlest::T_start_savegames) },
	{ DF_Type::viewscreen_topicmeeting_fill_land_holder_positionsst, sizeof(df::viewscreen_topicmeeting_fill_land_holder_positionsst) },
	{ DF_Type::viewscreen_topicmeeting_takerequestsst, sizeof(df::viewscreen_topicmeeting_takerequestsst) },
	{ DF_Type::viewscreen_topicmeetingst, sizeof(df::viewscreen_topicmeetingst) },
	{ DF_Type::viewscreen_tradeagreementst, sizeof(df::viewscreen_tradeagreementst) },
	{ DF_Type::viewscreen_tradegoodsst, sizeof(df::viewscreen_tradegoodsst) },
	{ DF_Type::viewscreen_tradelistst, sizeof(df::viewscreen_tradelistst) },
	{ DF_Type::viewscreen_treasurelistst, sizeof(df::viewscreen_treasurelistst) },
	{ DF_Type::viewscreen_unitlist_page, sizeof(df::enums::viewscreen_unitlist_page::viewscreen_unitlist_page) },
	{ DF_Type::viewscreen_unitlistst, sizeof(df::viewscreen_unitlistst) },
	{ DF_Type::viewscreen_unitst, sizeof(df::viewscreen_unitst) },
	{ DF_Type::viewscreen_update_regionst, sizeof(df::viewscreen_update_regionst) },
	{ DF_Type::viewscreen_wagesst, sizeof(df::viewscreen_wagesst) },
	{ DF_Type::viewscreen_workquota_conditionst, sizeof(df::viewscreen_workquota_conditionst) },
	{ DF_Type::viewscreen_workquota_conditionst__T_mode, sizeof(df::viewscreen_workquota_conditionst::T_mode) },
	{ DF_Type::viewscreen_workquota_conditionst__T_traits, sizeof(df::viewscreen_workquota_conditionst::T_traits) },
	{ DF_Type::viewscreen_workquota_conditionst__T_traits__T_flags, sizeof(df::viewscreen_workquota_conditionst::T_traits::T_flags) },
	{ DF_Type::viewscreen_workquota_detailsst, sizeof(df::viewscreen_workquota_detailsst) },
	{ DF_Type::viewscreen_workshop_profilest, sizeof(df::viewscreen_workshop_profilest) },
	{ DF_Type::viewscreen_workshop_profilest__T_tab, sizeof(df::viewscreen_workshop_profilest::T_tab) },
	{ DF_Type::weapon_attack, sizeof(df::weapon_attack) },
	{ DF_Type::weapon_attack__T_flags, sizeof(df::weapon_attack::T_flags) },
	{ DF_Type::weapon_flags, sizeof(df::enums::weapon_flags::weapon_flags) },
	{ DF_Type::weather_type, sizeof(df::enums::weather_type::weather_type) },
	{ DF_Type::web_cluster, sizeof(df::web_cluster) },
	{ DF_Type::whereabouts_type, sizeof(df::enums::whereabouts_type::whereabouts_type) },
	{ DF_Type::widget_menu, sizeof(df::widget_menu) },
	{ DF_Type::widget_textbox, sizeof(df::widget_textbox) },
	{ DF_Type::workshop_profile, sizeof(df::workshop_profile) },
	{ DF_Type::workshop_type, sizeof(df::enums::workshop_type::workshop_type) },
	{ DF_Type::world, sizeof(df::world) },
	{ DF_Type::world__T_activities, sizeof(df::world::T_activities) },
	{ DF_Type::world__T_agreements, sizeof(df::world::T_agreements) },
	{ DF_Type::world__T_area_grasses, sizeof(df::world::T_area_grasses) },
	{ DF_Type::world__T_area_grasses__T_layer_grasses, sizeof(df::world::T_area_grasses::T_layer_grasses) },
	{ DF_Type::world__T_arena_settings, sizeof(df::world::T_arena_settings) },
	{ DF_Type::world__T_arena_spawn, sizeof(df::world::T_arena_spawn) },
	{ DF_Type::world__T_arena_spawn__T_equipment, sizeof(df::world::T_arena_spawn::T_equipment) },
	{ DF_Type::world__T_arena_spawn__T_item_types, sizeof(df::world::T_arena_spawn::T_item_types) },
	{ DF_Type::world__T_arena_spawn__T_tame, sizeof(df::world::T_arena_spawn::T_tame) },
	{ DF_Type::world__T_armies, sizeof(df::world::T_armies) },
	{ DF_Type::world__T_army_controllers, sizeof(df::world::T_army_controllers) },
	{ DF_Type::world__T_army_tracking_info, sizeof(df::world::T_army_tracking_info) },
	{ DF_Type::world__T_artifacts, sizeof(df::world::T_artifacts) },
	{ DF_Type::world__T_belief_systems, sizeof(df::world::T_belief_systems) },
	{ DF_Type::world__T_crimes, sizeof(df::world::T_crimes) },
	{ DF_Type::world__T_cultural_identities, sizeof(df::world::T_cultural_identities) },
	{ DF_Type::world__T_cur_savegame, sizeof(df::world::T_cur_savegame) },
	{ DF_Type::world__T_dance_forms, sizeof(df::world::T_dance_forms) },
	{ DF_Type::world__T_divination_sets, sizeof(df::world::T_divination_sets) },
	{ DF_Type::world__T_enemy_status_cache, sizeof(df::world::T_enemy_status_cache) },
	{ DF_Type::world__T_entities, sizeof(df::world::T_entities) },
	{ DF_Type::world__T_features, sizeof(df::world::T_features) },
	{ DF_Type::world__T_flow_engine, sizeof(df::world::T_flow_engine) },
	{ DF_Type::world__T_flow_guides, sizeof(df::world::T_flow_guides) },
	{ DF_Type::world__T_formations, sizeof(df::world::T_formations) },
	{ DF_Type::world__T_identities, sizeof(df::world::T_identities) },
	{ DF_Type::world__T_image_sets, sizeof(df::world::T_image_sets) },
	{ DF_Type::world__T_incidents, sizeof(df::world::T_incidents) },
	{ DF_Type::world__T_interaction_instances, sizeof(df::world::T_interaction_instances) },
	{ DF_Type::world__T_items, sizeof(df::world::T_items) },
	{ DF_Type::world__T_languages, sizeof(df::world::T_languages) },
	{ DF_Type::world__T_map, sizeof(df::world::T_map) },
	{ DF_Type::world__T_map_extras, sizeof(df::world::T_map_extras) },
	{ DF_Type::world__T_math, sizeof(df::world::T_math) },
	{ DF_Type::world__T_math__T_approx, sizeof(df::world::T_math::T_approx) },
	{ DF_Type::world__T_musical_forms, sizeof(df::world::T_musical_forms) },
	{ DF_Type::world__T_nemesis, sizeof(df::world::T_nemesis) },
	{ DF_Type::world__T_occupations, sizeof(df::world::T_occupations) },
	{ DF_Type::world__T_pathfinder, sizeof(df::world::T_pathfinder) },
	{ DF_Type::world__T_pathfinder__T_boundary_heap, sizeof(df::world::T_pathfinder::T_boundary_heap) },
	{ DF_Type::world__T_plants, sizeof(df::world::T_plants) },
	{ DF_Type::world__T_poetic_forms, sizeof(df::world::T_poetic_forms) },
	{ DF_Type::world__T_profession_skills, sizeof(df::world::T_profession_skills) },
	{ DF_Type::world__T_rhythms, sizeof(df::world::T_rhythms) },
	{ DF_Type::world__T_scales, sizeof(df::world::T_scales) },
	{ DF_Type::world__T_schedules, sizeof(df::world::T_schedules) },
	{ DF_Type::world__T_squads, sizeof(df::world::T_squads) },
	{ DF_Type::world__T_status, sizeof(df::world::T_status) },
	{ DF_Type::world__T_status__T_flags, sizeof(df::world::T_status::T_flags) },
	{ DF_Type::world__T_status__T_slots, sizeof(df::world::T_status::T_slots) },
	{ DF_Type::world__T_status__T_slots__T_flags, sizeof(df::world::T_status::T_slots::T_flags) },
	{ DF_Type::world__T_stockpile, sizeof(df::world::T_stockpile) },
	{ DF_Type::world__T_stockpile__T_simple1, sizeof(df::world::T_stockpile::T_simple1) },
	{ DF_Type::world__T_stockpile__T_simple2, sizeof(df::world::T_stockpile::T_simple2) },
	{ DF_Type::world__T_stockpile__T_simple3, sizeof(df::world::T_stockpile::T_simple3) },
	{ DF_Type::world__T_units, sizeof(df::world::T_units) },
	{ DF_Type::world__T_unk_131ec0, sizeof(df::world::T_unk_131ec0) },
	{ DF_Type::world__T_unk_131ef0, sizeof(df::world::T_unk_131ef0) },
	{ DF_Type::world__T_unk_131ef0__T_claims, sizeof(df::world::T_unk_131ef0::T_claims) },
	{ DF_Type::world__T_unk_19325c, sizeof(df::world::T_unk_19325c) },
	{ DF_Type::world__T_unk_19325c__T_anon_1, sizeof(df::world::T_unk_19325c::T_anon_1) },
	{ DF_Type::world__T_unk_19325c__T_anon_2, sizeof(df::world::T_unk_19325c::T_anon_2) },
	{ DF_Type::world__T_unk_19325c__T_anon_3, sizeof(df::world::T_unk_19325c::T_anon_3) },
	{ DF_Type::world__T_unk_26c678, sizeof(df::world::T_unk_26c678) },
	{ DF_Type::world__T_unk_v40_6, sizeof(df::world::T_unk_v40_6) },
	{ DF_Type::world__T_vehicles, sizeof(df::world::T_vehicles) },
	{ DF_Type::world__T_vermin, sizeof(df::world::T_vermin) },
	{ DF_Type::world__T_worldgen, sizeof(df::world::T_worldgen) },
	{ DF_Type::world__T_worldgen__T_worldgen_parms, sizeof(df::world::T_worldgen::T_worldgen_parms) },
	{ DF_Type::world__T_worldgen_coord_buf, sizeof(df::world::T_worldgen_coord_buf) },
	{ DF_Type::world__T_worldgen_status, sizeof(df::world::T_worldgen_status) },
	{ DF_Type::world__T_written_contents, sizeof(df::world::T_written_contents) },
	{ DF_Type::world_construction, sizeof(df::world_construction) },
	{ DF_Type::world_construction_bridgest, sizeof(df::world_construction_bridgest) },
	{ DF_Type::world_construction_roadst, sizeof(df::world_construction_roadst) },
	{ DF_Type::world_construction_square, sizeof(df::world_construction_square) },
	{ DF_Type::world_construction_square_bridgest, sizeof(df::world_construction_square_bridgest) },
	{ DF_Type::world_construction_square_roadst, sizeof(df::world_construction_square_roadst) },
	{ DF_Type::world_construction_square_tunnelst, sizeof(df::world_construction_square_tunnelst) },
	{ DF_Type::world_construction_square_wallst, sizeof(df::world_construction_square_wallst) },
	{ DF_Type::world_construction_tunnelst, sizeof(df::world_construction_tunnelst) },
	{ DF_Type::world_construction_type, sizeof(df::enums::world_construction_type::world_construction_type) },
	{ DF_Type::world_construction_wallst, sizeof(df::world_construction_wallst) },
	{ DF_Type::world_dat_summary, sizeof(df::world_dat_summary) },
	{ DF_Type::world_data, sizeof(df::world_data) },
	{ DF_Type::world_data__T_constructions, sizeof(df::world_data::T_constructions) },
	{ DF_Type::world_data__T_feature_map, sizeof(df::world_data::T_feature_map) },
	{ DF_Type::world_data__T_feature_map__T_features, sizeof(df::world_data::T_feature_map::T_features) },
	{ DF_Type::world_data__T_flip_latitude, sizeof(df::world_data::T_flip_latitude) },
	{ DF_Type::world_data__T_mountain_peaks, sizeof(df::world_data::T_mountain_peaks) },
	{ DF_Type::world_data__T_unk_274, sizeof(df::world_data::T_unk_274) },
	{ DF_Type::world_data__T_unk_274__T_unk_10, sizeof(df::world_data::T_unk_274::T_unk_10) },
	{ DF_Type::world_data__T_unk_482f8, sizeof(df::world_data::T_unk_482f8) },
	{ DF_Type::world_data__T_unk_b4, sizeof(df::world_data::T_unk_b4) },
	{ DF_Type::world_gen_param_basest, sizeof(df::world_gen_param_basest) },
	{ DF_Type::world_gen_param_charst, sizeof(df::world_gen_param_charst) },
	{ DF_Type::world_gen_param_memberst, sizeof(df::world_gen_param_memberst) },
	{ DF_Type::world_gen_param_seedst, sizeof(df::world_gen_param_seedst) },
	{ DF_Type::world_gen_param_valuest, sizeof(df::world_gen_param_valuest) },
	{ DF_Type::world_geo_biome, sizeof(df::world_geo_biome) },
	{ DF_Type::world_geo_layer, sizeof(df::world_geo_layer) },
	{ DF_Type::world_history, sizeof(df::world_history) },
	{ DF_Type::world_history__T_event_collections, sizeof(df::world_history::T_event_collections) },
	{ DF_Type::world_history__T_intrigues, sizeof(df::world_history::T_intrigues) },
	{ DF_Type::world_history__T_intrigues__T_anon_1, sizeof(df::world_history::T_intrigues::T_anon_1) },
	{ DF_Type::world_landmass, sizeof(df::world_landmass) },
	{ DF_Type::world_object_data, sizeof(df::world_object_data) },
	{ DF_Type::world_object_data__T_offloaded_buildings, sizeof(df::world_object_data::T_offloaded_buildings) },
	{ DF_Type::world_object_data__T_offloaded_items, sizeof(df::world_object_data::T_offloaded_items) },
	{ DF_Type::world_object_data__T_unk_94, sizeof(df::world_object_data::T_unk_94) },
	{ DF_Type::world_population, sizeof(df::world_population) },
	{ DF_Type::world_population_ref, sizeof(df::world_population_ref) },
	{ DF_Type::world_population_type, sizeof(df::enums::world_population_type::world_population_type) },
	{ DF_Type::world_raws, sizeof(df::world_raws) },
	{ DF_Type::world_raws__T_bodyglosses, sizeof(df::world_raws::T_bodyglosses) },
	{ DF_Type::world_raws__T_buildings, sizeof(df::world_raws::T_buildings) },
	{ DF_Type::world_raws__T_descriptors, sizeof(df::world_raws::T_descriptors) },
	{ DF_Type::world_raws__T_effects, sizeof(df::world_raws::T_effects) },
	{ DF_Type::world_raws__T_itemdefs, sizeof(df::world_raws::T_itemdefs) },
	{ DF_Type::world_raws__T_language, sizeof(df::world_raws::T_language) },
	{ DF_Type::world_raws__T_plants, sizeof(df::world_raws::T_plants) },
	{ DF_Type::world_raws__T_reactions, sizeof(df::world_raws::T_reactions) },
	{ DF_Type::world_raws__T_syndromes, sizeof(df::world_raws::T_syndromes) },
	{ DF_Type::world_region, sizeof(df::world_region) },
	{ DF_Type::world_region_details, sizeof(df::world_region_details) },
	{ DF_Type::world_region_details__T_edges, sizeof(df::world_region_details::T_edges) },
	{ DF_Type::world_region_details__T_other_features, sizeof(df::world_region_details::T_other_features) },
	{ DF_Type::world_region_details__T_rivers_horizontal, sizeof(df::world_region_details::T_rivers_horizontal) },
	{ DF_Type::world_region_details__T_rivers_vertical, sizeof(df::world_region_details::T_rivers_vertical) },
	{ DF_Type::world_region_feature, sizeof(df::world_region_feature) },
	{ DF_Type::world_region_type, sizeof(df::enums::world_region_type::world_region_type) },
	{ DF_Type::world_river, sizeof(df::world_river) },
	{ DF_Type::world_site, sizeof(df::world_site) },
	{ DF_Type::world_site__T_subtype_info, sizeof(df::world_site::T_subtype_info) },
	{ DF_Type::world_site__T_unk_1, sizeof(df::world_site::T_unk_1) },
	{ DF_Type::world_site__T_unk_118, sizeof(df::world_site::T_unk_118) },
	{ DF_Type::world_site__T_unk_13c, sizeof(df::world_site::T_unk_13c) },
	{ DF_Type::world_site__T_unk_188, sizeof(df::world_site::T_unk_188) },
	{ DF_Type::world_site__T_unk_188__T_unk1, sizeof(df::world_site::T_unk_188::T_unk1) },
	{ DF_Type::world_site__T_unk_1__T_units, sizeof(df::world_site::T_unk_1::T_units) },
	{ DF_Type::world_site__T_unk_21c, sizeof(df::world_site::T_unk_21c) },
	{ DF_Type::world_site__T_unk_v40_2, sizeof(df::world_site::T_unk_v40_2) },
	{ DF_Type::world_site__T_unk_v40_4a, sizeof(df::world_site::T_unk_v40_4a) },
	{ DF_Type::world_site__T_unk_v40_4b, sizeof(df::world_site::T_unk_v40_4b) },
	{ DF_Type::world_site__T_unk_v40_4c, sizeof(df::world_site::T_unk_v40_4c) },
	{ DF_Type::world_site__T_unk_v40_4d, sizeof(df::world_site::T_unk_v40_4d) },
	{ DF_Type::world_site__T_unk_v40_4d__T_anon_1, sizeof(df::world_site::T_unk_v40_4d::T_anon_1) },
	{ DF_Type::world_site__T_unk_v43_2, sizeof(df::world_site::T_unk_v43_2) },
	{ DF_Type::world_site__T_unk_v47_1, sizeof(df::world_site::T_unk_v47_1) },
	{ DF_Type::world_site__T_unk_v47_1__T_unk_1, sizeof(df::world_site::T_unk_v47_1::T_unk_1) },
	{ DF_Type::world_site_flags, sizeof(df::enums::world_site_flags::world_site_flags) },
	{ DF_Type::world_site_inhabitant, sizeof(df::world_site_inhabitant) },
	{ DF_Type::world_site_realization, sizeof(df::world_site_realization) },
	{ DF_Type::world_site_realization__T_areas, sizeof(df::world_site_realization::T_areas) },
	{ DF_Type::world_site_realization__T_areas__T_type, sizeof(df::world_site_realization::T_areas::T_type) },
	{ DF_Type::world_site_realization__T_building_map, sizeof(df::world_site_realization::T_building_map) },
	{ DF_Type::world_site_realization__T_river_map, sizeof(df::world_site_realization::T_river_map) },
	{ DF_Type::world_site_realization__T_unk_193bc, sizeof(df::world_site_realization::T_unk_193bc) },
	{ DF_Type::world_site_realization__T_unk_193bc__T_unk_8, sizeof(df::world_site_realization::T_unk_193bc::T_unk_8) },
	{ DF_Type::world_site_realization__T_unk_55e8, sizeof(df::world_site_realization::T_unk_55e8) },
	{ DF_Type::world_site_realization__T_unk_55e8__T_unk_v40_2, sizeof(df::world_site_realization::T_unk_55e8::T_unk_v40_2) },
	{ DF_Type::world_site_type, sizeof(df::enums::world_site_type::world_site_type) },
	{ DF_Type::world_site_unk130, sizeof(df::world_site_unk130) },
	{ DF_Type::world_site_unk130__T_unk_4, sizeof(df::world_site_unk130::T_unk_4) },
	{ DF_Type::world_underground_region, sizeof(df::world_underground_region) },
	{ DF_Type::world_underground_region__T_type, sizeof(df::world_underground_region::T_type) },
	{ DF_Type::world_unk26c678_unk38, sizeof(df::world_unk26c678_unk38) },
	{ DF_Type::world_unk_20, sizeof(df::world_unk_20) },
	{ DF_Type::world_unk_20__T_anon_7, sizeof(df::world_unk_20::T_anon_7) },
	{ DF_Type::world_unk_6c, sizeof(df::world_unk_6c) },
	{ DF_Type::world_unk_a8, sizeof(df::world_unk_a8) },
	{ DF_Type::world_unk_b4, sizeof(df::world_unk_b4) },
	{ DF_Type::world_unk_c0, sizeof(df::world_unk_c0) },
	{ DF_Type::world_unk_c0__T_anon_7, sizeof(df::world_unk_c0::T_anon_7) },
	{ DF_Type::worldgen_range_type, sizeof(df::enums::worldgen_range_type::worldgen_range_type) },
	{ DF_Type::worldgen_region_type, sizeof(df::enums::worldgen_region_type::worldgen_region_type) },
	{ DF_Type::wound_curse_info, sizeof(df::wound_curse_info) },
	{ DF_Type::wound_curse_info__T_timing, sizeof(df::wound_curse_info::T_timing) },
	{ DF_Type::wound_damage_flags1, sizeof(df::wound_damage_flags1) },
	{ DF_Type::wound_damage_flags2, sizeof(df::wound_damage_flags2) },
	{ DF_Type::wound_effect_type, sizeof(df::enums::wound_effect_type::wound_effect_type) },
	{ DF_Type::written_content, sizeof(df::written_content) },
	{ DF_Type::written_content_style, sizeof(df::enums::written_content_style::written_content_style) },
	{ DF_Type::written_content_type, sizeof(df::enums::written_content_type::written_content_type) },
	{ DF_Type::z_level_flags, sizeof(df::z_level_flags) },
	{ DF_Type::zoom_commands, sizeof(df::enums::zoom_commands::zoom_commands) },
	{ DF_Type::None, 0 },
	{ DF_Type::int64_t, sizeof(int64_t) },
	{ DF_Type::uint64_t, sizeof(uint64_t) },
	{ DF_Type::int32_t, sizeof(int32_t) },
	{ DF_Type::int16_t, sizeof(int16_t) },
	{ DF_Type::uint32_t, sizeof(uint32_t) },
	{ DF_Type::uint16_t, sizeof(uint16_t) },
	{ DF_Type::uint8_t, sizeof(uint8_t) },
	{ DF_Type::int8_t, sizeof(int8_t) },
	{ DF_Type::Char, sizeof(char) },
	{ DF_Type::Long, sizeof(long) },
	{ DF_Type::Bool, sizeof(bool) },
	{ DF_Type::S_float, sizeof(float) },
	{ DF_Type::D_float, sizeof(float) },
	{ DF_Type::S_double, sizeof(double) }
};
std::size_t size_of_DF_Type(DF_Type p_type)
{
	auto result = DF_types_size_table[p_type];
	return result;
}

// Function to return the string value of this enum class
std::string DF_Type_to_string(DF_Type p_type)
{
    switch (p_type)
    {
        case DF_Type::None: return "None";
        case DF_Type::int64_t: return "int64_t";
        case DF_Type::uint64_t: return "uint64_t";
        case DF_Type::int32_t: return "int32_t";
        case DF_Type::int16_t: return "int16_t";
        case DF_Type::uint32_t: return "uint32_t";
        case DF_Type::uint16_t: return "uint16_t";
        case DF_Type::uint8_t: return "uint8_t";
        case DF_Type::int8_t: return "int8_t";
        case DF_Type::Void: return "Void";
        case DF_Type::Char: return "Char";
        case DF_Type::Long: return "Long";
        case DF_Type::Bool: return "Bool";
        case DF_Type::Stl_string: return "Stl_string";
        case DF_Type::Static_string: return "Static_string";
        case DF_Type::Ptr_string: return "Ptr_string";
        case DF_Type::S_float: return "S_float";
        case DF_Type::D_float: return "D_float";
        case DF_Type::S_double: return "S_double";
        case DF_Type::Padding: return "Padding";
        case DF_Type::Stl_fstream: return "Fstream";
		case DF_Type::abstract_building: return "abstract_building";
		case DF_Type::abstract_building__T_inhabitants: return "abstract_building__T_inhabitants";
		case DF_Type::abstract_building__T_unk1: return "abstract_building__T_unk1";
		case DF_Type::abstract_building_contents: return "abstract_building_contents";
		case DF_Type::abstract_building_counting_housest: return "abstract_building_counting_housest";
		case DF_Type::abstract_building_dark_towerst: return "abstract_building_dark_towerst";
		case DF_Type::abstract_building_dungeonst: return "abstract_building_dungeonst";
		case DF_Type::abstract_building_dungeonst__T_dungeon_type: return "abstract_building_dungeonst__T_dungeon_type";
		case DF_Type::abstract_building_flags: return "abstract_building_flags";
		case DF_Type::abstract_building_guildhallst: return "abstract_building_guildhallst";
		case DF_Type::abstract_building_inn_tavernst: return "abstract_building_inn_tavernst";
		case DF_Type::abstract_building_inn_tavernst__T_room_info: return "abstract_building_inn_tavernst__T_room_info";
		case DF_Type::abstract_building_keepst: return "abstract_building_keepst";
		case DF_Type::abstract_building_libraryst: return "abstract_building_libraryst";
		case DF_Type::abstract_building_marketst: return "abstract_building_marketst";
		case DF_Type::abstract_building_mead_hallst: return "abstract_building_mead_hallst";
		case DF_Type::abstract_building_templest: return "abstract_building_templest";
		case DF_Type::abstract_building_tombst: return "abstract_building_tombst";
		case DF_Type::abstract_building_towerst: return "abstract_building_towerst";
		case DF_Type::abstract_building_type: return "abstract_building_type";
		case DF_Type::abstract_building_underworld_spirest: return "abstract_building_underworld_spirest";
		case DF_Type::abstract_building_unk: return "abstract_building_unk";
		case DF_Type::abstract_building_unk__T_anon_1: return "abstract_building_unk__T_anon_1";
		case DF_Type::active_script_var_longst: return "active_script_var_longst";
		case DF_Type::active_script_var_unitst: return "active_script_var_unitst";
		case DF_Type::active_script_varst: return "active_script_varst";
		case DF_Type::activity_entry: return "activity_entry";
		case DF_Type::activity_entry_type: return "activity_entry_type";
		case DF_Type::activity_event: return "activity_event";
		case DF_Type::activity_event__T_flags: return "activity_event__T_flags";
		case DF_Type::activity_event__T_unk_v42_1: return "activity_event__T_unk_v42_1";
		case DF_Type::activity_event__T_unk_v42_2: return "activity_event__T_unk_v42_2";
		case DF_Type::activity_event_combat_trainingst: return "activity_event_combat_trainingst";
		case DF_Type::activity_event_conflictst: return "activity_event_conflictst";
		case DF_Type::activity_event_conflictst__T_sides: return "activity_event_conflictst__T_sides";
		case DF_Type::activity_event_conflictst__T_sides__T_enemies: return "activity_event_conflictst__T_sides__T_enemies";
		case DF_Type::activity_event_conversationst: return "activity_event_conversationst";
		case DF_Type::activity_event_conversationst__T_anon_6: return "activity_event_conversationst__T_anon_6";
		case DF_Type::activity_event_conversationst__T_flags2: return "activity_event_conversationst__T_flags2";
		case DF_Type::activity_event_conversationst__T_participants: return "activity_event_conversationst__T_participants";
		case DF_Type::activity_event_conversationst__T_turns: return "activity_event_conversationst__T_turns";
		case DF_Type::activity_event_conversationst__T_unk2: return "activity_event_conversationst__T_unk2";
		case DF_Type::activity_event_conversationst__T_unk_b4: return "activity_event_conversationst__T_unk_b4";
		case DF_Type::activity_event_copy_written_contentst: return "activity_event_copy_written_contentst";
		case DF_Type::activity_event_copy_written_contentst__T_flagsmaybe: return "activity_event_copy_written_contentst__T_flagsmaybe";
		case DF_Type::activity_event_discuss_topicst: return "activity_event_discuss_topicst";
		case DF_Type::activity_event_encounterst: return "activity_event_encounterst";
		case DF_Type::activity_event_encounterst__T_anon_1: return "activity_event_encounterst__T_anon_1";
		case DF_Type::activity_event_encounterst__T_anon_2: return "activity_event_encounterst__T_anon_2";
		case DF_Type::activity_event_fill_service_orderst: return "activity_event_fill_service_orderst";
		case DF_Type::activity_event_guardst: return "activity_event_guardst";
		case DF_Type::activity_event_harassmentst: return "activity_event_harassmentst";
		case DF_Type::activity_event_harassmentst__T_anon_2: return "activity_event_harassmentst__T_anon_2";
		case DF_Type::activity_event_individual_skill_drillst: return "activity_event_individual_skill_drillst";
		case DF_Type::activity_event_make_believest: return "activity_event_make_believest";
		case DF_Type::activity_event_participants: return "activity_event_participants";
		case DF_Type::activity_event_performancest: return "activity_event_performancest";
		case DF_Type::activity_event_performancest__T_participant_actions: return "activity_event_performancest__T_participant_actions";
		case DF_Type::activity_event_play_with_toyst: return "activity_event_play_with_toyst";
		case DF_Type::activity_event_play_with_toyst__T_unk: return "activity_event_play_with_toyst__T_unk";
		case DF_Type::activity_event_playst: return "activity_event_playst";
		case DF_Type::activity_event_ponder_topicst: return "activity_event_ponder_topicst";
		case DF_Type::activity_event_prayerst: return "activity_event_prayerst";
		case DF_Type::activity_event_ranged_practicest: return "activity_event_ranged_practicest";
		case DF_Type::activity_event_readst: return "activity_event_readst";
		case DF_Type::activity_event_researchst: return "activity_event_researchst";
		case DF_Type::activity_event_reunionst: return "activity_event_reunionst";
		case DF_Type::activity_event_skill_demonstrationst: return "activity_event_skill_demonstrationst";
		case DF_Type::activity_event_socializest: return "activity_event_socializest";
		case DF_Type::activity_event_sparringst: return "activity_event_sparringst";
		case DF_Type::activity_event_sparringst__T_groups: return "activity_event_sparringst__T_groups";
		case DF_Type::activity_event_store_objectst: return "activity_event_store_objectst";
		case DF_Type::activity_event_teach_topicst: return "activity_event_teach_topicst";
		case DF_Type::activity_event_training_sessionst: return "activity_event_training_sessionst";
		case DF_Type::activity_event_type: return "activity_event_type";
		case DF_Type::activity_event_worshipst: return "activity_event_worshipst";
		case DF_Type::activity_event_writest: return "activity_event_writest";
		case DF_Type::activity_info: return "activity_info";
		case DF_Type::activity_info__T_flags: return "activity_info__T_flags";
		case DF_Type::adventure_environment_ingest_from_containerst: return "adventure_environment_ingest_from_containerst";
		case DF_Type::adventure_environment_ingest_materialst: return "adventure_environment_ingest_materialst";
		case DF_Type::adventure_environment_optionst: return "adventure_environment_optionst";
		case DF_Type::adventure_environment_pickup_chop_treest: return "adventure_environment_pickup_chop_treest";
		case DF_Type::adventure_environment_pickup_ignite_vegst: return "adventure_environment_pickup_ignite_vegst";
		case DF_Type::adventure_environment_pickup_make_campfirest: return "adventure_environment_pickup_make_campfirest";
		case DF_Type::adventure_environment_pickup_vermin_eventst: return "adventure_environment_pickup_vermin_eventst";
		case DF_Type::adventure_environment_place_in_bld_containerst: return "adventure_environment_place_in_bld_containerst";
		case DF_Type::adventure_environment_place_in_it_containerst: return "adventure_environment_place_in_it_containerst";
		case DF_Type::adventure_environment_unit_suck_bloodst: return "adventure_environment_unit_suck_bloodst";
		case DF_Type::adventure_item_interact_choicest: return "adventure_item_interact_choicest";
		case DF_Type::adventure_item_interact_fill_from_containerst: return "adventure_item_interact_fill_from_containerst";
		case DF_Type::adventure_item_interact_fill_with_materialst: return "adventure_item_interact_fill_with_materialst";
		case DF_Type::adventure_item_interact_give_namest: return "adventure_item_interact_give_namest";
		case DF_Type::adventure_item_interact_heat_from_tilest: return "adventure_item_interact_heat_from_tilest";
		case DF_Type::adventure_item_interact_pull_outst: return "adventure_item_interact_pull_outst";
		case DF_Type::adventure_item_interact_readst: return "adventure_item_interact_readst";
		case DF_Type::adventure_item_interact_strugglest: return "adventure_item_interact_strugglest";
		case DF_Type::adventure_log_item: return "adventure_log_item";
		case DF_Type::adventure_movement_attack_creaturest: return "adventure_movement_attack_creaturest";
		case DF_Type::adventure_movement_building_interactst: return "adventure_movement_building_interactst";
		case DF_Type::adventure_movement_climbst: return "adventure_movement_climbst";
		case DF_Type::adventure_movement_hold_itemst: return "adventure_movement_hold_itemst";
		case DF_Type::adventure_movement_hold_tilest: return "adventure_movement_hold_tilest";
		case DF_Type::adventure_movement_item_interact_guidest: return "adventure_movement_item_interact_guidest";
		case DF_Type::adventure_movement_item_interact_pushst: return "adventure_movement_item_interact_pushst";
		case DF_Type::adventure_movement_item_interact_ridest: return "adventure_movement_item_interact_ridest";
		case DF_Type::adventure_movement_item_interactst: return "adventure_movement_item_interactst";
		case DF_Type::adventure_movement_movest: return "adventure_movement_movest";
		case DF_Type::adventure_movement_optionst: return "adventure_movement_optionst";
		case DF_Type::adventure_movement_release_hold_itemst: return "adventure_movement_release_hold_itemst";
		case DF_Type::adventure_movement_release_hold_tilest: return "adventure_movement_release_hold_tilest";
		case DF_Type::adventure_option_eat_item_contaminantst: return "adventure_option_eat_item_contaminantst";
		case DF_Type::adventure_option_eat_unit_contaminantst: return "adventure_option_eat_unit_contaminantst";
		case DF_Type::adventure_option_view_contaminantst: return "adventure_option_view_contaminantst";
		case DF_Type::adventure_optionst: return "adventure_optionst";
		case DF_Type::adventurer_attribute_level: return "adventurer_attribute_level";
		case DF_Type::agreement: return "agreement";
		case DF_Type::agreement__T_flags: return "agreement__T_flags";
		case DF_Type::agreement_details: return "agreement_details";
		case DF_Type::agreement_details__T_data: return "agreement_details__T_data";
		case DF_Type::agreement_details_data_citizenship: return "agreement_details_data_citizenship";
		case DF_Type::agreement_details_data_demonic_binding: return "agreement_details_data_demonic_binding";
		case DF_Type::agreement_details_data_join_party: return "agreement_details_data_join_party";
		case DF_Type::agreement_details_data_location: return "agreement_details_data_location";
		case DF_Type::agreement_details_data_parley: return "agreement_details_data_parley";
		case DF_Type::agreement_details_data_plot_abduct: return "agreement_details_data_plot_abduct";
		case DF_Type::agreement_details_data_plot_assassination: return "agreement_details_data_plot_assassination";
		case DF_Type::agreement_details_data_plot_conviction: return "agreement_details_data_plot_conviction";
		case DF_Type::agreement_details_data_plot_frame_treason: return "agreement_details_data_plot_frame_treason";
		case DF_Type::agreement_details_data_plot_induce_war: return "agreement_details_data_plot_induce_war";
		case DF_Type::agreement_details_data_plot_infiltration_coup: return "agreement_details_data_plot_infiltration_coup";
		case DF_Type::agreement_details_data_plot_sabotage: return "agreement_details_data_plot_sabotage";
		case DF_Type::agreement_details_data_plot_steal_artifact: return "agreement_details_data_plot_steal_artifact";
		case DF_Type::agreement_details_data_position_corruption: return "agreement_details_data_position_corruption";
		case DF_Type::agreement_details_data_promise_position: return "agreement_details_data_promise_position";
		case DF_Type::agreement_details_data_residency: return "agreement_details_data_residency";
		case DF_Type::agreement_details_type: return "agreement_details_type";
		case DF_Type::agreement_party: return "agreement_party";
		case DF_Type::agreement_party__T_anon_1: return "agreement_party__T_anon_1";
		case DF_Type::ammo_flags: return "ammo_flags";
		case DF_Type::animal_training_level: return "animal_training_level";
		case DF_Type::announcement_flags: return "announcement_flags";
		case DF_Type::announcement_type: return "announcement_type";
		case DF_Type::announcements: return "announcements";
		case DF_Type::appearance_modifier_growth_interval: return "appearance_modifier_growth_interval";
		case DF_Type::appearance_modifier_type: return "appearance_modifier_type";
		case DF_Type::architectural_element: return "architectural_element";
		case DF_Type::armor_flags: return "armor_flags";
		case DF_Type::armor_general_flags: return "armor_general_flags";
		case DF_Type::armor_properties: return "armor_properties";
		case DF_Type::army: return "army";
		case DF_Type::army__T_members: return "army__T_members";
		case DF_Type::army__T_unk_2c: return "army__T_unk_2c";
		case DF_Type::army_controller: return "army_controller";
		case DF_Type::army_controller__T_type: return "army_controller__T_type";
		case DF_Type::army_controller__T_unk_64: return "army_controller__T_unk_64";
		case DF_Type::army_controller_invasion: return "army_controller_invasion";
		case DF_Type::army_controller_invasion__T_anon_1: return "army_controller_invasion__T_anon_1";
		case DF_Type::army_controller_sub1: return "army_controller_sub1";
		case DF_Type::army_controller_sub11: return "army_controller_sub11";
		case DF_Type::army_controller_sub11__T_anon_3: return "army_controller_sub11__T_anon_3";
		case DF_Type::army_controller_sub12: return "army_controller_sub12";
		case DF_Type::army_controller_sub12__T_unk_4: return "army_controller_sub12__T_unk_4";
		case DF_Type::army_controller_sub13: return "army_controller_sub13";
		case DF_Type::army_controller_sub13__T_anon_4: return "army_controller_sub13__T_anon_4";
		case DF_Type::army_controller_sub14: return "army_controller_sub14";
		case DF_Type::army_controller_sub14__T_anon_4: return "army_controller_sub14__T_anon_4";
		case DF_Type::army_controller_sub15: return "army_controller_sub15";
		case DF_Type::army_controller_sub15__T_anon_3: return "army_controller_sub15__T_anon_3";
		case DF_Type::army_controller_sub16: return "army_controller_sub16";
		case DF_Type::army_controller_sub17: return "army_controller_sub17";
		case DF_Type::army_controller_sub18: return "army_controller_sub18";
		case DF_Type::army_controller_sub4: return "army_controller_sub4";
		case DF_Type::army_controller_sub4__T_unk_2: return "army_controller_sub4__T_unk_2";
		case DF_Type::army_controller_sub5: return "army_controller_sub5";
		case DF_Type::army_controller_sub6: return "army_controller_sub6";
		case DF_Type::army_controller_sub7: return "army_controller_sub7";
		case DF_Type::army_controller_sub7__T_anon_3: return "army_controller_sub7__T_anon_3";
		case DF_Type::army_controller_villain_visiting: return "army_controller_villain_visiting";
		case DF_Type::army_flags: return "army_flags";
		case DF_Type::art_facet_type: return "art_facet_type";
		case DF_Type::art_image: return "art_image";
		case DF_Type::art_image_chunk: return "art_image_chunk";
		case DF_Type::art_image_element: return "art_image_element";
		case DF_Type::art_image_element_creaturest: return "art_image_element_creaturest";
		case DF_Type::art_image_element_itemst: return "art_image_element_itemst";
		case DF_Type::art_image_element_plantst: return "art_image_element_plantst";
		case DF_Type::art_image_element_shapest: return "art_image_element_shapest";
		case DF_Type::art_image_element_treest: return "art_image_element_treest";
		case DF_Type::art_image_element_type: return "art_image_element_type";
		case DF_Type::art_image_property: return "art_image_property";
		case DF_Type::art_image_property_intransitive_verbst: return "art_image_property_intransitive_verbst";
		case DF_Type::art_image_property_transitive_verbst: return "art_image_property_transitive_verbst";
		case DF_Type::art_image_property_type: return "art_image_property_type";
		case DF_Type::art_image_property_verb: return "art_image_property_verb";
		case DF_Type::art_image_ref: return "art_image_ref";
		case DF_Type::artifact_claim: return "artifact_claim";
		case DF_Type::artifact_claim_type: return "artifact_claim_type";
		case DF_Type::artifact_record: return "artifact_record";
		case DF_Type::assign_trade_status: return "assign_trade_status";
		case DF_Type::assign_trade_status__T_status: return "assign_trade_status__T_status";
		case DF_Type::assume_identity_mode: return "assume_identity_mode";
		case DF_Type::barrack_preference_category: return "barrack_preference_category";
		case DF_Type::battlefield: return "battlefield";
		case DF_Type::battlefield__T_sapient_deaths: return "battlefield__T_sapient_deaths";
		case DF_Type::belief_system: return "belief_system";
		case DF_Type::biome_type: return "biome_type";
		case DF_Type::block_burrow: return "block_burrow";
		case DF_Type::block_burrow_link: return "block_burrow_link";
		case DF_Type::block_flags: return "block_flags";
		case DF_Type::block_square_event: return "block_square_event";
		case DF_Type::block_square_event_designation_priorityst: return "block_square_event_designation_priorityst";
		case DF_Type::block_square_event_frozen_liquidst: return "block_square_event_frozen_liquidst";
		case DF_Type::block_square_event_grassst: return "block_square_event_grassst";
		case DF_Type::block_square_event_item_spatterst: return "block_square_event_item_spatterst";
		case DF_Type::block_square_event_material_spatterst: return "block_square_event_material_spatterst";
		case DF_Type::block_square_event_mineralst: return "block_square_event_mineralst";
		case DF_Type::block_square_event_mineralst__T_flags: return "block_square_event_mineralst__T_flags";
		case DF_Type::block_square_event_spoorst: return "block_square_event_spoorst";
		case DF_Type::block_square_event_type: return "block_square_event_type";
		case DF_Type::block_square_event_world_constructionst: return "block_square_event_world_constructionst";
		case DF_Type::body_appearance_modifier: return "body_appearance_modifier";
		case DF_Type::body_component_info: return "body_component_info";
		case DF_Type::body_detail_plan: return "body_detail_plan";
		case DF_Type::body_layer_status: return "body_layer_status";
		case DF_Type::body_part_layer_flags: return "body_part_layer_flags";
		case DF_Type::body_part_layer_raw: return "body_part_layer_raw";
		case DF_Type::body_part_raw: return "body_part_raw";
		case DF_Type::body_part_raw_flags: return "body_part_raw_flags";
		case DF_Type::body_part_status: return "body_part_status";
		case DF_Type::body_part_template: return "body_part_template";
		case DF_Type::body_part_template_contype: return "body_part_template_contype";
		case DF_Type::body_part_template_flags: return "body_part_template_flags";
		case DF_Type::body_size_info: return "body_size_info";
		case DF_Type::body_template: return "body_template";
		case DF_Type::bp_appearance_modifier: return "bp_appearance_modifier";
		case DF_Type::breath_attack_type: return "breath_attack_type";
		case DF_Type::breed: return "breed";
		case DF_Type::breed__T_unk_18: return "breed__T_unk_18";
		case DF_Type::breed__T_unk_28: return "breed__T_unk_28";
		case DF_Type::breed__T_unk_8: return "breed__T_unk_8";
		case DF_Type::build_req_choice_genst: return "build_req_choice_genst";
		case DF_Type::build_req_choice_specst: return "build_req_choice_specst";
		case DF_Type::build_req_choice_type: return "build_req_choice_type";
		case DF_Type::build_req_choicest: return "build_req_choicest";
		case DF_Type::building: return "building";
		case DF_Type::building__T_activities: return "building__T_activities";
		case DF_Type::building__T_job_claim_suppress: return "building__T_job_claim_suppress";
		case DF_Type::building_actual: return "building_actual";
		case DF_Type::building_actual__T_contained_items: return "building_actual__T_contained_items";
		case DF_Type::building_animaltrapst: return "building_animaltrapst";
		case DF_Type::building_archerytargetst: return "building_archerytargetst";
		case DF_Type::building_archerytargetst__T_archery_direction: return "building_archerytargetst__T_archery_direction";
		case DF_Type::building_armorstandst: return "building_armorstandst";
		case DF_Type::building_axle_horizontalst: return "building_axle_horizontalst";
		case DF_Type::building_axle_verticalst: return "building_axle_verticalst";
		case DF_Type::building_bars_floorst: return "building_bars_floorst";
		case DF_Type::building_bars_verticalst: return "building_bars_verticalst";
		case DF_Type::building_bedst: return "building_bedst";
		case DF_Type::building_bedst__T_bed_flags: return "building_bedst__T_bed_flags";
		case DF_Type::building_bookcasest: return "building_bookcasest";
		case DF_Type::building_boxst: return "building_boxst";
		case DF_Type::building_bridgest: return "building_bridgest";
		case DF_Type::building_bridgest__T_direction: return "building_bridgest__T_direction";
		case DF_Type::building_cabinetst: return "building_cabinetst";
		case DF_Type::building_cagest: return "building_cagest";
		case DF_Type::building_cagest__T_cage_flags: return "building_cagest__T_cage_flags";
		case DF_Type::building_chainst: return "building_chainst";
		case DF_Type::building_chainst__T_chain_flags: return "building_chainst__T_chain_flags";
		case DF_Type::building_chairst: return "building_chairst";
		case DF_Type::building_civzonest: return "building_civzonest";
		case DF_Type::building_civzonest__T_gather_flags: return "building_civzonest__T_gather_flags";
		case DF_Type::building_civzonest__T_pit_flags: return "building_civzonest__T_pit_flags";
		case DF_Type::building_civzonest__T_zone_flags: return "building_civzonest__T_zone_flags";
		case DF_Type::building_coffinst: return "building_coffinst";
		case DF_Type::building_coffinst__T_burial_mode: return "building_coffinst__T_burial_mode";
		case DF_Type::building_constructionst: return "building_constructionst";
		case DF_Type::building_def: return "building_def";
		case DF_Type::building_def_furnacest: return "building_def_furnacest";
		case DF_Type::building_def_item: return "building_def_item";
		case DF_Type::building_def_workshopst: return "building_def_workshopst";
		case DF_Type::building_design: return "building_design";
		case DF_Type::building_design__T_flags: return "building_design__T_flags";
		case DF_Type::building_display_furniturest: return "building_display_furniturest";
		case DF_Type::building_doorst: return "building_doorst";
		case DF_Type::building_drawbuffer: return "building_drawbuffer";
		case DF_Type::building_extents: return "building_extents";
		case DF_Type::building_farmplotst: return "building_farmplotst";
		case DF_Type::building_flags: return "building_flags";
		case DF_Type::building_floodgatest: return "building_floodgatest";
		case DF_Type::building_furnacest: return "building_furnacest";
		case DF_Type::building_gear_assemblyst: return "building_gear_assemblyst";
		case DF_Type::building_gear_assemblyst__T_gear_flags: return "building_gear_assemblyst__T_gear_flags";
		case DF_Type::building_grate_floorst: return "building_grate_floorst";
		case DF_Type::building_grate_wallst: return "building_grate_wallst";
		case DF_Type::building_handler: return "building_handler";
		case DF_Type::building_hatchst: return "building_hatchst";
		case DF_Type::building_hivest: return "building_hivest";
		case DF_Type::building_instrumentst: return "building_instrumentst";
		case DF_Type::building_nest_boxst: return "building_nest_boxst";
		case DF_Type::building_nestst: return "building_nestst";
		case DF_Type::building_offering_placest: return "building_offering_placest";
		case DF_Type::building_road_dirtst: return "building_road_dirtst";
		case DF_Type::building_road_pavedst: return "building_road_pavedst";
		case DF_Type::building_roadst: return "building_roadst";
		case DF_Type::building_rollersst: return "building_rollersst";
		case DF_Type::building_screw_pumpst: return "building_screw_pumpst";
		case DF_Type::building_shopst: return "building_shopst";
		case DF_Type::building_shopst__T_shop_flags: return "building_shopst__T_shop_flags";
		case DF_Type::building_siegeenginest: return "building_siegeenginest";
		case DF_Type::building_siegeenginest__T_action: return "building_siegeenginest__T_action";
		case DF_Type::building_siegeenginest__T_facing: return "building_siegeenginest__T_facing";
		case DF_Type::building_slabst: return "building_slabst";
		case DF_Type::building_squad_use: return "building_squad_use";
		case DF_Type::building_statuest: return "building_statuest";
		case DF_Type::building_stockpilest: return "building_stockpilest";
		case DF_Type::building_supportst: return "building_supportst";
		case DF_Type::building_supportst__T_support_flags: return "building_supportst__T_support_flags";
		case DF_Type::building_tablest: return "building_tablest";
		case DF_Type::building_tablest__T_table_flags: return "building_tablest__T_table_flags";
		case DF_Type::building_traction_benchst: return "building_traction_benchst";
		case DF_Type::building_tradedepotst: return "building_tradedepotst";
		case DF_Type::building_tradedepotst__T_trade_flags: return "building_tradedepotst__T_trade_flags";
		case DF_Type::building_trapst: return "building_trapst";
		case DF_Type::building_trapst__T_stop_flags: return "building_trapst__T_stop_flags";
		case DF_Type::building_type: return "building_type";
		case DF_Type::building_users: return "building_users";
		case DF_Type::building_wagonst: return "building_wagonst";
		case DF_Type::building_water_wheelst: return "building_water_wheelst";
		case DF_Type::building_weaponrackst: return "building_weaponrackst";
		case DF_Type::building_weaponst: return "building_weaponst";
		case DF_Type::building_wellst: return "building_wellst";
		case DF_Type::building_wellst__T_well_flags: return "building_wellst__T_well_flags";
		case DF_Type::building_windmillst: return "building_windmillst";
		case DF_Type::building_window_gemst: return "building_window_gemst";
		case DF_Type::building_window_glassst: return "building_window_glassst";
		case DF_Type::building_windowst: return "building_windowst";
		case DF_Type::building_workshopst: return "building_workshopst";
		case DF_Type::buildings_other_id: return "buildings_other_id";
		case DF_Type::builtin_mats: return "builtin_mats";
		case DF_Type::burrow: return "burrow";
		case DF_Type::campfire: return "campfire";
		case DF_Type::caravan_state: return "caravan_state";
		case DF_Type::caravan_state__T_flags: return "caravan_state__T_flags";
		case DF_Type::caravan_state__T_trade_state: return "caravan_state__T_trade_state";
		case DF_Type::caste_attack: return "caste_attack";
		case DF_Type::caste_attack__T_flags: return "caste_attack__T_flags";
		case DF_Type::caste_body_info: return "caste_body_info";
		case DF_Type::caste_body_info__T_extra_butcher_objects: return "caste_body_info__T_extra_butcher_objects";
		case DF_Type::caste_body_info__T_flags: return "caste_body_info__T_flags";
		case DF_Type::caste_body_info__T_interactions: return "caste_body_info__T_interactions";
		case DF_Type::caste_body_info__T_interactions__T_type: return "caste_body_info__T_interactions__T_type";
		case DF_Type::caste_clothing_item: return "caste_clothing_item";
		case DF_Type::caste_raw: return "caste_raw";
		case DF_Type::caste_raw__T_anon_1: return "caste_raw__T_anon_1";
		case DF_Type::caste_raw__T_attributes: return "caste_raw__T_attributes";
		case DF_Type::caste_raw__T_bp_appearance: return "caste_raw__T_bp_appearance";
		case DF_Type::caste_raw__T_caste_profession_name: return "caste_raw__T_caste_profession_name";
		case DF_Type::caste_raw__T_extracts: return "caste_raw__T_extracts";
		case DF_Type::caste_raw__T_lair_hunter_speech: return "caste_raw__T_lair_hunter_speech";
		case DF_Type::caste_raw__T_misc: return "caste_raw__T_misc";
		case DF_Type::caste_raw__T_personality: return "caste_raw__T_personality";
		case DF_Type::caste_raw__T_secretion: return "caste_raw__T_secretion";
		case DF_Type::caste_raw__T_shearable_tissue_layer: return "caste_raw__T_shearable_tissue_layer";
		case DF_Type::caste_raw__T_sound: return "caste_raw__T_sound";
		case DF_Type::caste_raw__T_unk29: return "caste_raw__T_unk29";
		case DF_Type::caste_raw__T_unknown2: return "caste_raw__T_unknown2";
		case DF_Type::caste_raw_flags: return "caste_raw_flags";
		case DF_Type::cave_column: return "cave_column";
		case DF_Type::cave_column_link: return "cave_column_link";
		case DF_Type::cave_column_rectangle: return "cave_column_rectangle";
		case DF_Type::cie_add_tag_mask1: return "cie_add_tag_mask1";
		case DF_Type::cie_add_tag_mask2: return "cie_add_tag_mask2";
		case DF_Type::civzone_type: return "civzone_type";
		case DF_Type::coin_batch: return "coin_batch";
		case DF_Type::coin_batch__T_image_back: return "coin_batch__T_image_back";
		case DF_Type::coin_batch__T_image_front: return "coin_batch__T_image_front";
		case DF_Type::color_modifier_raw: return "color_modifier_raw";
		case DF_Type::combat_report_event_type: return "combat_report_event_type";
		case DF_Type::conflict_level: return "conflict_level";
		case DF_Type::construction: return "construction";
		case DF_Type::construction_flags: return "construction_flags";
		case DF_Type::construction_type: return "construction_type";
		case DF_Type::conversation: return "conversation";
		case DF_Type::conversation__T_speech: return "conversation__T_speech";
		case DF_Type::conversation__T_state: return "conversation__T_state";
		case DF_Type::conversation_menu: return "conversation_menu";
		case DF_Type::coord: return "coord";
		case DF_Type::coord2d: return "coord2d";
		case DF_Type::coord2d_path: return "coord2d_path";
		case DF_Type::coord_path: return "coord_path";
		case DF_Type::coord_rect: return "coord_rect";
		case DF_Type::corpse_material_type: return "corpse_material_type";
		case DF_Type::craft_material_class: return "craft_material_class";
		case DF_Type::creation_zone_pwg_alteration_campst: return "creation_zone_pwg_alteration_campst";
		case DF_Type::creation_zone_pwg_alteration_location_deathst: return "creation_zone_pwg_alteration_location_deathst";
		case DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1: return "creation_zone_pwg_alteration_location_deathst__T_unk_1";
		case DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1: return "creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1";
		case DF_Type::creation_zone_pwg_alteration_srb_ruinedst: return "creation_zone_pwg_alteration_srb_ruinedst";
		case DF_Type::creation_zone_pwg_alteration_srp_ruinedst: return "creation_zone_pwg_alteration_srp_ruinedst";
		case DF_Type::creation_zone_pwg_alteration_type: return "creation_zone_pwg_alteration_type";
		case DF_Type::creation_zone_pwg_alterationst: return "creation_zone_pwg_alterationst";
		case DF_Type::creature_graphics_appointment: return "creature_graphics_appointment";
		case DF_Type::creature_graphics_role: return "creature_graphics_role";
		case DF_Type::creature_handler: return "creature_handler";
		case DF_Type::creature_interaction: return "creature_interaction";
		case DF_Type::creature_interaction__T_flags: return "creature_interaction__T_flags";
		case DF_Type::creature_interaction_effect: return "creature_interaction_effect";
		case DF_Type::creature_interaction_effect__T_counter_trigger: return "creature_interaction_effect__T_counter_trigger";
		case DF_Type::creature_interaction_effect_add_simple_flagst: return "creature_interaction_effect_add_simple_flagst";
		case DF_Type::creature_interaction_effect_bleedingst: return "creature_interaction_effect_bleedingst";
		case DF_Type::creature_interaction_effect_blistersst: return "creature_interaction_effect_blistersst";
		case DF_Type::creature_interaction_effect_body_appearance_modifierst: return "creature_interaction_effect_body_appearance_modifierst";
		case DF_Type::creature_interaction_effect_body_mat_interactionst: return "creature_interaction_effect_body_mat_interactionst";
		case DF_Type::creature_interaction_effect_body_transformationst: return "creature_interaction_effect_body_transformationst";
		case DF_Type::creature_interaction_effect_bp_appearance_modifierst: return "creature_interaction_effect_bp_appearance_modifierst";
		case DF_Type::creature_interaction_effect_bruisingst: return "creature_interaction_effect_bruisingst";
		case DF_Type::creature_interaction_effect_can_do_interactionst: return "creature_interaction_effect_can_do_interactionst";
		case DF_Type::creature_interaction_effect_change_personalityst: return "creature_interaction_effect_change_personalityst";
		case DF_Type::creature_interaction_effect_close_open_woundsst: return "creature_interaction_effect_close_open_woundsst";
		case DF_Type::creature_interaction_effect_cough_bloodst: return "creature_interaction_effect_cough_bloodst";
		case DF_Type::creature_interaction_effect_cure_infectionsst: return "creature_interaction_effect_cure_infectionsst";
		case DF_Type::creature_interaction_effect_cure_infectionst: return "creature_interaction_effect_cure_infectionst";
		case DF_Type::creature_interaction_effect_display_namest: return "creature_interaction_effect_display_namest";
		case DF_Type::creature_interaction_effect_display_symbolst: return "creature_interaction_effect_display_symbolst";
		case DF_Type::creature_interaction_effect_dizzinessst: return "creature_interaction_effect_dizzinessst";
		case DF_Type::creature_interaction_effect_drowsinessst: return "creature_interaction_effect_drowsinessst";
		case DF_Type::creature_interaction_effect_erratic_behaviorst: return "creature_interaction_effect_erratic_behaviorst";
		case DF_Type::creature_interaction_effect_feel_emotionst: return "creature_interaction_effect_feel_emotionst";
		case DF_Type::creature_interaction_effect_feverst: return "creature_interaction_effect_feverst";
		case DF_Type::creature_interaction_effect_flags: return "creature_interaction_effect_flags";
		case DF_Type::creature_interaction_effect_flash_symbolst: return "creature_interaction_effect_flash_symbolst";
		case DF_Type::creature_interaction_effect_heal_nervesst: return "creature_interaction_effect_heal_nervesst";
		case DF_Type::creature_interaction_effect_heal_tissuesst: return "creature_interaction_effect_heal_tissuesst";
		case DF_Type::creature_interaction_effect_impair_functionst: return "creature_interaction_effect_impair_functionst";
		case DF_Type::creature_interaction_effect_material_force_adjustst: return "creature_interaction_effect_material_force_adjustst";
		case DF_Type::creature_interaction_effect_ment_att_changest: return "creature_interaction_effect_ment_att_changest";
		case DF_Type::creature_interaction_effect_nauseast: return "creature_interaction_effect_nauseast";
		case DF_Type::creature_interaction_effect_necrosisst: return "creature_interaction_effect_necrosisst";
		case DF_Type::creature_interaction_effect_numbnessst: return "creature_interaction_effect_numbnessst";
		case DF_Type::creature_interaction_effect_oozingst: return "creature_interaction_effect_oozingst";
		case DF_Type::creature_interaction_effect_painst: return "creature_interaction_effect_painst";
		case DF_Type::creature_interaction_effect_paralysisst: return "creature_interaction_effect_paralysisst";
		case DF_Type::creature_interaction_effect_phys_att_changest: return "creature_interaction_effect_phys_att_changest";
		case DF_Type::creature_interaction_effect_reduce_dizzinessst: return "creature_interaction_effect_reduce_dizzinessst";
		case DF_Type::creature_interaction_effect_reduce_feverst: return "creature_interaction_effect_reduce_feverst";
		case DF_Type::creature_interaction_effect_reduce_nauseast: return "creature_interaction_effect_reduce_nauseast";
		case DF_Type::creature_interaction_effect_reduce_painst: return "creature_interaction_effect_reduce_painst";
		case DF_Type::creature_interaction_effect_reduce_paralysisst: return "creature_interaction_effect_reduce_paralysisst";
		case DF_Type::creature_interaction_effect_reduce_swellingst: return "creature_interaction_effect_reduce_swellingst";
		case DF_Type::creature_interaction_effect_regrow_partsst: return "creature_interaction_effect_regrow_partsst";
		case DF_Type::creature_interaction_effect_remove_simple_flagst: return "creature_interaction_effect_remove_simple_flagst";
		case DF_Type::creature_interaction_effect_sense_creature_classst: return "creature_interaction_effect_sense_creature_classst";
		case DF_Type::creature_interaction_effect_skill_roll_adjustst: return "creature_interaction_effect_skill_roll_adjustst";
		case DF_Type::creature_interaction_effect_special_attack_interactionst: return "creature_interaction_effect_special_attack_interactionst";
		case DF_Type::creature_interaction_effect_speed_changest: return "creature_interaction_effect_speed_changest";
		case DF_Type::creature_interaction_effect_stop_bleedingst: return "creature_interaction_effect_stop_bleedingst";
		case DF_Type::creature_interaction_effect_swellingst: return "creature_interaction_effect_swellingst";
		case DF_Type::creature_interaction_effect_target: return "creature_interaction_effect_target";
		case DF_Type::creature_interaction_effect_target_mode: return "creature_interaction_effect_target_mode";
		case DF_Type::creature_interaction_effect_type: return "creature_interaction_effect_type";
		case DF_Type::creature_interaction_effect_unconsciousnessst: return "creature_interaction_effect_unconsciousnessst";
		case DF_Type::creature_interaction_effect_vomit_bloodst: return "creature_interaction_effect_vomit_bloodst";
		case DF_Type::creature_interaction_target_flags: return "creature_interaction_target_flags";
		case DF_Type::creature_raw: return "creature_raw";
		case DF_Type::creature_raw__T_graphics: return "creature_raw__T_graphics";
		case DF_Type::creature_raw__T_hive_product: return "creature_raw__T_hive_product";
		case DF_Type::creature_raw__T_profession_name: return "creature_raw__T_profession_name";
		case DF_Type::creature_raw_flags: return "creature_raw_flags";
		case DF_Type::creature_variation: return "creature_variation";
		case DF_Type::creature_variation_convert_tag: return "creature_variation_convert_tag";
		case DF_Type::crime: return "crime";
		case DF_Type::crime__T_convict_data: return "crime__T_convict_data";
		case DF_Type::crime__T_counterintelligence: return "crime__T_counterintelligence";
		case DF_Type::crime__T_flags: return "crime__T_flags";
		case DF_Type::crime__T_mode: return "crime__T_mode";
		case DF_Type::crime__T_punishment: return "crime__T_punishment";
		case DF_Type::crime__T_reports: return "crime__T_reports";
		case DF_Type::crime__T_victim_data: return "crime__T_victim_data";
		case DF_Type::crime_type: return "crime_type";
		case DF_Type::cultural_identity: return "cultural_identity";
		case DF_Type::cultural_identity__T_anon_1: return "cultural_identity__T_anon_1";
		case DF_Type::cultural_identity__T_anon_2: return "cultural_identity__T_anon_2";
		case DF_Type::cultural_identity__T_group_log: return "cultural_identity__T_group_log";
		case DF_Type::cultural_identity__T_group_log__T_join_type: return "cultural_identity__T_group_log__T_join_type";
		case DF_Type::cumulus_type: return "cumulus_type";
		case DF_Type::curse_attr_change: return "curse_attr_change";
		case DF_Type::d_init: return "d_init";
		case DF_Type::d_init__T_store_dist: return "d_init__T_store_dist";
		case DF_Type::d_init__T_wound_color: return "d_init__T_wound_color";
		case DF_Type::d_init_embark_confirm: return "d_init_embark_confirm";
		case DF_Type::d_init_flags1: return "d_init_flags1";
		case DF_Type::d_init_flags2: return "d_init_flags2";
		case DF_Type::d_init_flags3: return "d_init_flags3";
		case DF_Type::d_init_flags4: return "d_init_flags4";
		case DF_Type::d_init_idlers: return "d_init_idlers";
		case DF_Type::d_init_nickname: return "d_init_nickname";
		case DF_Type::d_init_tunnel: return "d_init_tunnel";
		case DF_Type::d_init_z_view: return "d_init_z_view";
		case DF_Type::dance_form: return "dance_form";
		case DF_Type::dance_form_sub1: return "dance_form_sub1";
		case DF_Type::dance_form_sub2: return "dance_form_sub2";
		case DF_Type::death_condition_type: return "death_condition_type";
		case DF_Type::death_type: return "death_type";
		case DF_Type::deep_vein_hollow: return "deep_vein_hollow";
		case DF_Type::descriptor_color: return "descriptor_color";
		case DF_Type::descriptor_pattern: return "descriptor_pattern";
		case DF_Type::descriptor_shape: return "descriptor_shape";
		case DF_Type::descriptor_shape__T_gems_use: return "descriptor_shape__T_gems_use";
		case DF_Type::dfhack_knowledge_scholar_flag: return "dfhack_knowledge_scholar_flag";
		case DF_Type::dfhack_material_category: return "dfhack_material_category";
		case DF_Type::dfhack_room_quality_level: return "dfhack_room_quality_level";
		case DF_Type::dipscript_info: return "dipscript_info";
		case DF_Type::dipscript_popup: return "dipscript_popup";
		case DF_Type::dipscript_popup__T_flags: return "dipscript_popup__T_flags";
		case DF_Type::divination_set: return "divination_set";
		case DF_Type::divination_set_roll: return "divination_set_roll";
		case DF_Type::door_flags: return "door_flags";
		case DF_Type::dye_info: return "dye_info";
		case DF_Type::effect_info: return "effect_info";
		case DF_Type::embark_feature: return "embark_feature";
		case DF_Type::embark_finder_option: return "embark_finder_option";
		case DF_Type::embark_item_choice: return "embark_item_choice";
		case DF_Type::embark_item_choice__T_list: return "embark_item_choice__T_list";
		case DF_Type::embark_location: return "embark_location";
		case DF_Type::embark_note: return "embark_note";
		case DF_Type::embark_profile: return "embark_profile";
		case DF_Type::emotion_type: return "emotion_type";
		case DF_Type::enabler: return "enabler";
		case DF_Type::enabler__T_async_frombox: return "enabler__T_async_frombox";
		case DF_Type::enabler__T_async_frombox__T_queue: return "enabler__T_async_frombox__T_queue";
		case DF_Type::enabler__T_async_frombox__T_queue___union0: return "enabler__T_async_frombox__T_queue___union0";
		case DF_Type::enabler__T_async_frombox__T_queue___union0___struct1: return "enabler__T_async_frombox__T_queue___union0___struct1";
		case DF_Type::enabler__T_async_frombox__T_queue__T_msg: return "enabler__T_async_frombox__T_queue__T_msg";
		case DF_Type::enabler__T_async_tobox: return "enabler__T_async_tobox";
		case DF_Type::enabler__T_async_tobox__T_queue: return "enabler__T_async_tobox__T_queue";
		case DF_Type::enabler__T_async_tobox__T_queue__T_cmd: return "enabler__T_async_tobox__T_queue__T_cmd";
		case DF_Type::enabler__T_async_zoom: return "enabler__T_async_zoom";
		case DF_Type::enabler__T_flag: return "enabler__T_flag";
		case DF_Type::enabler__T_gputicks: return "enabler__T_gputicks";
		case DF_Type::enabler__T_overridden_grid_sizes: return "enabler__T_overridden_grid_sizes";
		case DF_Type::enabler__T_simticks: return "enabler__T_simticks";
		case DF_Type::enabler__T_text_system: return "enabler__T_text_system";
		case DF_Type::enabler__T_text_system__T_file_info: return "enabler__T_text_system__T_file_info";
		case DF_Type::enabler__T_textures: return "enabler__T_textures";
		case DF_Type::engraving: return "engraving";
		case DF_Type::engraving_flags: return "engraving_flags";
		case DF_Type::entity_action_type: return "entity_action_type";
		case DF_Type::entity_activity_statistics: return "entity_activity_statistics";
		case DF_Type::entity_activity_statistics__T_food: return "entity_activity_statistics__T_food";
		case DF_Type::entity_activity_statistics__T_found_misc: return "entity_activity_statistics__T_found_misc";
		case DF_Type::entity_activity_statistics__T_wealth: return "entity_activity_statistics__T_wealth";
		case DF_Type::entity_animal_raw: return "entity_animal_raw";
		case DF_Type::entity_animal_raw__T_flags: return "entity_animal_raw__T_flags";
		case DF_Type::entity_buy_prices: return "entity_buy_prices";
		case DF_Type::entity_buy_requests: return "entity_buy_requests";
		case DF_Type::entity_claim_mask: return "entity_claim_mask";
		case DF_Type::entity_claim_mask__T_map: return "entity_claim_mask__T_map";
		case DF_Type::entity_entity_link: return "entity_entity_link";
		case DF_Type::entity_entity_link_type: return "entity_entity_link_type";
		case DF_Type::entity_event: return "entity_event";
		case DF_Type::entity_event__T_data: return "entity_event__T_data";
		case DF_Type::entity_event__T_data__T_abandon: return "entity_event__T_data__T_abandon";
		case DF_Type::entity_event__T_data__T_abduction: return "entity_event__T_data__T_abduction";
		case DF_Type::entity_event__T_data__T_accept_peace_offer: return "entity_event__T_data__T_accept_peace_offer";
		case DF_Type::entity_event__T_data__T_accept_tribute_demand: return "entity_event__T_data__T_accept_tribute_demand";
		case DF_Type::entity_event__T_data__T_accept_tribute_offer: return "entity_event__T_data__T_accept_tribute_offer";
		case DF_Type::entity_event__T_data__T_artifact_destroyed: return "entity_event__T_data__T_artifact_destroyed";
		case DF_Type::entity_event__T_data__T_artifact_in_feature_layer: return "entity_event__T_data__T_artifact_in_feature_layer";
		case DF_Type::entity_event__T_data__T_artifact_in_inventory: return "entity_event__T_data__T_artifact_in_inventory";
		case DF_Type::entity_event__T_data__T_artifact_in_site: return "entity_event__T_data__T_artifact_in_site";
		case DF_Type::entity_event__T_data__T_artifact_in_subregion: return "entity_event__T_data__T_artifact_in_subregion";
		case DF_Type::entity_event__T_data__T_artifact_not_in_feature_layer: return "entity_event__T_data__T_artifact_not_in_feature_layer";
		case DF_Type::entity_event__T_data__T_artifact_not_in_inventory: return "entity_event__T_data__T_artifact_not_in_inventory";
		case DF_Type::entity_event__T_data__T_artifact_not_in_site: return "entity_event__T_data__T_artifact_not_in_site";
		case DF_Type::entity_event__T_data__T_artifact_not_in_subregion: return "entity_event__T_data__T_artifact_not_in_subregion";
		case DF_Type::entity_event__T_data__T_beast: return "entity_event__T_data__T_beast";
		case DF_Type::entity_event__T_data__T_cease_tribute_offer: return "entity_event__T_data__T_cease_tribute_offer";
		case DF_Type::entity_event__T_data__T_claim: return "entity_event__T_data__T_claim";
		case DF_Type::entity_event__T_data__T_flee: return "entity_event__T_data__T_flee";
		case DF_Type::entity_event__T_data__T_founded: return "entity_event__T_data__T_founded";
		case DF_Type::entity_event__T_data__T_founding: return "entity_event__T_data__T_founding";
		case DF_Type::entity_event__T_data__T_group: return "entity_event__T_data__T_group";
		case DF_Type::entity_event__T_data__T_harass: return "entity_event__T_data__T_harass";
		case DF_Type::entity_event__T_data__T_incident: return "entity_event__T_data__T_incident";
		case DF_Type::entity_event__T_data__T_insurrection: return "entity_event__T_data__T_insurrection";
		case DF_Type::entity_event__T_data__T_insurrection_end: return "entity_event__T_data__T_insurrection_end";
		case DF_Type::entity_event__T_data__T_insurrection_end__T_result: return "entity_event__T_data__T_insurrection_end__T_result";
		case DF_Type::entity_event__T_data__T_invasion: return "entity_event__T_data__T_invasion";
		case DF_Type::entity_event__T_data__T_leave: return "entity_event__T_data__T_leave";
		case DF_Type::entity_event__T_data__T_occupation: return "entity_event__T_data__T_occupation";
		case DF_Type::entity_event__T_data__T_reclaimed: return "entity_event__T_data__T_reclaimed";
		case DF_Type::entity_event__T_data__T_reclaiming: return "entity_event__T_data__T_reclaiming";
		case DF_Type::entity_event__T_data__T_refuse_peace_offer: return "entity_event__T_data__T_refuse_peace_offer";
		case DF_Type::entity_event__T_data__T_refuse_tribute_demand: return "entity_event__T_data__T_refuse_tribute_demand";
		case DF_Type::entity_event__T_data__T_refuse_tribute_offer: return "entity_event__T_data__T_refuse_tribute_offer";
		case DF_Type::entity_event__T_data__T_succession: return "entity_event__T_data__T_succession";
		case DF_Type::entity_event_type: return "entity_event_type";
		case DF_Type::entity_material_category: return "entity_material_category";
		case DF_Type::entity_name_type: return "entity_name_type";
		case DF_Type::entity_occasion: return "entity_occasion";
		case DF_Type::entity_occasion_info: return "entity_occasion_info";
		case DF_Type::entity_occasion_schedule: return "entity_occasion_schedule";
		case DF_Type::entity_occasion_schedule_feature: return "entity_occasion_schedule_feature";
		case DF_Type::entity_population: return "entity_population";
		case DF_Type::entity_population_unk4: return "entity_population_unk4";
		case DF_Type::entity_population_unk4__T_anon_1: return "entity_population_unk4__T_anon_1";
		case DF_Type::entity_population_unk4__T_anon_2: return "entity_population_unk4__T_anon_2";
		case DF_Type::entity_population_unk4__T_anon_3: return "entity_population_unk4__T_anon_3";
		case DF_Type::entity_position: return "entity_position";
		case DF_Type::entity_position_assignment: return "entity_position_assignment";
		case DF_Type::entity_position_flags: return "entity_position_flags";
		case DF_Type::entity_position_raw: return "entity_position_raw";
		case DF_Type::entity_position_raw_flags: return "entity_position_raw_flags";
		case DF_Type::entity_position_responsibility: return "entity_position_responsibility";
		case DF_Type::entity_raw: return "entity_raw";
		case DF_Type::entity_raw__T_equipment: return "entity_raw__T_equipment";
		case DF_Type::entity_raw__T_jobs: return "entity_raw__T_jobs";
		case DF_Type::entity_raw__T_land_holder_trigger: return "entity_raw__T_land_holder_trigger";
		case DF_Type::entity_raw__T_progress_trigger: return "entity_raw__T_progress_trigger";
		case DF_Type::entity_raw__T_scholar: return "entity_raw__T_scholar";
		case DF_Type::entity_raw__T_symbols: return "entity_raw__T_symbols";
		case DF_Type::entity_raw__T_tissue_styles: return "entity_raw__T_tissue_styles";
		case DF_Type::entity_raw__T_workshops: return "entity_raw__T_workshops";
		case DF_Type::entity_raw_flags: return "entity_raw_flags";
		case DF_Type::entity_recipe: return "entity_recipe";
		case DF_Type::entity_sell_category: return "entity_sell_category";
		case DF_Type::entity_sell_prices: return "entity_sell_prices";
		case DF_Type::entity_sell_requests: return "entity_sell_requests";
		case DF_Type::entity_site_link: return "entity_site_link";
		case DF_Type::entity_site_link__T_unk_7: return "entity_site_link__T_unk_7";
		case DF_Type::entity_site_link_flags: return "entity_site_link_flags";
		case DF_Type::entity_site_link_status_flags: return "entity_site_link_status_flags";
		case DF_Type::entity_site_link_type: return "entity_site_link_type";
		case DF_Type::entity_tissue_style: return "entity_tissue_style";
		case DF_Type::entity_uniform: return "entity_uniform";
		case DF_Type::entity_uniform_item: return "entity_uniform_item";
		case DF_Type::entity_unk_v47_1: return "entity_unk_v47_1";
		case DF_Type::environment_type: return "environment_type";
		case DF_Type::era_type: return "era_type";
		case DF_Type::ethic_response: return "ethic_response";
		case DF_Type::ethic_type: return "ethic_type";
		case DF_Type::export_map_type: return "export_map_type";
		case DF_Type::feature: return "feature";
		case DF_Type::feature_alteration: return "feature_alteration";
		case DF_Type::feature_alteration_new_lava_fill_zst: return "feature_alteration_new_lava_fill_zst";
		case DF_Type::feature_alteration_new_pop_maxst: return "feature_alteration_new_pop_maxst";
		case DF_Type::feature_alteration_type: return "feature_alteration_type";
		case DF_Type::feature_cavest: return "feature_cavest";
		case DF_Type::feature_deep_special_tubest: return "feature_deep_special_tubest";
		case DF_Type::feature_deep_surface_portalst: return "feature_deep_surface_portalst";
		case DF_Type::feature_init: return "feature_init";
		case DF_Type::feature_init_cavest: return "feature_init_cavest";
		case DF_Type::feature_init_deep_special_tubest: return "feature_init_deep_special_tubest";
		case DF_Type::feature_init_deep_surface_portalst: return "feature_init_deep_surface_portalst";
		case DF_Type::feature_init_flags: return "feature_init_flags";
		case DF_Type::feature_init_magma_core_from_layerst: return "feature_init_magma_core_from_layerst";
		case DF_Type::feature_init_magma_poolst: return "feature_init_magma_poolst";
		case DF_Type::feature_init_outdoor_riverst: return "feature_init_outdoor_riverst";
		case DF_Type::feature_init_pitst: return "feature_init_pitst";
		case DF_Type::feature_init_subterranean_from_layerst: return "feature_init_subterranean_from_layerst";
		case DF_Type::feature_init_underworld_from_layerst: return "feature_init_underworld_from_layerst";
		case DF_Type::feature_init_volcanost: return "feature_init_volcanost";
		case DF_Type::feature_magma_core_from_layerst: return "feature_magma_core_from_layerst";
		case DF_Type::feature_magma_poolst: return "feature_magma_poolst";
		case DF_Type::feature_outdoor_riverst: return "feature_outdoor_riverst";
		case DF_Type::feature_pitst: return "feature_pitst";
		case DF_Type::feature_subterranean_from_layerst: return "feature_subterranean_from_layerst";
		case DF_Type::feature_type: return "feature_type";
		case DF_Type::feature_underworld_from_layerst: return "feature_underworld_from_layerst";
		case DF_Type::feature_volcanost: return "feature_volcanost";
		case DF_Type::file_compressorst: return "file_compressorst";
		case DF_Type::fire: return "fire";
		case DF_Type::flow_guide: return "flow_guide";
		case DF_Type::flow_guide_item_cloudst: return "flow_guide_item_cloudst";
		case DF_Type::flow_guide_trailing_flowst: return "flow_guide_trailing_flowst";
		case DF_Type::flow_guide_type: return "flow_guide_type";
		case DF_Type::flow_info: return "flow_info";
		case DF_Type::flow_reuse_pool: return "flow_reuse_pool";
		case DF_Type::flow_reuse_pool__T_flags: return "flow_reuse_pool__T_flags";
		case DF_Type::flow_type: return "flow_type";
		case DF_Type::fog_type: return "fog_type";
		case DF_Type::fortress_type: return "fortress_type";
		case DF_Type::front_type: return "front_type";
		case DF_Type::furnace_type: return "furnace_type";
		case DF_Type::furniture_type: return "furniture_type";
		case DF_Type::gait_info: return "gait_info";
		case DF_Type::gait_info__T_flags: return "gait_info__T_flags";
		case DF_Type::gait_type: return "gait_type";
		case DF_Type::game_mode: return "game_mode";
		case DF_Type::game_type: return "game_type";
		case DF_Type::gate_flags: return "gate_flags";
		case DF_Type::general_ref: return "general_ref";
		case DF_Type::general_ref_abstract_buildingst: return "general_ref_abstract_buildingst";
		case DF_Type::general_ref_activity_eventst: return "general_ref_activity_eventst";
		case DF_Type::general_ref_artifact: return "general_ref_artifact";
		case DF_Type::general_ref_building: return "general_ref_building";
		case DF_Type::general_ref_building_cagedst: return "general_ref_building_cagedst";
		case DF_Type::general_ref_building_chainst: return "general_ref_building_chainst";
		case DF_Type::general_ref_building_civzone_assignedst: return "general_ref_building_civzone_assignedst";
		case DF_Type::general_ref_building_destinationst: return "general_ref_building_destinationst";
		case DF_Type::general_ref_building_display_furniturest: return "general_ref_building_display_furniturest";
		case DF_Type::general_ref_building_holderst: return "general_ref_building_holderst";
		case DF_Type::general_ref_building_nest_boxst: return "general_ref_building_nest_boxst";
		case DF_Type::general_ref_building_triggerst: return "general_ref_building_triggerst";
		case DF_Type::general_ref_building_triggertargetst: return "general_ref_building_triggertargetst";
		case DF_Type::general_ref_building_use_target_1st: return "general_ref_building_use_target_1st";
		case DF_Type::general_ref_building_use_target_2st: return "general_ref_building_use_target_2st";
		case DF_Type::general_ref_building_well_tag: return "general_ref_building_well_tag";
		case DF_Type::general_ref_coinbatch: return "general_ref_coinbatch";
		case DF_Type::general_ref_contained_in_itemst: return "general_ref_contained_in_itemst";
		case DF_Type::general_ref_contains_itemst: return "general_ref_contains_itemst";
		case DF_Type::general_ref_contains_unitst: return "general_ref_contains_unitst";
		case DF_Type::general_ref_creaturest: return "general_ref_creaturest";
		case DF_Type::general_ref_dance_formst: return "general_ref_dance_formst";
		case DF_Type::general_ref_entity: return "general_ref_entity";
		case DF_Type::general_ref_entity_art_image: return "general_ref_entity_art_image";
		case DF_Type::general_ref_entity_itemownerst: return "general_ref_entity_itemownerst";
		case DF_Type::general_ref_entity_offeredst: return "general_ref_entity_offeredst";
		case DF_Type::general_ref_entity_popst: return "general_ref_entity_popst";
		case DF_Type::general_ref_entity_stolenst: return "general_ref_entity_stolenst";
		case DF_Type::general_ref_feature_layerst: return "general_ref_feature_layerst";
		case DF_Type::general_ref_historical_eventst: return "general_ref_historical_eventst";
		case DF_Type::general_ref_historical_figurest: return "general_ref_historical_figurest";
		case DF_Type::general_ref_interactionst: return "general_ref_interactionst";
		case DF_Type::general_ref_is_artifactst: return "general_ref_is_artifactst";
		case DF_Type::general_ref_is_nemesisst: return "general_ref_is_nemesisst";
		case DF_Type::general_ref_item: return "general_ref_item";
		case DF_Type::general_ref_item_type: return "general_ref_item_type";
		case DF_Type::general_ref_knowledge_scholar_flagst: return "general_ref_knowledge_scholar_flagst";
		case DF_Type::general_ref_languagest: return "general_ref_languagest";
		case DF_Type::general_ref_locationst: return "general_ref_locationst";
		case DF_Type::general_ref_mapsquare: return "general_ref_mapsquare";
		case DF_Type::general_ref_musical_formst: return "general_ref_musical_formst";
		case DF_Type::general_ref_nemesis: return "general_ref_nemesis";
		case DF_Type::general_ref_poetic_formst: return "general_ref_poetic_formst";
		case DF_Type::general_ref_projectile: return "general_ref_projectile";
		case DF_Type::general_ref_sitest: return "general_ref_sitest";
		case DF_Type::general_ref_spherest: return "general_ref_spherest";
		case DF_Type::general_ref_subregionst: return "general_ref_subregionst";
		case DF_Type::general_ref_type: return "general_ref_type";
		case DF_Type::general_ref_unit: return "general_ref_unit";
		case DF_Type::general_ref_unit_beateest: return "general_ref_unit_beateest";
		case DF_Type::general_ref_unit_cageest: return "general_ref_unit_cageest";
		case DF_Type::general_ref_unit_climberst: return "general_ref_unit_climberst";
		case DF_Type::general_ref_unit_foodreceiverst: return "general_ref_unit_foodreceiverst";
		case DF_Type::general_ref_unit_geldeest: return "general_ref_unit_geldeest";
		case DF_Type::general_ref_unit_holderst: return "general_ref_unit_holderst";
		case DF_Type::general_ref_unit_infantst: return "general_ref_unit_infantst";
		case DF_Type::general_ref_unit_interrogateest: return "general_ref_unit_interrogateest";
		case DF_Type::general_ref_unit_itemownerst: return "general_ref_unit_itemownerst";
		case DF_Type::general_ref_unit_itemownerst__T_flags: return "general_ref_unit_itemownerst__T_flags";
		case DF_Type::general_ref_unit_kidnapeest: return "general_ref_unit_kidnapeest";
		case DF_Type::general_ref_unit_milkeest: return "general_ref_unit_milkeest";
		case DF_Type::general_ref_unit_patientst: return "general_ref_unit_patientst";
		case DF_Type::general_ref_unit_reporteest: return "general_ref_unit_reporteest";
		case DF_Type::general_ref_unit_riderst: return "general_ref_unit_riderst";
		case DF_Type::general_ref_unit_sheareest: return "general_ref_unit_sheareest";
		case DF_Type::general_ref_unit_slaughtereest: return "general_ref_unit_slaughtereest";
		case DF_Type::general_ref_unit_suckeest: return "general_ref_unit_suckeest";
		case DF_Type::general_ref_unit_tradebringerst: return "general_ref_unit_tradebringerst";
		case DF_Type::general_ref_unit_traineest: return "general_ref_unit_traineest";
		case DF_Type::general_ref_unit_workerst: return "general_ref_unit_workerst";
		case DF_Type::general_ref_value_levelst: return "general_ref_value_levelst";
		case DF_Type::general_ref_written_contentst: return "general_ref_written_contentst";
		case DF_Type::geo_layer_type: return "geo_layer_type";
		case DF_Type::ghost_goal: return "ghost_goal";
		case DF_Type::ghost_type: return "ghost_type";
		case DF_Type::gloves_flags: return "gloves_flags";
		case DF_Type::glowing_barrier: return "glowing_barrier";
		case DF_Type::goal_type: return "goal_type";
		case DF_Type::graphic: return "graphic";
		case DF_Type::guild_id: return "guild_id";
		case DF_Type::hauler_type: return "hauler_type";
		case DF_Type::hauling_route: return "hauling_route";
		case DF_Type::hauling_stop: return "hauling_stop";
		case DF_Type::health_view_bits1: return "health_view_bits1";
		case DF_Type::health_view_bits2: return "health_view_bits2";
		case DF_Type::health_view_bits3: return "health_view_bits3";
		case DF_Type::helm_flags: return "helm_flags";
		case DF_Type::hillock_house_type: return "hillock_house_type";
		case DF_Type::histfig_body_state: return "histfig_body_state";
		case DF_Type::histfig_entity_link: return "histfig_entity_link";
		case DF_Type::histfig_entity_link_criminalst: return "histfig_entity_link_criminalst";
		case DF_Type::histfig_entity_link_enemyst: return "histfig_entity_link_enemyst";
		case DF_Type::histfig_entity_link_former_memberst: return "histfig_entity_link_former_memberst";
		case DF_Type::histfig_entity_link_former_mercenaryst: return "histfig_entity_link_former_mercenaryst";
		case DF_Type::histfig_entity_link_former_occupationst: return "histfig_entity_link_former_occupationst";
		case DF_Type::histfig_entity_link_former_positionst: return "histfig_entity_link_former_positionst";
		case DF_Type::histfig_entity_link_former_prisonerst: return "histfig_entity_link_former_prisonerst";
		case DF_Type::histfig_entity_link_former_slavest: return "histfig_entity_link_former_slavest";
		case DF_Type::histfig_entity_link_former_squadst: return "histfig_entity_link_former_squadst";
		case DF_Type::histfig_entity_link_memberst: return "histfig_entity_link_memberst";
		case DF_Type::histfig_entity_link_mercenaryst: return "histfig_entity_link_mercenaryst";
		case DF_Type::histfig_entity_link_occupationst: return "histfig_entity_link_occupationst";
		case DF_Type::histfig_entity_link_position_claimst: return "histfig_entity_link_position_claimst";
		case DF_Type::histfig_entity_link_positionst: return "histfig_entity_link_positionst";
		case DF_Type::histfig_entity_link_prisonerst: return "histfig_entity_link_prisonerst";
		case DF_Type::histfig_entity_link_slavest: return "histfig_entity_link_slavest";
		case DF_Type::histfig_entity_link_squadst: return "histfig_entity_link_squadst";
		case DF_Type::histfig_entity_link_type: return "histfig_entity_link_type";
		case DF_Type::histfig_flags: return "histfig_flags";
		case DF_Type::histfig_hf_link: return "histfig_hf_link";
		case DF_Type::histfig_hf_link_apprenticest: return "histfig_hf_link_apprenticest";
		case DF_Type::histfig_hf_link_childst: return "histfig_hf_link_childst";
		case DF_Type::histfig_hf_link_companionst: return "histfig_hf_link_companionst";
		case DF_Type::histfig_hf_link_deceased_spousest: return "histfig_hf_link_deceased_spousest";
		case DF_Type::histfig_hf_link_deityst: return "histfig_hf_link_deityst";
		case DF_Type::histfig_hf_link_fatherst: return "histfig_hf_link_fatherst";
		case DF_Type::histfig_hf_link_former_apprenticest: return "histfig_hf_link_former_apprenticest";
		case DF_Type::histfig_hf_link_former_masterst: return "histfig_hf_link_former_masterst";
		case DF_Type::histfig_hf_link_former_spousest: return "histfig_hf_link_former_spousest";
		case DF_Type::histfig_hf_link_imprisonerst: return "histfig_hf_link_imprisonerst";
		case DF_Type::histfig_hf_link_loverst: return "histfig_hf_link_loverst";
		case DF_Type::histfig_hf_link_masterst: return "histfig_hf_link_masterst";
		case DF_Type::histfig_hf_link_motherst: return "histfig_hf_link_motherst";
		case DF_Type::histfig_hf_link_pet_ownerst: return "histfig_hf_link_pet_ownerst";
		case DF_Type::histfig_hf_link_prisonerst: return "histfig_hf_link_prisonerst";
		case DF_Type::histfig_hf_link_spousest: return "histfig_hf_link_spousest";
		case DF_Type::histfig_hf_link_type: return "histfig_hf_link_type";
		case DF_Type::histfig_relationship_type: return "histfig_relationship_type";
		case DF_Type::histfig_site_link: return "histfig_site_link";
		case DF_Type::histfig_site_link_hangoutst: return "histfig_site_link_hangoutst";
		case DF_Type::histfig_site_link_home_site_abstract_buildingst: return "histfig_site_link_home_site_abstract_buildingst";
		case DF_Type::histfig_site_link_home_site_realization_buildingst: return "histfig_site_link_home_site_realization_buildingst";
		case DF_Type::histfig_site_link_home_site_realization_sulst: return "histfig_site_link_home_site_realization_sulst";
		case DF_Type::histfig_site_link_home_site_saved_civzonest: return "histfig_site_link_home_site_saved_civzonest";
		case DF_Type::histfig_site_link_lairst: return "histfig_site_link_lairst";
		case DF_Type::histfig_site_link_occupationst: return "histfig_site_link_occupationst";
		case DF_Type::histfig_site_link_prison_abstract_buildingst: return "histfig_site_link_prison_abstract_buildingst";
		case DF_Type::histfig_site_link_prison_site_building_profilest: return "histfig_site_link_prison_site_building_profilest";
		case DF_Type::histfig_site_link_seat_of_powerst: return "histfig_site_link_seat_of_powerst";
		case DF_Type::histfig_site_link_type: return "histfig_site_link_type";
		case DF_Type::historical_entity: return "historical_entity";
		case DF_Type::historical_entity__T_claims: return "historical_entity__T_claims";
		case DF_Type::historical_entity__T_derived_resources: return "historical_entity__T_derived_resources";
		case DF_Type::historical_entity__T_flags: return "historical_entity__T_flags";
		case DF_Type::historical_entity__T_guild_professions: return "historical_entity__T_guild_professions";
		case DF_Type::historical_entity__T_positions: return "historical_entity__T_positions";
		case DF_Type::historical_entity__T_relations: return "historical_entity__T_relations";
		case DF_Type::historical_entity__T_relations__T_constructions: return "historical_entity__T_relations__T_constructions";
		case DF_Type::historical_entity__T_relations__T_diplomacy: return "historical_entity__T_relations__T_diplomacy";
		case DF_Type::historical_entity__T_resources: return "historical_entity__T_resources";
		case DF_Type::historical_entity__T_resources__T_animals: return "historical_entity__T_resources__T_animals";
		case DF_Type::historical_entity__T_resources__T_metal: return "historical_entity__T_resources__T_metal";
		case DF_Type::historical_entity__T_resources__T_misc_mat: return "historical_entity__T_resources__T_misc_mat";
		case DF_Type::historical_entity__T_resources__T_organic: return "historical_entity__T_resources__T_organic";
		case DF_Type::historical_entity__T_resources__T_refuse: return "historical_entity__T_resources__T_refuse";
		case DF_Type::historical_entity__T_resources__T_unk13: return "historical_entity__T_resources__T_unk13";
		case DF_Type::historical_entity__T_resources__T_wood_products: return "historical_entity__T_resources__T_wood_products";
		case DF_Type::historical_entity__T_tissue_styles: return "historical_entity__T_tissue_styles";
		case DF_Type::historical_entity__T_training_knowledge: return "historical_entity__T_training_knowledge";
		case DF_Type::historical_entity__T_unk_v47_1: return "historical_entity__T_unk_v47_1";
		case DF_Type::historical_entity__T_unknown1d: return "historical_entity__T_unknown1d";
		case DF_Type::historical_entity__T_unknown1e: return "historical_entity__T_unknown1e";
		case DF_Type::historical_entity__T_unknown2: return "historical_entity__T_unknown2";
		case DF_Type::historical_entity__T_unknown2__T_unk28: return "historical_entity__T_unknown2__T_unk28";
		case DF_Type::historical_entity__T_unknown2__T_unk29: return "historical_entity__T_unknown2__T_unk29";
		case DF_Type::historical_entity_type: return "historical_entity_type";
		case DF_Type::historical_figure: return "historical_figure";
		case DF_Type::historical_figure__T_unk_fc: return "historical_figure__T_unk_fc";
		case DF_Type::historical_figure__T_unk_v47_2: return "historical_figure__T_unk_v47_2";
		case DF_Type::historical_figure__T_vague_relationships: return "historical_figure__T_vague_relationships";
		case DF_Type::historical_figure_info: return "historical_figure_info";
		case DF_Type::historical_figure_info__T_books: return "historical_figure_info__T_books";
		case DF_Type::historical_figure_info__T_books__T_flags: return "historical_figure_info__T_books__T_flags";
		case DF_Type::historical_figure_info__T_curse: return "historical_figure_info__T_curse";
		case DF_Type::historical_figure_info__T_curse__T_anon_1: return "historical_figure_info__T_curse__T_anon_1";
		case DF_Type::historical_figure_info__T_curse__T_experiments: return "historical_figure_info__T_curse__T_experiments";
		case DF_Type::historical_figure_info__T_known_info: return "historical_figure_info__T_known_info";
		case DF_Type::historical_figure_info__T_known_info__T_anon_1: return "historical_figure_info__T_known_info__T_anon_1";
		case DF_Type::historical_figure_info__T_known_info__T_anon_6: return "historical_figure_info__T_known_info__T_anon_6";
		case DF_Type::historical_figure_info__T_known_info__T_knowledge: return "historical_figure_info__T_known_info__T_knowledge";
		case DF_Type::historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal: return "historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal";
		case DF_Type::historical_figure_info__T_known_info__T_unk_a8: return "historical_figure_info__T_known_info__T_unk_a8";
		case DF_Type::historical_figure_info__T_masterpieces: return "historical_figure_info__T_masterpieces";
		case DF_Type::historical_figure_info__T_personality: return "historical_figure_info__T_personality";
		case DF_Type::historical_figure_info__T_relationships: return "historical_figure_info__T_relationships";
		case DF_Type::historical_figure_info__T_relationships__T_anon_1: return "historical_figure_info__T_relationships__T_anon_1";
		case DF_Type::historical_figure_info__T_relationships__T_artifact_claims: return "historical_figure_info__T_relationships__T_artifact_claims";
		case DF_Type::historical_figure_info__T_relationships__T_hf_historical: return "historical_figure_info__T_relationships__T_hf_historical";
		case DF_Type::historical_figure_info__T_relationships__T_hf_visual: return "historical_figure_info__T_relationships__T_hf_visual";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues: return "historical_figure_info__T_relationships__T_intrigues";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_intrigue: return "historical_figure_info__T_relationships__T_intrigues__T_intrigue";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots: return "historical_figure_info__T_relationships__T_intrigues__T_plots";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data: return "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Infiltrate_Society: return "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Infiltrate_Society";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Sabotage_Actor: return "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Sabotage_Actor";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type: return "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type";
		case DF_Type::historical_figure_info__T_reputation: return "historical_figure_info__T_reputation";
		case DF_Type::historical_figure_info__T_reputation__T_anon_1: return "historical_figure_info__T_reputation__T_anon_1";
		case DF_Type::historical_figure_info__T_reputation__T_unk_2c: return "historical_figure_info__T_reputation__T_unk_2c";
		case DF_Type::historical_figure_info__T_reputation__T_unk_2c__T_anon_12: return "historical_figure_info__T_reputation__T_unk_2c__T_anon_12";
		case DF_Type::historical_figure_info__T_reputation__T_wanted: return "historical_figure_info__T_reputation__T_wanted";
		case DF_Type::historical_figure_info__T_reputation__T_wanted__T_unk: return "historical_figure_info__T_reputation__T_wanted__T_unk";
		case DF_Type::historical_figure_info__T_skills: return "historical_figure_info__T_skills";
		case DF_Type::historical_figure_info__T_skills__T_employment_held: return "historical_figure_info__T_skills__T_employment_held";
		case DF_Type::historical_figure_info__T_skills__T_employment_held__T_employment: return "historical_figure_info__T_skills__T_employment_held__T_employment";
		case DF_Type::historical_figure_info__T_whereabouts: return "historical_figure_info__T_whereabouts";
		case DF_Type::historical_figure_info__T_wounds: return "historical_figure_info__T_wounds";
		case DF_Type::historical_kills: return "historical_kills";
		case DF_Type::history_era: return "history_era";
		case DF_Type::history_era__T_details: return "history_era__T_details";
		case DF_Type::history_era__T_title: return "history_era__T_title";
		case DF_Type::history_event: return "history_event";
		case DF_Type::history_event_add_entity_site_profile_flagst: return "history_event_add_entity_site_profile_flagst";
		case DF_Type::history_event_add_hf_entity_honorst: return "history_event_add_hf_entity_honorst";
		case DF_Type::history_event_add_hf_entity_linkst: return "history_event_add_hf_entity_linkst";
		case DF_Type::history_event_add_hf_hf_linkst: return "history_event_add_hf_hf_linkst";
		case DF_Type::history_event_add_hf_site_linkst: return "history_event_add_hf_site_linkst";
		case DF_Type::history_event_agreement_concludedst: return "history_event_agreement_concludedst";
		case DF_Type::history_event_agreement_formedst: return "history_event_agreement_formedst";
		case DF_Type::history_event_agreements_voidedst: return "history_event_agreements_voidedst";
		case DF_Type::history_event_artifact_claim_formedst: return "history_event_artifact_claim_formedst";
		case DF_Type::history_event_artifact_copiedst: return "history_event_artifact_copiedst";
		case DF_Type::history_event_artifact_copiedst__T_flags2: return "history_event_artifact_copiedst__T_flags2";
		case DF_Type::history_event_artifact_createdst: return "history_event_artifact_createdst";
		case DF_Type::history_event_artifact_createdst__T_flags2: return "history_event_artifact_createdst__T_flags2";
		case DF_Type::history_event_artifact_destroyedst: return "history_event_artifact_destroyedst";
		case DF_Type::history_event_artifact_droppedst: return "history_event_artifact_droppedst";
		case DF_Type::history_event_artifact_foundst: return "history_event_artifact_foundst";
		case DF_Type::history_event_artifact_givenst: return "history_event_artifact_givenst";
		case DF_Type::history_event_artifact_hiddenst: return "history_event_artifact_hiddenst";
		case DF_Type::history_event_artifact_lostst: return "history_event_artifact_lostst";
		case DF_Type::history_event_artifact_possessedst: return "history_event_artifact_possessedst";
		case DF_Type::history_event_artifact_recoveredst: return "history_event_artifact_recoveredst";
		case DF_Type::history_event_artifact_storedst: return "history_event_artifact_storedst";
		case DF_Type::history_event_artifact_transformedst: return "history_event_artifact_transformedst";
		case DF_Type::history_event_assume_identityst: return "history_event_assume_identityst";
		case DF_Type::history_event_body_abusedst: return "history_event_body_abusedst";
		case DF_Type::history_event_body_abusedst__T_abuse_data: return "history_event_body_abusedst__T_abuse_data";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Animated: return "history_event_body_abusedst__T_abuse_data__T_Animated";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Flayed: return "history_event_body_abusedst__T_abuse_data__T_Flayed";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Hung: return "history_event_body_abusedst__T_abuse_data__T_Hung";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Impaled: return "history_event_body_abusedst__T_abuse_data__T_Impaled";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled: return "history_event_body_abusedst__T_abuse_data__T_Piled";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type: return "history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type";
		case DF_Type::history_event_body_abusedst__T_abuse_type: return "history_event_body_abusedst__T_abuse_type";
		case DF_Type::history_event_building_profile_acquiredst: return "history_event_building_profile_acquiredst";
		case DF_Type::history_event_ceremonyst: return "history_event_ceremonyst";
		case DF_Type::history_event_change_creature_typest: return "history_event_change_creature_typest";
		case DF_Type::history_event_change_hf_body_statest: return "history_event_change_hf_body_statest";
		case DF_Type::history_event_change_hf_jobst: return "history_event_change_hf_jobst";
		case DF_Type::history_event_change_hf_moodst: return "history_event_change_hf_moodst";
		case DF_Type::history_event_change_hf_statest: return "history_event_change_hf_statest";
		case DF_Type::history_event_change_hf_statest__T_state: return "history_event_change_hf_statest__T_state";
		case DF_Type::history_event_circumstance_info: return "history_event_circumstance_info";
		case DF_Type::history_event_circumstance_info__T_data: return "history_event_circumstance_info__T_data";
		case DF_Type::history_event_collection: return "history_event_collection";
		case DF_Type::history_event_collection_abductionst: return "history_event_collection_abductionst";
		case DF_Type::history_event_collection_battlest: return "history_event_collection_battlest";
		case DF_Type::history_event_collection_battlest__T_attacker_merc_type: return "history_event_collection_battlest__T_attacker_merc_type";
		case DF_Type::history_event_collection_beast_attackst: return "history_event_collection_beast_attackst";
		case DF_Type::history_event_collection_ceremonyst: return "history_event_collection_ceremonyst";
		case DF_Type::history_event_collection_competitionst: return "history_event_collection_competitionst";
		case DF_Type::history_event_collection_duelst: return "history_event_collection_duelst";
		case DF_Type::history_event_collection_entity_overthrownst: return "history_event_collection_entity_overthrownst";
		case DF_Type::history_event_collection_insurrectionst: return "history_event_collection_insurrectionst";
		case DF_Type::history_event_collection_journeyst: return "history_event_collection_journeyst";
		case DF_Type::history_event_collection_occasionst: return "history_event_collection_occasionst";
		case DF_Type::history_event_collection_performancest: return "history_event_collection_performancest";
		case DF_Type::history_event_collection_persecutionst: return "history_event_collection_persecutionst";
		case DF_Type::history_event_collection_processionst: return "history_event_collection_processionst";
		case DF_Type::history_event_collection_purgest: return "history_event_collection_purgest";
		case DF_Type::history_event_collection_raidst: return "history_event_collection_raidst";
		case DF_Type::history_event_collection_site_conqueredst: return "history_event_collection_site_conqueredst";
		case DF_Type::history_event_collection_theftst: return "history_event_collection_theftst";
		case DF_Type::history_event_collection_type: return "history_event_collection_type";
		case DF_Type::history_event_collection_warst: return "history_event_collection_warst";
		case DF_Type::history_event_collection_warst__T_unk: return "history_event_collection_warst__T_unk";
		case DF_Type::history_event_competitionst: return "history_event_competitionst";
		case DF_Type::history_event_context: return "history_event_context";
		case DF_Type::history_event_context__T_unk_10: return "history_event_context__T_unk_10";
		case DF_Type::history_event_create_entity_positionst: return "history_event_create_entity_positionst";
		case DF_Type::history_event_created_buildingst: return "history_event_created_buildingst";
		case DF_Type::history_event_created_sitest: return "history_event_created_sitest";
		case DF_Type::history_event_created_world_constructionst: return "history_event_created_world_constructionst";
		case DF_Type::history_event_creature_devouredst: return "history_event_creature_devouredst";
		case DF_Type::history_event_dance_form_createdst: return "history_event_dance_form_createdst";
		case DF_Type::history_event_diplomat_lostst: return "history_event_diplomat_lostst";
		case DF_Type::history_event_entity_actionst: return "history_event_entity_actionst";
		case DF_Type::history_event_entity_alliance_formedst: return "history_event_entity_alliance_formedst";
		case DF_Type::history_event_entity_breach_feature_layerst: return "history_event_entity_breach_feature_layerst";
		case DF_Type::history_event_entity_createdst: return "history_event_entity_createdst";
		case DF_Type::history_event_entity_dissolvedst: return "history_event_entity_dissolvedst";
		case DF_Type::history_event_entity_equipment_purchasest: return "history_event_entity_equipment_purchasest";
		case DF_Type::history_event_entity_expels_hfst: return "history_event_entity_expels_hfst";
		case DF_Type::history_event_entity_fled_sitest: return "history_event_entity_fled_sitest";
		case DF_Type::history_event_entity_incorporatedst: return "history_event_entity_incorporatedst";
		case DF_Type::history_event_entity_lawst: return "history_event_entity_lawst";
		case DF_Type::history_event_entity_lawst__T_add_flags: return "history_event_entity_lawst__T_add_flags";
		case DF_Type::history_event_entity_lawst__T_remove_flags: return "history_event_entity_lawst__T_remove_flags";
		case DF_Type::history_event_entity_overthrownst: return "history_event_entity_overthrownst";
		case DF_Type::history_event_entity_persecutedst: return "history_event_entity_persecutedst";
		case DF_Type::history_event_entity_rampaged_in_sitest: return "history_event_entity_rampaged_in_sitest";
		case DF_Type::history_event_entity_razed_buildingst: return "history_event_entity_razed_buildingst";
		case DF_Type::history_event_entity_searched_sitest: return "history_event_entity_searched_sitest";
		case DF_Type::history_event_failed_frame_attemptst: return "history_event_failed_frame_attemptst";
		case DF_Type::history_event_failed_intrigue_corruptionst: return "history_event_failed_intrigue_corruptionst";
		case DF_Type::history_event_first_contact_failedst: return "history_event_first_contact_failedst";
		case DF_Type::history_event_first_contactst: return "history_event_first_contactst";
		case DF_Type::history_event_flags: return "history_event_flags";
		case DF_Type::history_event_gamblest: return "history_event_gamblest";
		case DF_Type::history_event_hf_act_on_artifactst: return "history_event_hf_act_on_artifactst";
		case DF_Type::history_event_hf_act_on_artifactst__T_action: return "history_event_hf_act_on_artifactst__T_action";
		case DF_Type::history_event_hf_act_on_buildingst: return "history_event_hf_act_on_buildingst";
		case DF_Type::history_event_hf_act_on_buildingst__T_action: return "history_event_hf_act_on_buildingst__T_action";
		case DF_Type::history_event_hf_attacked_sitest: return "history_event_hf_attacked_sitest";
		case DF_Type::history_event_hf_confrontedst: return "history_event_hf_confrontedst";
		case DF_Type::history_event_hf_convictedst: return "history_event_hf_convictedst";
		case DF_Type::history_event_hf_convictedst__T_plot_flags: return "history_event_hf_convictedst__T_plot_flags";
		case DF_Type::history_event_hf_convictedst__T_punishment_flags: return "history_event_hf_convictedst__T_punishment_flags";
		case DF_Type::history_event_hf_destroyed_sitest: return "history_event_hf_destroyed_sitest";
		case DF_Type::history_event_hf_does_interactionst: return "history_event_hf_does_interactionst";
		case DF_Type::history_event_hf_enslavedst: return "history_event_hf_enslavedst";
		case DF_Type::history_event_hf_freedst: return "history_event_hf_freedst";
		case DF_Type::history_event_hf_gains_secret_goalst: return "history_event_hf_gains_secret_goalst";
		case DF_Type::history_event_hf_interrogatedst: return "history_event_hf_interrogatedst";
		case DF_Type::history_event_hf_interrogatedst__T_interrogation_flags: return "history_event_hf_interrogatedst__T_interrogation_flags";
		case DF_Type::history_event_hf_learns_secretst: return "history_event_hf_learns_secretst";
		case DF_Type::history_event_hf_preachst: return "history_event_hf_preachst";
		case DF_Type::history_event_hf_ransomedst: return "history_event_hf_ransomedst";
		case DF_Type::history_event_hf_razed_buildingst: return "history_event_hf_razed_buildingst";
		case DF_Type::history_event_hf_recruited_unit_type_for_entityst: return "history_event_hf_recruited_unit_type_for_entityst";
		case DF_Type::history_event_hf_relationship_deniedst: return "history_event_hf_relationship_deniedst";
		case DF_Type::history_event_hfs_formed_intrigue_relationshipst: return "history_event_hfs_formed_intrigue_relationshipst";
		case DF_Type::history_event_hfs_formed_reputation_relationshipst: return "history_event_hfs_formed_reputation_relationshipst";
		case DF_Type::history_event_hist_figure_abductedst: return "history_event_hist_figure_abductedst";
		case DF_Type::history_event_hist_figure_diedst: return "history_event_hist_figure_diedst";
		case DF_Type::history_event_hist_figure_new_petst: return "history_event_hist_figure_new_petst";
		case DF_Type::history_event_hist_figure_reach_summitst: return "history_event_hist_figure_reach_summitst";
		case DF_Type::history_event_hist_figure_reunionst: return "history_event_hist_figure_reunionst";
		case DF_Type::history_event_hist_figure_revivedst: return "history_event_hist_figure_revivedst";
		case DF_Type::history_event_hist_figure_revivedst__T_flags2: return "history_event_hist_figure_revivedst__T_flags2";
		case DF_Type::history_event_hist_figure_simple_actionst: return "history_event_hist_figure_simple_actionst";
		case DF_Type::history_event_hist_figure_simple_battle_eventst: return "history_event_hist_figure_simple_battle_eventst";
		case DF_Type::history_event_hist_figure_travelst: return "history_event_hist_figure_travelst";
		case DF_Type::history_event_hist_figure_travelst__T_reason: return "history_event_hist_figure_travelst__T_reason";
		case DF_Type::history_event_hist_figure_woundedst: return "history_event_hist_figure_woundedst";
		case DF_Type::history_event_hist_figure_woundedst__T_flags2: return "history_event_hist_figure_woundedst__T_flags2";
		case DF_Type::history_event_hist_figure_woundedst__T_injury_type: return "history_event_hist_figure_woundedst__T_injury_type";
		case DF_Type::history_event_insurrection_endedst: return "history_event_insurrection_endedst";
		case DF_Type::history_event_insurrection_startedst: return "history_event_insurrection_startedst";
		case DF_Type::history_event_item_stolenst: return "history_event_item_stolenst";
		case DF_Type::history_event_knowledge_discoveredst: return "history_event_knowledge_discoveredst";
		case DF_Type::history_event_masterpiece_created_arch_constructst: return "history_event_masterpiece_created_arch_constructst";
		case DF_Type::history_event_masterpiece_created_arch_designst: return "history_event_masterpiece_created_arch_designst";
		case DF_Type::history_event_masterpiece_created_dye_itemst: return "history_event_masterpiece_created_dye_itemst";
		case DF_Type::history_event_masterpiece_created_engravingst: return "history_event_masterpiece_created_engravingst";
		case DF_Type::history_event_masterpiece_created_foodst: return "history_event_masterpiece_created_foodst";
		case DF_Type::history_event_masterpiece_created_item_improvementst: return "history_event_masterpiece_created_item_improvementst";
		case DF_Type::history_event_masterpiece_created_itemst: return "history_event_masterpiece_created_itemst";
		case DF_Type::history_event_masterpiece_createdst: return "history_event_masterpiece_createdst";
		case DF_Type::history_event_masterpiece_lostst: return "history_event_masterpiece_lostst";
		case DF_Type::history_event_merchantst: return "history_event_merchantst";
		case DF_Type::history_event_modified_buildingst: return "history_event_modified_buildingst";
		case DF_Type::history_event_modified_buildingst__T_modification: return "history_event_modified_buildingst__T_modification";
		case DF_Type::history_event_musical_form_createdst: return "history_event_musical_form_createdst";
		case DF_Type::history_event_performancest: return "history_event_performancest";
		case DF_Type::history_event_poetic_form_createdst: return "history_event_poetic_form_createdst";
		case DF_Type::history_event_processionst: return "history_event_processionst";
		case DF_Type::history_event_reason: return "history_event_reason";
		case DF_Type::history_event_reason_info: return "history_event_reason_info";
		case DF_Type::history_event_reason_info__T_data: return "history_event_reason_info__T_data";
		case DF_Type::history_event_reclaim_sitest: return "history_event_reclaim_sitest";
		case DF_Type::history_event_reclaim_sitest__T_flags2: return "history_event_reclaim_sitest__T_flags2";
		case DF_Type::history_event_regionpop_incorporated_into_entityst: return "history_event_regionpop_incorporated_into_entityst";
		case DF_Type::history_event_remove_hf_entity_linkst: return "history_event_remove_hf_entity_linkst";
		case DF_Type::history_event_remove_hf_hf_linkst: return "history_event_remove_hf_hf_linkst";
		case DF_Type::history_event_remove_hf_site_linkst: return "history_event_remove_hf_site_linkst";
		case DF_Type::history_event_replaced_buildingst: return "history_event_replaced_buildingst";
		case DF_Type::history_event_sabotagest: return "history_event_sabotagest";
		case DF_Type::history_event_simple_battle_subtype: return "history_event_simple_battle_subtype";
		case DF_Type::history_event_site_diedst: return "history_event_site_diedst";
		case DF_Type::history_event_site_diedst__T_flags2: return "history_event_site_diedst__T_flags2";
		case DF_Type::history_event_site_disputest: return "history_event_site_disputest";
		case DF_Type::history_event_site_retiredst: return "history_event_site_retiredst";
		case DF_Type::history_event_site_retiredst__T_flags2: return "history_event_site_retiredst__T_flags2";
		case DF_Type::history_event_site_surrenderedst: return "history_event_site_surrenderedst";
		case DF_Type::history_event_sneak_into_sitest: return "history_event_sneak_into_sitest";
		case DF_Type::history_event_spotted_leaving_sitest: return "history_event_spotted_leaving_sitest";
		case DF_Type::history_event_squad_vs_squadst: return "history_event_squad_vs_squadst";
		case DF_Type::history_event_tactical_situationst: return "history_event_tactical_situationst";
		case DF_Type::history_event_tactical_situationst__T_tactics_flags: return "history_event_tactical_situationst__T_tactics_flags";
		case DF_Type::history_event_topicagreement_concludedst: return "history_event_topicagreement_concludedst";
		case DF_Type::history_event_topicagreement_madest: return "history_event_topicagreement_madest";
		case DF_Type::history_event_topicagreement_rejectedst: return "history_event_topicagreement_rejectedst";
		case DF_Type::history_event_tradest: return "history_event_tradest";
		case DF_Type::history_event_type: return "history_event_type";
		case DF_Type::history_event_war_attacked_sitest: return "history_event_war_attacked_sitest";
		case DF_Type::history_event_war_attacked_sitest__T_unk_1: return "history_event_war_attacked_sitest__T_unk_1";
		case DF_Type::history_event_war_destroyed_sitest: return "history_event_war_destroyed_sitest";
		case DF_Type::history_event_war_field_battlest: return "history_event_war_field_battlest";
		case DF_Type::history_event_war_peace_acceptedst: return "history_event_war_peace_acceptedst";
		case DF_Type::history_event_war_peace_rejectedst: return "history_event_war_peace_rejectedst";
		case DF_Type::history_event_war_plundered_sitest: return "history_event_war_plundered_sitest";
		case DF_Type::history_event_war_site_new_leaderst: return "history_event_war_site_new_leaderst";
		case DF_Type::history_event_war_site_taken_overst: return "history_event_war_site_taken_overst";
		case DF_Type::history_event_war_site_tribute_forcedst: return "history_event_war_site_tribute_forcedst";
		case DF_Type::history_event_war_site_tribute_forcedst__T_tribute_flags: return "history_event_war_site_tribute_forcedst__T_tribute_flags";
		case DF_Type::history_event_written_content_composedst: return "history_event_written_content_composedst";
		case DF_Type::history_hit_item: return "history_hit_item";
		case DF_Type::hive_flags: return "hive_flags";
		case DF_Type::honors_type: return "honors_type";
		case DF_Type::honors_type__T_flags: return "honors_type__T_flags";
		case DF_Type::honors_type__T_required_skill_type: return "honors_type__T_required_skill_type";
		case DF_Type::hospital_supplies: return "hospital_supplies";
		case DF_Type::hospital_supplies__T_supplies_needed: return "hospital_supplies__T_supplies_needed";
		case DF_Type::identity: return "identity";
		case DF_Type::identity___union1: return "identity___union1";
		case DF_Type::identity_type: return "identity_type";
		case DF_Type::identity_unk_94: return "identity_unk_94";
		case DF_Type::image_set: return "image_set";
		case DF_Type::image_set__T_unk_vec1: return "image_set__T_unk_vec1";
		case DF_Type::improvement_type: return "improvement_type";
		case DF_Type::incident: return "incident";
		case DF_Type::incident__T_data: return "incident__T_data";
		case DF_Type::incident__T_flags: return "incident__T_flags";
		case DF_Type::incident__T_type: return "incident__T_type";
		case DF_Type::incident_hfid: return "incident_hfid";
		case DF_Type::incident_sub10: return "incident_sub10";
		case DF_Type::incident_sub6_performance: return "incident_sub6_performance";
		case DF_Type::incident_sub6_performance__T_participants: return "incident_sub6_performance__T_participants";
		case DF_Type::incident_sub7: return "incident_sub7";
		case DF_Type::incident_sub8: return "incident_sub8";
		case DF_Type::incident_sub9: return "incident_sub9";
		case DF_Type::inclusion_type: return "inclusion_type";
		case DF_Type::init: return "init";
		case DF_Type::init_display: return "init_display";
		case DF_Type::init_display__T_windowed: return "init_display__T_windowed";
		case DF_Type::init_display_flags: return "init_display_flags";
		case DF_Type::init_font: return "init_font";
		case DF_Type::init_font__T_use_ttf: return "init_font__T_use_ttf";
		case DF_Type::init_input: return "init_input";
		case DF_Type::init_input_flags: return "init_input_flags";
		case DF_Type::init_media: return "init_media";
		case DF_Type::init_media_flags: return "init_media_flags";
		case DF_Type::init_window: return "init_window";
		case DF_Type::init_window_flags: return "init_window_flags";
		case DF_Type::inorganic_flags: return "inorganic_flags";
		case DF_Type::inorganic_raw: return "inorganic_raw";
		case DF_Type::inorganic_raw__T_environment: return "inorganic_raw__T_environment";
		case DF_Type::inorganic_raw__T_environment_spec: return "inorganic_raw__T_environment_spec";
		case DF_Type::inorganic_raw__T_metal_ore: return "inorganic_raw__T_metal_ore";
		case DF_Type::inorganic_raw__T_thread_metal: return "inorganic_raw__T_thread_metal";
		case DF_Type::instrument_flags: return "instrument_flags";
		case DF_Type::instrument_piece: return "instrument_piece";
		case DF_Type::instrument_piece__T_flags: return "instrument_piece__T_flags";
		case DF_Type::instrument_register: return "instrument_register";
		case DF_Type::insurrection_outcome: return "insurrection_outcome";
		case DF_Type::interaction: return "interaction";
		case DF_Type::interaction_effect: return "interaction_effect";
		case DF_Type::interaction_effect__T_flags: return "interaction_effect__T_flags";
		case DF_Type::interaction_effect_add_syndromest: return "interaction_effect_add_syndromest";
		case DF_Type::interaction_effect_animatest: return "interaction_effect_animatest";
		case DF_Type::interaction_effect_change_item_qualityst: return "interaction_effect_change_item_qualityst";
		case DF_Type::interaction_effect_change_weatherst: return "interaction_effect_change_weatherst";
		case DF_Type::interaction_effect_cleanst: return "interaction_effect_cleanst";
		case DF_Type::interaction_effect_contactst: return "interaction_effect_contactst";
		case DF_Type::interaction_effect_create_itemst: return "interaction_effect_create_itemst";
		case DF_Type::interaction_effect_hidest: return "interaction_effect_hidest";
		case DF_Type::interaction_effect_location_hint: return "interaction_effect_location_hint";
		case DF_Type::interaction_effect_material_emissionst: return "interaction_effect_material_emissionst";
		case DF_Type::interaction_effect_propel_unitst: return "interaction_effect_propel_unitst";
		case DF_Type::interaction_effect_resurrectst: return "interaction_effect_resurrectst";
		case DF_Type::interaction_effect_summon_unitst: return "interaction_effect_summon_unitst";
		case DF_Type::interaction_effect_type: return "interaction_effect_type";
		case DF_Type::interaction_flags: return "interaction_flags";
		case DF_Type::interaction_instance: return "interaction_instance";
		case DF_Type::interaction_source: return "interaction_source";
		case DF_Type::interaction_source_attackst: return "interaction_source_attackst";
		case DF_Type::interaction_source_creature_actionst: return "interaction_source_creature_actionst";
		case DF_Type::interaction_source_deityst: return "interaction_source_deityst";
		case DF_Type::interaction_source_disturbancest: return "interaction_source_disturbancest";
		case DF_Type::interaction_source_experimentst: return "interaction_source_experimentst";
		case DF_Type::interaction_source_ingestionst: return "interaction_source_ingestionst";
		case DF_Type::interaction_source_regionst: return "interaction_source_regionst";
		case DF_Type::interaction_source_regionst__T_region_flags: return "interaction_source_regionst__T_region_flags";
		case DF_Type::interaction_source_secretst: return "interaction_source_secretst";
		case DF_Type::interaction_source_secretst__T_learn_flags: return "interaction_source_secretst__T_learn_flags";
		case DF_Type::interaction_source_type: return "interaction_source_type";
		case DF_Type::interaction_source_underground_specialst: return "interaction_source_underground_specialst";
		case DF_Type::interaction_source_usage_hint: return "interaction_source_usage_hint";
		case DF_Type::interaction_target: return "interaction_target";
		case DF_Type::interaction_target_corpsest: return "interaction_target_corpsest";
		case DF_Type::interaction_target_creaturest: return "interaction_target_creaturest";
		case DF_Type::interaction_target_info: return "interaction_target_info";
		case DF_Type::interaction_target_info__T_restrictions: return "interaction_target_info__T_restrictions";
		case DF_Type::interaction_target_location_type: return "interaction_target_location_type";
		case DF_Type::interaction_target_locationst: return "interaction_target_locationst";
		case DF_Type::interaction_target_materialst: return "interaction_target_materialst";
		case DF_Type::interaction_target_materialst__T_restrictions: return "interaction_target_materialst__T_restrictions";
		case DF_Type::interaction_target_type: return "interaction_target_type";
		case DF_Type::interface_breakdown_types: return "interface_breakdown_types";
		case DF_Type::interface_button: return "interface_button";
		case DF_Type::interface_button_building_category_selectorst: return "interface_button_building_category_selectorst";
		case DF_Type::interface_button_building_custom_category_selectorst: return "interface_button_building_custom_category_selectorst";
		case DF_Type::interface_button_building_material_selectorst: return "interface_button_building_material_selectorst";
		case DF_Type::interface_button_building_new_jobst: return "interface_button_building_new_jobst";
		case DF_Type::interface_button_buildingst: return "interface_button_buildingst";
		case DF_Type::interface_button_construction_building_selectorst: return "interface_button_construction_building_selectorst";
		case DF_Type::interface_button_construction_category_selectorst: return "interface_button_construction_category_selectorst";
		case DF_Type::interface_button_construction_category_selectorst__T_category_id: return "interface_button_construction_category_selectorst__T_category_id";
		case DF_Type::interface_button_construction_donest: return "interface_button_construction_donest";
		case DF_Type::interface_button_constructionst: return "interface_button_constructionst";
		case DF_Type::interface_key: return "interface_key";
		case DF_Type::interfacest: return "interfacest";
		case DF_Type::interrogation_report: return "interrogation_report";
		case DF_Type::invasion_info: return "invasion_info";
		case DF_Type::invasion_info__T_flags: return "invasion_info__T_flags";
		case DF_Type::item: return "item";
		case DF_Type::item_actual: return "item_actual";
		case DF_Type::item_ammost: return "item_ammost";
		case DF_Type::item_amuletst: return "item_amuletst";
		case DF_Type::item_animaltrapst: return "item_animaltrapst";
		case DF_Type::item_anvilst: return "item_anvilst";
		case DF_Type::item_armorst: return "item_armorst";
		case DF_Type::item_armorstandst: return "item_armorstandst";
		case DF_Type::item_backpackst: return "item_backpackst";
		case DF_Type::item_ballistaarrowheadst: return "item_ballistaarrowheadst";
		case DF_Type::item_ballistapartsst: return "item_ballistapartsst";
		case DF_Type::item_barrelst: return "item_barrelst";
		case DF_Type::item_barst: return "item_barst";
		case DF_Type::item_bedst: return "item_bedst";
		case DF_Type::item_binst: return "item_binst";
		case DF_Type::item_blocksst: return "item_blocksst";
		case DF_Type::item_body_component: return "item_body_component";
		case DF_Type::item_body_component__T_appearance: return "item_body_component__T_appearance";
		case DF_Type::item_body_component__T_body: return "item_body_component__T_body";
		case DF_Type::item_body_component__T_bone1: return "item_body_component__T_bone1";
		case DF_Type::item_body_component__T_bone2: return "item_body_component__T_bone2";
		case DF_Type::item_body_component__T_corpse_flags: return "item_body_component__T_corpse_flags";
		case DF_Type::item_bookst: return "item_bookst";
		case DF_Type::item_boulderst: return "item_boulderst";
		case DF_Type::item_boxst: return "item_boxst";
		case DF_Type::item_braceletst: return "item_braceletst";
		case DF_Type::item_branchst: return "item_branchst";
		case DF_Type::item_bucketst: return "item_bucketst";
		case DF_Type::item_cabinetst: return "item_cabinetst";
		case DF_Type::item_cagest: return "item_cagest";
		case DF_Type::item_catapultpartsst: return "item_catapultpartsst";
		case DF_Type::item_chainst: return "item_chainst";
		case DF_Type::item_chairst: return "item_chairst";
		case DF_Type::item_cheesest: return "item_cheesest";
		case DF_Type::item_clothst: return "item_clothst";
		case DF_Type::item_coffinst: return "item_coffinst";
		case DF_Type::item_coinst: return "item_coinst";
		case DF_Type::item_constructed: return "item_constructed";
		case DF_Type::item_corpsepiecest: return "item_corpsepiecest";
		case DF_Type::item_corpsest: return "item_corpsest";
		case DF_Type::item_crafted: return "item_crafted";
		case DF_Type::item_critter: return "item_critter";
		case DF_Type::item_crownst: return "item_crownst";
		case DF_Type::item_crutchst: return "item_crutchst";
		case DF_Type::item_doorst: return "item_doorst";
		case DF_Type::item_drinkst: return "item_drinkst";
		case DF_Type::item_earringst: return "item_earringst";
		case DF_Type::item_eggst: return "item_eggst";
		case DF_Type::item_eggst__T_egg_flags: return "item_eggst__T_egg_flags";
		case DF_Type::item_figurinest: return "item_figurinest";
		case DF_Type::item_filter_spec: return "item_filter_spec";
		case DF_Type::item_fish_rawst: return "item_fish_rawst";
		case DF_Type::item_fishst: return "item_fishst";
		case DF_Type::item_flags: return "item_flags";
		case DF_Type::item_flags2: return "item_flags2";
		case DF_Type::item_flaskst: return "item_flaskst";
		case DF_Type::item_floodgatest: return "item_floodgatest";
		case DF_Type::item_foodst: return "item_foodst";
		case DF_Type::item_foodst__T_ingredients: return "item_foodst__T_ingredients";
		case DF_Type::item_gemst: return "item_gemst";
		case DF_Type::item_globst: return "item_globst";
		case DF_Type::item_glovesst: return "item_glovesst";
		case DF_Type::item_gobletst: return "item_gobletst";
		case DF_Type::item_gratest: return "item_gratest";
		case DF_Type::item_hatch_coverst: return "item_hatch_coverst";
		case DF_Type::item_helmst: return "item_helmst";
		case DF_Type::item_history_info: return "item_history_info";
		case DF_Type::item_instrumentst: return "item_instrumentst";
		case DF_Type::item_kill_info: return "item_kill_info";
		case DF_Type::item_liquid: return "item_liquid";
		case DF_Type::item_liquid_miscst: return "item_liquid_miscst";
		case DF_Type::item_liquipowder: return "item_liquipowder";
		case DF_Type::item_magicness: return "item_magicness";
		case DF_Type::item_magicness_type: return "item_magicness_type";
		case DF_Type::item_matstate: return "item_matstate";
		case DF_Type::item_meatst: return "item_meatst";
		case DF_Type::item_millstonest: return "item_millstonest";
		case DF_Type::item_orthopedic_castst: return "item_orthopedic_castst";
		case DF_Type::item_pantsst: return "item_pantsst";
		case DF_Type::item_petst: return "item_petst";
		case DF_Type::item_petst__T_pet_flags: return "item_petst__T_pet_flags";
		case DF_Type::item_pipe_sectionst: return "item_pipe_sectionst";
		case DF_Type::item_plant_growthst: return "item_plant_growthst";
		case DF_Type::item_plantst: return "item_plantst";
		case DF_Type::item_powder: return "item_powder";
		case DF_Type::item_powder_miscst: return "item_powder_miscst";
		case DF_Type::item_quality: return "item_quality";
		case DF_Type::item_quernst: return "item_quernst";
		case DF_Type::item_quiverst: return "item_quiverst";
		case DF_Type::item_remainsst: return "item_remainsst";
		case DF_Type::item_ringst: return "item_ringst";
		case DF_Type::item_rockst: return "item_rockst";
		case DF_Type::item_roughst: return "item_roughst";
		case DF_Type::item_scepterst: return "item_scepterst";
		case DF_Type::item_seedsst: return "item_seedsst";
		case DF_Type::item_sheetst: return "item_sheetst";
		case DF_Type::item_shieldst: return "item_shieldst";
		case DF_Type::item_shoesst: return "item_shoesst";
		case DF_Type::item_siegeammost: return "item_siegeammost";
		case DF_Type::item_skin_tannedst: return "item_skin_tannedst";
		case DF_Type::item_slabst: return "item_slabst";
		case DF_Type::item_smallgemst: return "item_smallgemst";
		case DF_Type::item_splintst: return "item_splintst";
		case DF_Type::item_statuest: return "item_statuest";
		case DF_Type::item_stockpile_ref: return "item_stockpile_ref";
		case DF_Type::item_tablest: return "item_tablest";
		case DF_Type::item_threadst: return "item_threadst";
		case DF_Type::item_toolst: return "item_toolst";
		case DF_Type::item_totemst: return "item_totemst";
		case DF_Type::item_toyst: return "item_toyst";
		case DF_Type::item_traction_benchst: return "item_traction_benchst";
		case DF_Type::item_trapcompst: return "item_trapcompst";
		case DF_Type::item_trappartsst: return "item_trappartsst";
		case DF_Type::item_type: return "item_type";
		case DF_Type::item_verminst: return "item_verminst";
		case DF_Type::item_weaponrackst: return "item_weaponrackst";
		case DF_Type::item_weaponst: return "item_weaponst";
		case DF_Type::item_windowst: return "item_windowst";
		case DF_Type::item_woodst: return "item_woodst";
		case DF_Type::itemdef: return "itemdef";
		case DF_Type::itemdef_ammost: return "itemdef_ammost";
		case DF_Type::itemdef_armorst: return "itemdef_armorst";
		case DF_Type::itemdef_flags: return "itemdef_flags";
		case DF_Type::itemdef_foodst: return "itemdef_foodst";
		case DF_Type::itemdef_glovesst: return "itemdef_glovesst";
		case DF_Type::itemdef_helmst: return "itemdef_helmst";
		case DF_Type::itemdef_instrumentst: return "itemdef_instrumentst";
		case DF_Type::itemdef_pantsst: return "itemdef_pantsst";
		case DF_Type::itemdef_shieldst: return "itemdef_shieldst";
		case DF_Type::itemdef_shoesst: return "itemdef_shoesst";
		case DF_Type::itemdef_siegeammost: return "itemdef_siegeammost";
		case DF_Type::itemdef_toolst: return "itemdef_toolst";
		case DF_Type::itemdef_toolst__T_default_improvements: return "itemdef_toolst__T_default_improvements";
		case DF_Type::itemdef_toyst: return "itemdef_toyst";
		case DF_Type::itemdef_trapcompst: return "itemdef_trapcompst";
		case DF_Type::itemdef_weaponst: return "itemdef_weaponst";
		case DF_Type::itemimprovement: return "itemimprovement";
		case DF_Type::itemimprovement_art_imagest: return "itemimprovement_art_imagest";
		case DF_Type::itemimprovement_bandsst: return "itemimprovement_bandsst";
		case DF_Type::itemimprovement_clothst: return "itemimprovement_clothst";
		case DF_Type::itemimprovement_coveredst: return "itemimprovement_coveredst";
		case DF_Type::itemimprovement_coveredst__T_cover_flags: return "itemimprovement_coveredst__T_cover_flags";
		case DF_Type::itemimprovement_illustrationst: return "itemimprovement_illustrationst";
		case DF_Type::itemimprovement_instrument_piecest: return "itemimprovement_instrument_piecest";
		case DF_Type::itemimprovement_itemspecificst: return "itemimprovement_itemspecificst";
		case DF_Type::itemimprovement_pagesst: return "itemimprovement_pagesst";
		case DF_Type::itemimprovement_rings_hangingst: return "itemimprovement_rings_hangingst";
		case DF_Type::itemimprovement_sewn_imagest: return "itemimprovement_sewn_imagest";
		case DF_Type::itemimprovement_sewn_imagest__T_cloth: return "itemimprovement_sewn_imagest__T_cloth";
		case DF_Type::itemimprovement_specific_type: return "itemimprovement_specific_type";
		case DF_Type::itemimprovement_spikesst: return "itemimprovement_spikesst";
		case DF_Type::itemimprovement_threadst: return "itemimprovement_threadst";
		case DF_Type::itemimprovement_writingst: return "itemimprovement_writingst";
		case DF_Type::items_other_id: return "items_other_id";
		case DF_Type::job: return "job";
		case DF_Type::job_art_specification: return "job_art_specification";
		case DF_Type::job_art_specification__T_type: return "job_art_specification__T_type";
		case DF_Type::job_flags: return "job_flags";
		case DF_Type::job_handler: return "job_handler";
		case DF_Type::job_handler__T_anon_1: return "job_handler__T_anon_1";
		case DF_Type::job_handler__T_postings: return "job_handler__T_postings";
		case DF_Type::job_handler__T_postings__T_flags: return "job_handler__T_postings__T_flags";
		case DF_Type::job_item: return "job_item";
		case DF_Type::job_item_filter: return "job_item_filter";
		case DF_Type::job_item_flags1: return "job_item_flags1";
		case DF_Type::job_item_flags2: return "job_item_flags2";
		case DF_Type::job_item_flags3: return "job_item_flags3";
		case DF_Type::job_item_ref: return "job_item_ref";
		case DF_Type::job_item_ref__T_role: return "job_item_ref__T_role";
		case DF_Type::job_item_vector_id: return "job_item_vector_id";
		case DF_Type::job_list_link: return "job_list_link";
		case DF_Type::job_material_category: return "job_material_category";
		case DF_Type::job_skill: return "job_skill";
		case DF_Type::job_skill_class: return "job_skill_class";
		case DF_Type::job_subtype_surgery: return "job_subtype_surgery";
		case DF_Type::job_type: return "job_type";
		case DF_Type::job_type_class: return "job_type_class";
		case DF_Type::justification: return "justification";
		case DF_Type::KeybindingScreen: return "KeybindingScreen";
		case DF_Type::KeybindingScreen__T_mode: return "KeybindingScreen__T_mode";
		case DF_Type::kitchen_exc_type: return "kitchen_exc_type";
		case DF_Type::kitchen_pref_flag: return "kitchen_pref_flag";
		case DF_Type::knowledge_scholar_category_flag: return "knowledge_scholar_category_flag";
		case DF_Type::knowledge_scholar_category_flag__T_flag_data: return "knowledge_scholar_category_flag__T_flag_data";
		case DF_Type::knowledge_scholar_category_flag__T_flag_type: return "knowledge_scholar_category_flag__T_flag_type";
		case DF_Type::knowledge_scholar_flags_0: return "knowledge_scholar_flags_0";
		case DF_Type::knowledge_scholar_flags_1: return "knowledge_scholar_flags_1";
		case DF_Type::knowledge_scholar_flags_10: return "knowledge_scholar_flags_10";
		case DF_Type::knowledge_scholar_flags_11: return "knowledge_scholar_flags_11";
		case DF_Type::knowledge_scholar_flags_12: return "knowledge_scholar_flags_12";
		case DF_Type::knowledge_scholar_flags_13: return "knowledge_scholar_flags_13";
		case DF_Type::knowledge_scholar_flags_2: return "knowledge_scholar_flags_2";
		case DF_Type::knowledge_scholar_flags_3: return "knowledge_scholar_flags_3";
		case DF_Type::knowledge_scholar_flags_4: return "knowledge_scholar_flags_4";
		case DF_Type::knowledge_scholar_flags_5: return "knowledge_scholar_flags_5";
		case DF_Type::knowledge_scholar_flags_6: return "knowledge_scholar_flags_6";
		case DF_Type::knowledge_scholar_flags_7: return "knowledge_scholar_flags_7";
		case DF_Type::knowledge_scholar_flags_8: return "knowledge_scholar_flags_8";
		case DF_Type::knowledge_scholar_flags_9: return "knowledge_scholar_flags_9";
		case DF_Type::lair_type: return "lair_type";
		case DF_Type::language_name: return "language_name";
		case DF_Type::language_name_category: return "language_name_category";
		case DF_Type::language_symbol: return "language_symbol";
		case DF_Type::language_translation: return "language_translation";
		case DF_Type::language_word: return "language_word";
		case DF_Type::language_word_flags: return "language_word_flags";
		case DF_Type::language_word_table: return "language_word_table";
		case DF_Type::large_integer: return "large_integer";
		case DF_Type::large_integer___struct0: return "large_integer___struct0";
		case DF_Type::large_integer__T_u: return "large_integer__T_u";
		case DF_Type::layer_object: return "layer_object";
		case DF_Type::layer_object_buttonst: return "layer_object_buttonst";
		case DF_Type::layer_object_listst: return "layer_object_listst";
		case DF_Type::layer_type: return "layer_type";
		case DF_Type::lever_target_type: return "lever_target_type";
		case DF_Type::loadgame_save_info: return "loadgame_save_info";
		case DF_Type::local_population: return "local_population";
		case DF_Type::local_population___union4: return "local_population___union4";
		case DF_Type::local_population__T_flags: return "local_population__T_flags";
		case DF_Type::location_scribe_jobs: return "location_scribe_jobs";
		case DF_Type::machine: return "machine";
		case DF_Type::machine__T_components: return "machine__T_components";
		case DF_Type::machine__T_flags: return "machine__T_flags";
		case DF_Type::machine_conn_modes: return "machine_conn_modes";
		case DF_Type::machine_handler: return "machine_handler";
		case DF_Type::machine_info: return "machine_info";
		case DF_Type::machine_info__T_flags: return "machine_info__T_flags";
		case DF_Type::machine_standardst: return "machine_standardst";
		case DF_Type::machine_tile_set: return "machine_tile_set";
		case DF_Type::machine_type: return "machine_type";
		case DF_Type::MacroScreenLoad: return "MacroScreenLoad";
		case DF_Type::MacroScreenSave: return "MacroScreenSave";
		case DF_Type::manager_order: return "manager_order";
		case DF_Type::manager_order__T_frequency: return "manager_order__T_frequency";
		case DF_Type::manager_order_condition_item: return "manager_order_condition_item";
		case DF_Type::manager_order_condition_item__T_compare_type: return "manager_order_condition_item__T_compare_type";
		case DF_Type::manager_order_condition_order: return "manager_order_condition_order";
		case DF_Type::manager_order_condition_order__T_condition: return "manager_order_condition_order__T_condition";
		case DF_Type::manager_order_status: return "manager_order_status";
		case DF_Type::manager_order_template: return "manager_order_template";
		case DF_Type::mandate: return "mandate";
		case DF_Type::mandate__T_mode: return "mandate__T_mode";
		case DF_Type::mandate__T_punishment: return "mandate__T_punishment";
		case DF_Type::map_block: return "map_block";
		case DF_Type::map_block_column: return "map_block_column";
		case DF_Type::map_block_column__T_unmined_glyphs: return "map_block_column__T_unmined_glyphs";
		case DF_Type::map_renderer: return "map_renderer";
		case DF_Type::map_renderer__T_anon_4: return "map_renderer__T_anon_4";
		case DF_Type::map_viewport: return "map_viewport";
		case DF_Type::masterpiece_loss_type: return "masterpiece_loss_type";
		case DF_Type::material: return "material";
		case DF_Type::material_common: return "material_common";
		case DF_Type::material_common__T_hardens_with_water: return "material_common__T_hardens_with_water";
		case DF_Type::material_common__T_heat: return "material_common__T_heat";
		case DF_Type::material_common__T_reaction_product: return "material_common__T_reaction_product";
		case DF_Type::material_common__T_strength: return "material_common__T_strength";
		case DF_Type::material_flags: return "material_flags";
		case DF_Type::material_template: return "material_template";
		case DF_Type::material_vec_ref: return "material_vec_ref";
		case DF_Type::matgloss_list: return "matgloss_list";
		case DF_Type::matgloss_list__T_unk_0: return "matgloss_list__T_unk_0";
		case DF_Type::matter_state: return "matter_state";
		case DF_Type::meeting_context: return "meeting_context";
		case DF_Type::meeting_diplomat_info: return "meeting_diplomat_info";
		case DF_Type::meeting_diplomat_info__T_flags: return "meeting_diplomat_info__T_flags";
		case DF_Type::meeting_event: return "meeting_event";
		case DF_Type::meeting_event_type: return "meeting_event_type";
		case DF_Type::meeting_topic: return "meeting_topic";
		case DF_Type::meeting_variable: return "meeting_variable";
		case DF_Type::mental_attribute_type: return "mental_attribute_type";
		case DF_Type::mental_picture: return "mental_picture";
		case DF_Type::mental_picture__T_unk: return "mental_picture__T_unk";
		case DF_Type::mental_picture_element_hfst: return "mental_picture_element_hfst";
		case DF_Type::mental_picture_element_regionst: return "mental_picture_element_regionst";
		case DF_Type::mental_picture_element_sitest: return "mental_picture_element_sitest";
		case DF_Type::mental_picture_element_type: return "mental_picture_element_type";
		case DF_Type::mental_picture_elementst: return "mental_picture_elementst";
		case DF_Type::mental_picture_property_actionst: return "mental_picture_property_actionst";
		case DF_Type::mental_picture_property_adjectivest: return "mental_picture_property_adjectivest";
		case DF_Type::mental_picture_property_color_patternst: return "mental_picture_property_color_patternst";
		case DF_Type::mental_picture_property_datest: return "mental_picture_property_datest";
		case DF_Type::mental_picture_property_emotionst: return "mental_picture_property_emotionst";
		case DF_Type::mental_picture_property_positionst: return "mental_picture_property_positionst";
		case DF_Type::mental_picture_property_shapest: return "mental_picture_property_shapest";
		case DF_Type::mental_picture_property_timest: return "mental_picture_property_timest";
		case DF_Type::mental_picture_property_toolst: return "mental_picture_property_toolst";
		case DF_Type::mental_picture_property_type: return "mental_picture_property_type";
		case DF_Type::mental_picture_propertyst: return "mental_picture_propertyst";
		case DF_Type::misc_trait_type: return "misc_trait_type";
		case DF_Type::mission: return "mission";
		case DF_Type::mission__T_details: return "mission__T_details";
		case DF_Type::mission__T_details__T_raid: return "mission__T_details__T_raid";
		case DF_Type::mission__T_details__T_raid__T_raid_flags: return "mission__T_details__T_raid__T_raid_flags";
		case DF_Type::mission__T_details__T_raid__T_raid_type: return "mission__T_details__T_raid__T_raid_type";
		case DF_Type::mission__T_details__T_recovery: return "mission__T_details__T_recovery";
		case DF_Type::mission__T_details__T_request: return "mission__T_details__T_request";
		case DF_Type::mission__T_details__T_rescue: return "mission__T_details__T_rescue";
		case DF_Type::mission__T_type: return "mission__T_type";
		case DF_Type::mission_campaign_report: return "mission_campaign_report";
		case DF_Type::mission_report: return "mission_report";
		case DF_Type::monument_type: return "monument_type";
		case DF_Type::mood_type: return "mood_type";
		case DF_Type::mountain_peak_flags: return "mountain_peak_flags";
		case DF_Type::moving_party: return "moving_party";
		case DF_Type::moving_party__T_members: return "moving_party__T_members";
		case DF_Type::musical_form: return "musical_form";
		case DF_Type::musical_form__T_flags: return "musical_form__T_flags";
		case DF_Type::musical_form_feature: return "musical_form_feature";
		case DF_Type::musical_form_instruments: return "musical_form_instruments";
		case DF_Type::musical_form_instruments__T_substitutions: return "musical_form_instruments__T_substitutions";
		case DF_Type::musical_form_interval: return "musical_form_interval";
		case DF_Type::musical_form_interval__T_flags: return "musical_form_interval__T_flags";
		case DF_Type::musical_form_melodies: return "musical_form_melodies";
		case DF_Type::musical_form_pitch_style: return "musical_form_pitch_style";
		case DF_Type::musical_form_purpose: return "musical_form_purpose";
		case DF_Type::musical_form_style: return "musical_form_style";
		case DF_Type::musical_form_sub4: return "musical_form_sub4";
		case DF_Type::musical_form_vocals: return "musical_form_vocals";
		case DF_Type::need_type: return "need_type";
		case DF_Type::nemesis_flags: return "nemesis_flags";
		case DF_Type::nemesis_offload: return "nemesis_offload";
		case DF_Type::nemesis_record: return "nemesis_record";
		case DF_Type::next_global_id: return "next_global_id";
		case DF_Type::occasion_schedule_feature: return "occasion_schedule_feature";
		case DF_Type::occasion_schedule_type: return "occasion_schedule_type";
		case DF_Type::occupation: return "occupation";
		case DF_Type::occupation_sub1: return "occupation_sub1";
		case DF_Type::occupation_type: return "occupation_type";
		case DF_Type::ocean_wave: return "ocean_wave";
		case DF_Type::organic_mat_category: return "organic_mat_category";
		case DF_Type::orientation_flags: return "orientation_flags";
		case DF_Type::pants_flags: return "pants_flags";
		case DF_Type::part_of_speech: return "part_of_speech";
		case DF_Type::party_info: return "party_info";
		case DF_Type::pattern_type: return "pattern_type";
		case DF_Type::performance_event_type: return "performance_event_type";
		case DF_Type::performance_participant_type: return "performance_participant_type";
		case DF_Type::performance_play_orderst: return "performance_play_orderst";
		case DF_Type::performance_play_orderst__T_anon_4: return "performance_play_orderst__T_anon_4";
		case DF_Type::personality_facet_type: return "personality_facet_type";
		case DF_Type::physical_attribute_type: return "physical_attribute_type";
		case DF_Type::pitch_choice_type: return "pitch_choice_type";
		case DF_Type::plant: return "plant";
		case DF_Type::plant__T_damage_flags: return "plant__T_damage_flags";
		case DF_Type::plant_flags: return "plant_flags";
		case DF_Type::plant_growth: return "plant_growth";
		case DF_Type::plant_growth__T_behavior: return "plant_growth__T_behavior";
		case DF_Type::plant_growth__T_locations: return "plant_growth__T_locations";
		case DF_Type::plant_growth_print: return "plant_growth_print";
		case DF_Type::plant_raw: return "plant_raw";
		case DF_Type::plant_raw__T_colors: return "plant_raw__T_colors";
		case DF_Type::plant_raw__T_material_defs: return "plant_raw__T_material_defs";
		case DF_Type::plant_raw__T_stockpile_growth_flags: return "plant_raw__T_stockpile_growth_flags";
		case DF_Type::plant_raw__T_tiles: return "plant_raw__T_tiles";
		case DF_Type::plant_raw_flags: return "plant_raw_flags";
		case DF_Type::plant_tree_info: return "plant_tree_info";
		case DF_Type::plant_tree_tile: return "plant_tree_tile";
		case DF_Type::plot_agreement: return "plot_agreement";
		case DF_Type::plot_role_type: return "plot_role_type";
		case DF_Type::plot_strategy_type: return "plot_strategy_type";
		case DF_Type::poetic_form: return "poetic_form";
		case DF_Type::poetic_form__T_flags: return "poetic_form__T_flags";
		case DF_Type::poetic_form_action: return "poetic_form_action";
		case DF_Type::poetic_form_additional_feature: return "poetic_form_additional_feature";
		case DF_Type::poetic_form_caesura_position: return "poetic_form_caesura_position";
		case DF_Type::poetic_form_feature: return "poetic_form_feature";
		case DF_Type::poetic_form_mood: return "poetic_form_mood";
		case DF_Type::poetic_form_part: return "poetic_form_part";
		case DF_Type::poetic_form_part__T_flags: return "poetic_form_part__T_flags";
		case DF_Type::poetic_form_pattern: return "poetic_form_pattern";
		case DF_Type::poetic_form_perspective: return "poetic_form_perspective";
		case DF_Type::poetic_form_perspective__T_type: return "poetic_form_perspective__T_type";
		case DF_Type::poetic_form_subject: return "poetic_form_subject";
		case DF_Type::poetic_form_subject_target: return "poetic_form_subject_target";
		case DF_Type::poetic_form_subject_target__T_Concept: return "poetic_form_subject_target__T_Concept";
		case DF_Type::poetic_form_subject_target__T_Histfig: return "poetic_form_subject_target__T_Histfig";
		case DF_Type::popup_message: return "popup_message";
		case DF_Type::power_info: return "power_info";
		case DF_Type::pressure_plate_info: return "pressure_plate_info";
		case DF_Type::pressure_plate_info__T_flags: return "pressure_plate_info__T_flags";
		case DF_Type::profession: return "profession";
		case DF_Type::proj_itemst: return "proj_itemst";
		case DF_Type::proj_list_link: return "proj_list_link";
		case DF_Type::proj_magicst: return "proj_magicst";
		case DF_Type::proj_unitst: return "proj_unitst";
		case DF_Type::projectile: return "projectile";
		case DF_Type::projectile_flags: return "projectile_flags";
		case DF_Type::projectile_type: return "projectile_type";
		case DF_Type::property_ownership: return "property_ownership";
		case DF_Type::punishment: return "punishment";
		case DF_Type::reaction: return "reaction";
		case DF_Type::reaction__T_building: return "reaction__T_building";
		case DF_Type::reaction_category: return "reaction_category";
		case DF_Type::reaction_description: return "reaction_description";
		case DF_Type::reaction_flags: return "reaction_flags";
		case DF_Type::reaction_product: return "reaction_product";
		case DF_Type::reaction_product_improvement_flags: return "reaction_product_improvement_flags";
		case DF_Type::reaction_product_item_flags: return "reaction_product_item_flags";
		case DF_Type::reaction_product_item_improvementst: return "reaction_product_item_improvementst";
		case DF_Type::reaction_product_item_improvementst__T_get_material: return "reaction_product_item_improvementst__T_get_material";
		case DF_Type::reaction_product_itemst: return "reaction_product_itemst";
		case DF_Type::reaction_product_itemst__T_get_material: return "reaction_product_itemst__T_get_material";
		case DF_Type::reaction_product_type: return "reaction_product_type";
		case DF_Type::reaction_reagent: return "reaction_reagent";
		case DF_Type::reaction_reagent_flags: return "reaction_reagent_flags";
		case DF_Type::reaction_reagent_itemst: return "reaction_reagent_itemst";
		case DF_Type::reaction_reagent_type: return "reaction_reagent_type";
		case DF_Type::region_block_event_sphere_fieldst: return "region_block_event_sphere_fieldst";
		case DF_Type::region_block_event_type: return "region_block_event_type";
		case DF_Type::region_block_eventst: return "region_block_eventst";
		case DF_Type::region_map_entry: return "region_map_entry";
		case DF_Type::region_map_entry__T_clouds: return "region_map_entry__T_clouds";
		case DF_Type::region_map_entry__T_wind: return "region_map_entry__T_wind";
		case DF_Type::region_map_entry_flags: return "region_map_entry_flags";
		case DF_Type::region_weather: return "region_weather";
		case DF_Type::relationship_event: return "relationship_event";
		case DF_Type::relationship_event_supplement: return "relationship_event_supplement";
		case DF_Type::renderer: return "renderer";
		case DF_Type::report: return "report";
		case DF_Type::report__T_flags: return "report__T_flags";
		case DF_Type::reputation_type: return "reputation_type";
		case DF_Type::resource_allotment_data: return "resource_allotment_data";
		case DF_Type::resource_allotment_data__T_unk_654: return "resource_allotment_data__T_unk_654";
		case DF_Type::resource_allotment_specifier: return "resource_allotment_specifier";
		case DF_Type::resource_allotment_specifier_ammost: return "resource_allotment_specifier_ammost";
		case DF_Type::resource_allotment_specifier_anvilst: return "resource_allotment_specifier_anvilst";
		case DF_Type::resource_allotment_specifier_armor_bodyst: return "resource_allotment_specifier_armor_bodyst";
		case DF_Type::resource_allotment_specifier_armor_bootsst: return "resource_allotment_specifier_armor_bootsst";
		case DF_Type::resource_allotment_specifier_armor_glovesst: return "resource_allotment_specifier_armor_glovesst";
		case DF_Type::resource_allotment_specifier_armor_helmst: return "resource_allotment_specifier_armor_helmst";
		case DF_Type::resource_allotment_specifier_armor_pantsst: return "resource_allotment_specifier_armor_pantsst";
		case DF_Type::resource_allotment_specifier_backpackst: return "resource_allotment_specifier_backpackst";
		case DF_Type::resource_allotment_specifier_bagst: return "resource_allotment_specifier_bagst";
		case DF_Type::resource_allotment_specifier_bedst: return "resource_allotment_specifier_bedst";
		case DF_Type::resource_allotment_specifier_bonest: return "resource_allotment_specifier_bonest";
		case DF_Type::resource_allotment_specifier_boxst: return "resource_allotment_specifier_boxst";
		case DF_Type::resource_allotment_specifier_cabinetst: return "resource_allotment_specifier_cabinetst";
		case DF_Type::resource_allotment_specifier_chairst: return "resource_allotment_specifier_chairst";
		case DF_Type::resource_allotment_specifier_cheesest: return "resource_allotment_specifier_cheesest";
		case DF_Type::resource_allotment_specifier_clothing_bodyst: return "resource_allotment_specifier_clothing_bodyst";
		case DF_Type::resource_allotment_specifier_clothing_bootsst: return "resource_allotment_specifier_clothing_bootsst";
		case DF_Type::resource_allotment_specifier_clothing_glovesst: return "resource_allotment_specifier_clothing_glovesst";
		case DF_Type::resource_allotment_specifier_clothing_helmst: return "resource_allotment_specifier_clothing_helmst";
		case DF_Type::resource_allotment_specifier_clothing_pantsst: return "resource_allotment_specifier_clothing_pantsst";
		case DF_Type::resource_allotment_specifier_clothst: return "resource_allotment_specifier_clothst";
		case DF_Type::resource_allotment_specifier_craftsst: return "resource_allotment_specifier_craftsst";
		case DF_Type::resource_allotment_specifier_cropst: return "resource_allotment_specifier_cropst";
		case DF_Type::resource_allotment_specifier_extractst: return "resource_allotment_specifier_extractst";
		case DF_Type::resource_allotment_specifier_flaskst: return "resource_allotment_specifier_flaskst";
		case DF_Type::resource_allotment_specifier_gemsst: return "resource_allotment_specifier_gemsst";
		case DF_Type::resource_allotment_specifier_hornst: return "resource_allotment_specifier_hornst";
		case DF_Type::resource_allotment_specifier_leatherst: return "resource_allotment_specifier_leatherst";
		case DF_Type::resource_allotment_specifier_meatst: return "resource_allotment_specifier_meatst";
		case DF_Type::resource_allotment_specifier_metalst: return "resource_allotment_specifier_metalst";
		case DF_Type::resource_allotment_specifier_pearlst: return "resource_allotment_specifier_pearlst";
		case DF_Type::resource_allotment_specifier_powderst: return "resource_allotment_specifier_powderst";
		case DF_Type::resource_allotment_specifier_quiverst: return "resource_allotment_specifier_quiverst";
		case DF_Type::resource_allotment_specifier_shellst: return "resource_allotment_specifier_shellst";
		case DF_Type::resource_allotment_specifier_skinst: return "resource_allotment_specifier_skinst";
		case DF_Type::resource_allotment_specifier_soapst: return "resource_allotment_specifier_soapst";
		case DF_Type::resource_allotment_specifier_stonest: return "resource_allotment_specifier_stonest";
		case DF_Type::resource_allotment_specifier_tablest: return "resource_allotment_specifier_tablest";
		case DF_Type::resource_allotment_specifier_tallowst: return "resource_allotment_specifier_tallowst";
		case DF_Type::resource_allotment_specifier_threadst: return "resource_allotment_specifier_threadst";
		case DF_Type::resource_allotment_specifier_toothst: return "resource_allotment_specifier_toothst";
		case DF_Type::resource_allotment_specifier_type: return "resource_allotment_specifier_type";
		case DF_Type::resource_allotment_specifier_weapon_meleest: return "resource_allotment_specifier_weapon_meleest";
		case DF_Type::resource_allotment_specifier_weapon_rangedst: return "resource_allotment_specifier_weapon_rangedst";
		case DF_Type::resource_allotment_specifier_woodst: return "resource_allotment_specifier_woodst";
		case DF_Type::rhythm: return "rhythm";
		case DF_Type::rhythm_sub1: return "rhythm_sub1";
		case DF_Type::rhythm_sub1__T_anon_1: return "rhythm_sub1__T_anon_1";
		case DF_Type::rhythm_sub2: return "rhythm_sub2";
		case DF_Type::room_rent_info: return "room_rent_info";
		case DF_Type::room_rent_info__T_flags: return "room_rent_info__T_flags";
		case DF_Type::route_stockpile_link: return "route_stockpile_link";
		case DF_Type::route_stockpile_link__T_mode: return "route_stockpile_link__T_mode";
		case DF_Type::scale: return "scale";
		case DF_Type::scale__T_unk1: return "scale__T_unk1";
		case DF_Type::scale_sub1: return "scale_sub1";
		case DF_Type::scale_sub2: return "scale_sub2";
		case DF_Type::schedule_info: return "schedule_info";
		case DF_Type::schedule_slot: return "schedule_slot";
		case DF_Type::screw_pump_direction: return "screw_pump_direction";
		case DF_Type::scribejob: return "scribejob";
		case DF_Type::script_step_conditionalst: return "script_step_conditionalst";
		case DF_Type::script_step_conditionalst__T_condition: return "script_step_conditionalst__T_condition";
		case DF_Type::script_step_constructtopiclistst: return "script_step_constructtopiclistst";
		case DF_Type::script_step_dipeventst: return "script_step_dipeventst";
		case DF_Type::script_step_diphistoryst: return "script_step_diphistoryst";
		case DF_Type::script_step_discussst: return "script_step_discussst";
		case DF_Type::script_step_eventst: return "script_step_eventst";
		case DF_Type::script_step_invasionst: return "script_step_invasionst";
		case DF_Type::script_step_setvarst: return "script_step_setvarst";
		case DF_Type::script_step_simpleactionst: return "script_step_simpleactionst";
		case DF_Type::script_step_textviewerst: return "script_step_textviewerst";
		case DF_Type::script_step_topicdiscussionst: return "script_step_topicdiscussionst";
		case DF_Type::script_stepst: return "script_stepst";
		case DF_Type::script_var_longst: return "script_var_longst";
		case DF_Type::script_var_unitst: return "script_var_unitst";
		case DF_Type::script_varst: return "script_varst";
		case DF_Type::setup_character_info: return "setup_character_info";
		case DF_Type::setup_character_info__T_available_embark_items: return "setup_character_info__T_available_embark_items";
		case DF_Type::setup_character_info__T_page: return "setup_character_info__T_page";
		case DF_Type::setup_character_info__T_sel_trait_column: return "setup_character_info__T_sel_trait_column";
		case DF_Type::setup_character_info__T_status: return "setup_character_info__T_status";
		case DF_Type::shoes_flags: return "shoes_flags";
		case DF_Type::shop_type: return "shop_type";
		case DF_Type::siegeengine_type: return "siegeengine_type";
		case DF_Type::site_building_item: return "site_building_item";
		case DF_Type::site_dispute_type: return "site_dispute_type";
		case DF_Type::site_realization_building: return "site_realization_building";
		case DF_Type::site_realization_building__T_unk_4c: return "site_realization_building__T_unk_4c";
		case DF_Type::site_realization_building_info_castle_courtyardst: return "site_realization_building_info_castle_courtyardst";
		case DF_Type::site_realization_building_info_castle_towerst: return "site_realization_building_info_castle_towerst";
		case DF_Type::site_realization_building_info_castle_wallst: return "site_realization_building_info_castle_wallst";
		case DF_Type::site_realization_building_info_hillock_housest: return "site_realization_building_info_hillock_housest";
		case DF_Type::site_realization_building_info_market_squarest: return "site_realization_building_info_market_squarest";
		case DF_Type::site_realization_building_info_shop_housest: return "site_realization_building_info_shop_housest";
		case DF_Type::site_realization_building_info_tree_housest: return "site_realization_building_info_tree_housest";
		case DF_Type::site_realization_building_info_trenchesst: return "site_realization_building_info_trenchesst";
		case DF_Type::site_realization_building_info_trenchesst__T_spokes: return "site_realization_building_info_trenchesst__T_spokes";
		case DF_Type::site_realization_building_infost: return "site_realization_building_infost";
		case DF_Type::site_realization_building_type: return "site_realization_building_type";
		case DF_Type::site_realization_crossroads: return "site_realization_crossroads";
		case DF_Type::site_reputation_info: return "site_reputation_info";
		case DF_Type::site_reputation_report: return "site_reputation_report";
		case DF_Type::site_shop_type: return "site_shop_type";
		case DF_Type::site_type: return "site_type";
		case DF_Type::skill_rating: return "skill_rating";
		case DF_Type::slab_engraving_type: return "slab_engraving_type";
		case DF_Type::sound_production_type: return "sound_production_type";
		case DF_Type::spatter: return "spatter";
		case DF_Type::spatter__T_flags: return "spatter__T_flags";
		case DF_Type::spatter_common: return "spatter_common";
		case DF_Type::spatter_common__T_base_flags: return "spatter_common__T_base_flags";
		case DF_Type::special_mat_table: return "special_mat_table";
		case DF_Type::specific_ref: return "specific_ref";
		case DF_Type::specific_ref__T_data: return "specific_ref__T_data";
		case DF_Type::specific_ref__T_data__T_wrestle: return "specific_ref__T_data__T_wrestle";
		case DF_Type::specific_ref_type: return "specific_ref_type";
		case DF_Type::sphere_type: return "sphere_type";
		case DF_Type::spoils_report: return "spoils_report";
		case DF_Type::squad: return "squad";
		case DF_Type::squad__T_rooms: return "squad__T_rooms";
		case DF_Type::squad_ammo_spec: return "squad_ammo_spec";
		case DF_Type::squad_ammo_spec__T_flags: return "squad_ammo_spec__T_flags";
		case DF_Type::squad_event_type: return "squad_event_type";
		case DF_Type::squad_order: return "squad_order";
		case DF_Type::squad_order_cannot_reason: return "squad_order_cannot_reason";
		case DF_Type::squad_order_cause_trouble_for_entityst: return "squad_order_cause_trouble_for_entityst";
		case DF_Type::squad_order_defend_burrowsst: return "squad_order_defend_burrowsst";
		case DF_Type::squad_order_drive_armies_from_sitest: return "squad_order_drive_armies_from_sitest";
		case DF_Type::squad_order_drive_entity_off_sitest: return "squad_order_drive_entity_off_sitest";
		case DF_Type::squad_order_kill_hfst: return "squad_order_kill_hfst";
		case DF_Type::squad_order_kill_listst: return "squad_order_kill_listst";
		case DF_Type::squad_order_movest: return "squad_order_movest";
		case DF_Type::squad_order_patrol_routest: return "squad_order_patrol_routest";
		case DF_Type::squad_order_raid_sitest: return "squad_order_raid_sitest";
		case DF_Type::squad_order_rescue_hfst: return "squad_order_rescue_hfst";
		case DF_Type::squad_order_retrieve_artifactst: return "squad_order_retrieve_artifactst";
		case DF_Type::squad_order_trainst: return "squad_order_trainst";
		case DF_Type::squad_order_type: return "squad_order_type";
		case DF_Type::squad_position: return "squad_position";
		case DF_Type::squad_schedule_entry: return "squad_schedule_entry";
		case DF_Type::squad_schedule_order: return "squad_schedule_order";
		case DF_Type::squad_uniform_spec: return "squad_uniform_spec";
		case DF_Type::squad_use_flags: return "squad_use_flags";
		case DF_Type::stockpile_category: return "stockpile_category";
		case DF_Type::stockpile_group_set: return "stockpile_group_set";
		case DF_Type::stockpile_links: return "stockpile_links";
		case DF_Type::stockpile_list: return "stockpile_list";
		case DF_Type::stockpile_settings: return "stockpile_settings";
		case DF_Type::stockpile_settings__T_ammo: return "stockpile_settings__T_ammo";
		case DF_Type::stockpile_settings__T_animals: return "stockpile_settings__T_animals";
		case DF_Type::stockpile_settings__T_armor: return "stockpile_settings__T_armor";
		case DF_Type::stockpile_settings__T_bars_blocks: return "stockpile_settings__T_bars_blocks";
		case DF_Type::stockpile_settings__T_cloth: return "stockpile_settings__T_cloth";
		case DF_Type::stockpile_settings__T_coins: return "stockpile_settings__T_coins";
		case DF_Type::stockpile_settings__T_finished_goods: return "stockpile_settings__T_finished_goods";
		case DF_Type::stockpile_settings__T_food: return "stockpile_settings__T_food";
		case DF_Type::stockpile_settings__T_furniture: return "stockpile_settings__T_furniture";
		case DF_Type::stockpile_settings__T_gems: return "stockpile_settings__T_gems";
		case DF_Type::stockpile_settings__T_leather: return "stockpile_settings__T_leather";
		case DF_Type::stockpile_settings__T_ore: return "stockpile_settings__T_ore";
		case DF_Type::stockpile_settings__T_refuse: return "stockpile_settings__T_refuse";
		case DF_Type::stockpile_settings__T_sheet: return "stockpile_settings__T_sheet";
		case DF_Type::stockpile_settings__T_stone: return "stockpile_settings__T_stone";
		case DF_Type::stockpile_settings__T_weapons: return "stockpile_settings__T_weapons";
		case DF_Type::stockpile_settings__T_wood: return "stockpile_settings__T_wood";
		case DF_Type::stop_depart_condition: return "stop_depart_condition";
		case DF_Type::stop_depart_condition__T_direction: return "stop_depart_condition__T_direction";
		case DF_Type::stop_depart_condition__T_flags: return "stop_depart_condition__T_flags";
		case DF_Type::stop_depart_condition__T_mode: return "stop_depart_condition__T_mode";
		case DF_Type::strain_type: return "strain_type";
		case DF_Type::stratus_type: return "stratus_type";
		case DF_Type::syndrome: return "syndrome";
		case DF_Type::syndrome_flags: return "syndrome_flags";
		case DF_Type::T_cursor: return "T_cursor";
		case DF_Type::T_selection_rect: return "T_selection_rect";
		case DF_Type::tactical_situation: return "tactical_situation";
		case DF_Type::talk_choice: return "talk_choice";
		case DF_Type::talk_choice__T_unk: return "talk_choice__T_unk";
		case DF_Type::talk_choice_type: return "talk_choice_type";
		case DF_Type::temperaturest: return "temperaturest";
		case DF_Type::temple_deity_data: return "temple_deity_data";
		case DF_Type::temple_deity_type: return "temple_deity_type";
		case DF_Type::text_info_element_longst: return "text_info_element_longst";
		case DF_Type::text_info_element_stringst: return "text_info_element_stringst";
		case DF_Type::text_info_elementst: return "text_info_elementst";
		case DF_Type::texture_handler: return "texture_handler";
		case DF_Type::tile_bitmask: return "tile_bitmask";
		case DF_Type::tile_building_occ: return "tile_building_occ";
		case DF_Type::tile_designation: return "tile_designation";
		case DF_Type::tile_dig_designation: return "tile_dig_designation";
		case DF_Type::tile_liquid: return "tile_liquid";
		case DF_Type::tile_liquid_flow: return "tile_liquid_flow";
		case DF_Type::tile_liquid_flow_dir: return "tile_liquid_flow_dir";
		case DF_Type::tile_occupancy: return "tile_occupancy";
		case DF_Type::tile_page: return "tile_page";
		case DF_Type::tile_traffic: return "tile_traffic";
		case DF_Type::tiletype: return "tiletype";
		case DF_Type::tiletype_material: return "tiletype_material";
		case DF_Type::tiletype_shape: return "tiletype_shape";
		case DF_Type::tiletype_shape_basic: return "tiletype_shape_basic";
		case DF_Type::tiletype_special: return "tiletype_special";
		case DF_Type::tiletype_variant: return "tiletype_variant";
		case DF_Type::timbre_type: return "timbre_type";
		case DF_Type::timed_event: return "timed_event";
		case DF_Type::timed_event_type: return "timed_event_type";
		case DF_Type::tissue: return "tissue";
		case DF_Type::tissue_flags: return "tissue_flags";
		case DF_Type::tissue_style_raw: return "tissue_style_raw";
		case DF_Type::tissue_style_type: return "tissue_style_type";
		case DF_Type::tissue_template: return "tissue_template";
		case DF_Type::tool_flags: return "tool_flags";
		case DF_Type::tool_uses: return "tool_uses";
		case DF_Type::tower_shape: return "tower_shape";
		case DF_Type::toy_flags: return "toy_flags";
		case DF_Type::training_assignment: return "training_assignment";
		case DF_Type::training_assignment__T_flags: return "training_assignment__T_flags";
		case DF_Type::training_knowledge_level: return "training_knowledge_level";
		case DF_Type::trap_type: return "trap_type";
		case DF_Type::trapcomp_flags: return "trapcomp_flags";
		case DF_Type::tree_house_type: return "tree_house_type";
		case DF_Type::tuning_type: return "tuning_type";
		case DF_Type::ui: return "ui";
		case DF_Type::ui__T_alerts: return "ui__T_alerts";
		case DF_Type::ui__T_alerts__T_list: return "ui__T_alerts__T_list";
		case DF_Type::ui__T_becoming_capital: return "ui__T_becoming_capital";
		case DF_Type::ui__T_burrows: return "ui__T_burrows";
		case DF_Type::ui__T_economy_prices: return "ui__T_economy_prices";
		case DF_Type::ui__T_economy_prices__T_price_adjustment: return "ui__T_economy_prices__T_price_adjustment";
		case DF_Type::ui__T_economy_prices__T_price_setter: return "ui__T_economy_prices__T_price_setter";
		case DF_Type::ui__T_equipment: return "ui__T_equipment";
		case DF_Type::ui__T_equipment__T_update: return "ui__T_equipment__T_update";
		case DF_Type::ui__T_hauling: return "ui__T_hauling";
		case DF_Type::ui__T_invasions: return "ui__T_invasions";
		case DF_Type::ui__T_kitchen: return "ui__T_kitchen";
		case DF_Type::ui__T_main: return "ui__T_main";
		case DF_Type::ui__T_main__T_dead_citizens: return "ui__T_main__T_dead_citizens";
		case DF_Type::ui__T_map_edge: return "ui__T_map_edge";
		case DF_Type::ui__T_squads: return "ui__T_squads";
		case DF_Type::ui__T_stockpile: return "ui__T_stockpile";
		case DF_Type::ui__T_tax_collection: return "ui__T_tax_collection";
		case DF_Type::ui__T_unk23c8_flags: return "ui__T_unk23c8_flags";
		case DF_Type::ui__T_unk2a8c: return "ui__T_unk2a8c";
		case DF_Type::ui__T_waypoints: return "ui__T_waypoints";
		case DF_Type::ui__T_waypoints__T_points: return "ui__T_waypoints__T_points";
		case DF_Type::ui__T_waypoints__T_routes: return "ui__T_waypoints__T_routes";
		case DF_Type::ui_advmode: return "ui_advmode";
		case DF_Type::ui_advmode__T_assume_identity: return "ui_advmode__T_assume_identity";
		case DF_Type::ui_advmode__T_companions: return "ui_advmode__T_companions";
		case DF_Type::ui_advmode__T_conversation: return "ui_advmode__T_conversation";
		case DF_Type::ui_advmode__T_conversation__T_choices: return "ui_advmode__T_conversation__T_choices";
		case DF_Type::ui_advmode__T_conversation__T_targets: return "ui_advmode__T_conversation__T_targets";
		case DF_Type::ui_advmode__T_conversation__T_targets__T_type: return "ui_advmode__T_conversation__T_targets__T_type";
		case DF_Type::ui_advmode__T_interactions: return "ui_advmode__T_interactions";
		case DF_Type::ui_advmode__T_show_menu: return "ui_advmode__T_show_menu";
		case DF_Type::ui_advmode__T_travel_right_map: return "ui_advmode__T_travel_right_map";
		case DF_Type::ui_advmode__T_unk_3124: return "ui_advmode__T_unk_3124";
		case DF_Type::ui_advmode__T_unk_3170: return "ui_advmode__T_unk_3170";
		case DF_Type::ui_advmode__T_unk_3170__T_unk_2: return "ui_advmode__T_unk_3170__T_unk_2";
		case DF_Type::ui_advmode__T_unk_v40_1: return "ui_advmode__T_unk_v40_1";
		case DF_Type::ui_advmode__T_unk_v40_2: return "ui_advmode__T_unk_v40_2";
		case DF_Type::ui_advmode__T_unk_v40_3: return "ui_advmode__T_unk_v40_3";
		case DF_Type::ui_advmode__T_unk_v40_4: return "ui_advmode__T_unk_v40_4";
		case DF_Type::ui_advmode__T_unk_v40_4__T_unk_v40_4a: return "ui_advmode__T_unk_v40_4__T_unk_v40_4a";
		case DF_Type::ui_advmode__T_unk_v40_5: return "ui_advmode__T_unk_v40_5";
		case DF_Type::ui_advmode__T_unk_v42_1: return "ui_advmode__T_unk_v42_1";
		case DF_Type::ui_advmode_menu: return "ui_advmode_menu";
		case DF_Type::ui_build_item_req: return "ui_build_item_req";
		case DF_Type::ui_build_selector: return "ui_build_selector";
		case DF_Type::ui_hotkey: return "ui_hotkey";
		case DF_Type::ui_hotkey___union2: return "ui_hotkey___union2";
		case DF_Type::ui_hotkey__T_cmd: return "ui_hotkey__T_cmd";
		case DF_Type::ui_look_list: return "ui_look_list";
		case DF_Type::ui_look_list__T_items: return "ui_look_list__T_items";
		case DF_Type::ui_look_list__T_items__T_data: return "ui_look_list__T_items__T_data";
		case DF_Type::ui_look_list__T_items__T_data__T_Magma: return "ui_look_list__T_items__T_data__T_Magma";
		case DF_Type::ui_look_list__T_items__T_data__T_Spatter: return "ui_look_list__T_items__T_data__T_Spatter";
		case DF_Type::ui_look_list__T_items__T_data__T_Water: return "ui_look_list__T_items__T_data__T_Water";
		case DF_Type::ui_look_list__T_items__T_type: return "ui_look_list__T_items__T_type";
		case DF_Type::ui_sidebar_menus: return "ui_sidebar_menus";
		case DF_Type::ui_sidebar_menus__T_barracks: return "ui_sidebar_menus__T_barracks";
		case DF_Type::ui_sidebar_menus__T_building: return "ui_sidebar_menus__T_building";
		case DF_Type::ui_sidebar_menus__T_command_line: return "ui_sidebar_menus__T_command_line";
		case DF_Type::ui_sidebar_menus__T_designation: return "ui_sidebar_menus__T_designation";
		case DF_Type::ui_sidebar_menus__T_designation__T_mine_mode: return "ui_sidebar_menus__T_designation__T_mine_mode";
		case DF_Type::ui_sidebar_menus__T_hospital: return "ui_sidebar_menus__T_hospital";
		case DF_Type::ui_sidebar_menus__T_job_details: return "ui_sidebar_menus__T_job_details";
		case DF_Type::ui_sidebar_menus__T_location: return "ui_sidebar_menus__T_location";
		case DF_Type::ui_sidebar_menus__T_minimap: return "ui_sidebar_menus__T_minimap";
		case DF_Type::ui_sidebar_menus__T_unit: return "ui_sidebar_menus__T_unit";
		case DF_Type::ui_sidebar_menus__T_unit__T_expel_error: return "ui_sidebar_menus__T_unit__T_expel_error";
		case DF_Type::ui_sidebar_menus__T_unit_cursor: return "ui_sidebar_menus__T_unit_cursor";
		case DF_Type::ui_sidebar_menus__T_unit_skills: return "ui_sidebar_menus__T_unit_skills";
		case DF_Type::ui_sidebar_menus__T_workshop_job: return "ui_sidebar_menus__T_workshop_job";
		case DF_Type::ui_sidebar_menus__T_zone: return "ui_sidebar_menus__T_zone";
		case DF_Type::ui_sidebar_menus__T_zone__T_mode: return "ui_sidebar_menus__T_zone__T_mode";
		case DF_Type::ui_sidebar_mode: return "ui_sidebar_mode";
		case DF_Type::ui_unit_view_mode: return "ui_unit_view_mode";
		case DF_Type::ui_unit_view_mode__T_value: return "ui_unit_view_mode__T_value";
		case DF_Type::undead_flags: return "undead_flags";
		case DF_Type::uniform_category: return "uniform_category";
		case DF_Type::uniform_flags: return "uniform_flags";
		case DF_Type::uniform_indiv_choice: return "uniform_indiv_choice";
		case DF_Type::unit: return "unit";
		case DF_Type::unit__T_animal: return "unit__T_animal";
		case DF_Type::unit__T_appearance: return "unit__T_appearance";
		case DF_Type::unit__T_body: return "unit__T_body";
		case DF_Type::unit__T_counters: return "unit__T_counters";
		case DF_Type::unit__T_counters2: return "unit__T_counters2";
		case DF_Type::unit__T_counters__T_soldier_mood: return "unit__T_counters__T_soldier_mood";
		case DF_Type::unit__T_curse: return "unit__T_curse";
		case DF_Type::unit__T_enemy: return "unit__T_enemy";
		case DF_Type::unit__T_enemy__T_undead: return "unit__T_enemy__T_undead";
		case DF_Type::unit__T_enemy__T_unk_448: return "unit__T_enemy__T_unk_448";
		case DF_Type::unit__T_enemy__T_unk_448__T_unk: return "unit__T_enemy__T_unk_448__T_unk";
		case DF_Type::unit__T_enemy__T_unk_44c: return "unit__T_enemy__T_unk_44c";
		case DF_Type::unit__T_enemy__T_unk_v40_sub3: return "unit__T_enemy__T_unk_v40_sub3";
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_2: return "unit__T_enemy__T_unk_v40_sub3__T_unk_2";
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_6: return "unit__T_enemy__T_unk_v40_sub3__T_unk_6";
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7: return "unit__T_enemy__T_unk_v40_sub3__T_unk_7";
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1: return "unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1";
		case DF_Type::unit__T_enemy__T_witness_reports: return "unit__T_enemy__T_witness_reports";
		case DF_Type::unit__T_job: return "unit__T_job";
		case DF_Type::unit__T_meeting: return "unit__T_meeting";
		case DF_Type::unit__T_meeting__T_state: return "unit__T_meeting__T_state";
		case DF_Type::unit__T_military: return "unit__T_military";
		case DF_Type::unit__T_military__T_pickup_flags: return "unit__T_military__T_pickup_flags";
		case DF_Type::unit__T_opponent: return "unit__T_opponent";
		case DF_Type::unit__T_path: return "unit__T_path";
		case DF_Type::unit__T_reports: return "unit__T_reports";
		case DF_Type::unit__T_status: return "unit__T_status";
		case DF_Type::unit__T_status2: return "unit__T_status2";
		case DF_Type::unit__T_status__T_eat_history: return "unit__T_status__T_eat_history";
		case DF_Type::unit__T_status__T_eat_history__T_drink: return "unit__T_status__T_eat_history__T_drink";
		case DF_Type::unit__T_status__T_eat_history__T_food: return "unit__T_status__T_eat_history__T_food";
		case DF_Type::unit__T_syndromes: return "unit__T_syndromes";
		case DF_Type::unit__T_unknown7: return "unit__T_unknown7";
		case DF_Type::unit_action: return "unit_action";
		case DF_Type::unit_action__T_data: return "unit_action__T_data";
		case DF_Type::unit_action_data_attack: return "unit_action_data_attack";
		case DF_Type::unit_action_data_attack__T_flags: return "unit_action_data_attack__T_flags";
		case DF_Type::unit_action_data_attack__T_unk_4: return "unit_action_data_attack__T_unk_4";
		case DF_Type::unit_action_data_attack__T_unk_4__T_wrestle_type: return "unit_action_data_attack__T_unk_4__T_wrestle_type";
		case DF_Type::unit_action_data_block: return "unit_action_data_block";
		case DF_Type::unit_action_data_climb: return "unit_action_data_climb";
		case DF_Type::unit_action_data_dodge: return "unit_action_data_dodge";
		case DF_Type::unit_action_data_hold_item: return "unit_action_data_hold_item";
		case DF_Type::unit_action_data_hold_terrain: return "unit_action_data_hold_terrain";
		case DF_Type::unit_action_data_job: return "unit_action_data_job";
		case DF_Type::unit_action_data_job2: return "unit_action_data_job2";
		case DF_Type::unit_action_data_jump: return "unit_action_data_jump";
		case DF_Type::unit_action_data_lie_down: return "unit_action_data_lie_down";
		case DF_Type::unit_action_data_move: return "unit_action_data_move";
		case DF_Type::unit_action_data_move__T_flags: return "unit_action_data_move__T_flags";
		case DF_Type::unit_action_data_parry: return "unit_action_data_parry";
		case DF_Type::unit_action_data_push_object: return "unit_action_data_push_object";
		case DF_Type::unit_action_data_recover: return "unit_action_data_recover";
		case DF_Type::unit_action_data_release_item: return "unit_action_data_release_item";
		case DF_Type::unit_action_data_release_terrain: return "unit_action_data_release_terrain";
		case DF_Type::unit_action_data_stand_up: return "unit_action_data_stand_up";
		case DF_Type::unit_action_data_suck_blood: return "unit_action_data_suck_blood";
		case DF_Type::unit_action_data_talk: return "unit_action_data_talk";
		case DF_Type::unit_action_data_unsteady: return "unit_action_data_unsteady";
		case DF_Type::unit_action_type: return "unit_action_type";
		case DF_Type::unit_appearance: return "unit_appearance";
		case DF_Type::unit_attribute: return "unit_attribute";
		case DF_Type::unit_bp_health_flags: return "unit_bp_health_flags";
		case DF_Type::unit_chunk: return "unit_chunk";
		case DF_Type::unit_chunk__T_units: return "unit_chunk__T_units";
		case DF_Type::unit_coin_debt: return "unit_coin_debt";
		case DF_Type::unit_complaint: return "unit_complaint";
		case DF_Type::unit_complaint__T_type: return "unit_complaint__T_type";
		case DF_Type::unit_dance_skill: return "unit_dance_skill";
		case DF_Type::unit_demand: return "unit_demand";
		case DF_Type::unit_demand__T_place: return "unit_demand__T_place";
		case DF_Type::unit_emotion_memory: return "unit_emotion_memory";
		case DF_Type::unit_flags1: return "unit_flags1";
		case DF_Type::unit_flags2: return "unit_flags2";
		case DF_Type::unit_flags3: return "unit_flags3";
		case DF_Type::unit_flags4: return "unit_flags4";
		case DF_Type::unit_genes: return "unit_genes";
		case DF_Type::unit_ghost_info: return "unit_ghost_info";
		case DF_Type::unit_ghost_info__T_flags: return "unit_ghost_info__T_flags";
		case DF_Type::unit_ghost_info__T_target: return "unit_ghost_info__T_target";
		case DF_Type::unit_health_flags: return "unit_health_flags";
		case DF_Type::unit_health_info: return "unit_health_info";
		case DF_Type::unit_health_info__T_op_history: return "unit_health_info__T_op_history";
		case DF_Type::unit_health_info__T_op_history__T_info: return "unit_health_info__T_op_history__T_info";
		case DF_Type::unit_health_info__T_op_history__T_info__T_bandage: return "unit_health_info__T_op_history__T_info__T_bandage";
		case DF_Type::unit_health_info__T_op_history__T_info__T_crutch: return "unit_health_info__T_op_history__T_info__T_crutch";
		case DF_Type::unit_instrument_skill: return "unit_instrument_skill";
		case DF_Type::unit_inventory_item: return "unit_inventory_item";
		case DF_Type::unit_inventory_item__T_mode: return "unit_inventory_item__T_mode";
		case DF_Type::unit_item_use: return "unit_item_use";
		case DF_Type::unit_item_wrestle: return "unit_item_wrestle";
		case DF_Type::unit_labor: return "unit_labor";
		case DF_Type::unit_labor_category: return "unit_labor_category";
		case DF_Type::unit_misc_trait: return "unit_misc_trait";
		case DF_Type::unit_musical_skill: return "unit_musical_skill";
		case DF_Type::unit_path_goal: return "unit_path_goal";
		case DF_Type::unit_personality: return "unit_personality";
		case DF_Type::unit_personality__T_dreams: return "unit_personality__T_dreams";
		case DF_Type::unit_personality__T_emotions: return "unit_personality__T_emotions";
		case DF_Type::unit_personality__T_emotions__T_flags: return "unit_personality__T_emotions__T_flags";
		case DF_Type::unit_personality__T_flags: return "unit_personality__T_flags";
		case DF_Type::unit_personality__T_memories: return "unit_personality__T_memories";
		case DF_Type::unit_personality__T_memories__T_reflected_on: return "unit_personality__T_memories__T_reflected_on";
		case DF_Type::unit_personality__T_needs: return "unit_personality__T_needs";
		case DF_Type::unit_personality__T_unk5: return "unit_personality__T_unk5";
		case DF_Type::unit_personality__T_unk_v40_2: return "unit_personality__T_unk_v40_2";
		case DF_Type::unit_personality__T_unk_v40_6: return "unit_personality__T_unk_v40_6";
		case DF_Type::unit_personality__T_values: return "unit_personality__T_values";
		case DF_Type::unit_poetic_skill: return "unit_poetic_skill";
		case DF_Type::unit_preference: return "unit_preference";
		case DF_Type::unit_preference___union3: return "unit_preference___union3";
		case DF_Type::unit_preference__T_type: return "unit_preference__T_type";
		case DF_Type::unit_relationship_type: return "unit_relationship_type";
		case DF_Type::unit_report_type: return "unit_report_type";
		case DF_Type::unit_request: return "unit_request";
		case DF_Type::unit_request__T_type: return "unit_request__T_type";
		case DF_Type::unit_skill: return "unit_skill";
		case DF_Type::unit_soul: return "unit_soul";
		case DF_Type::unit_soul__T_performance_skills: return "unit_soul__T_performance_skills";
		case DF_Type::unit_station_type: return "unit_station_type";
		case DF_Type::unit_storage_status: return "unit_storage_status";
		case DF_Type::unit_syndrome: return "unit_syndrome";
		case DF_Type::unit_syndrome__T_flags: return "unit_syndrome__T_flags";
		case DF_Type::unit_syndrome__T_symptoms: return "unit_syndrome__T_symptoms";
		case DF_Type::unit_syndrome__T_symptoms__T_flags: return "unit_syndrome__T_symptoms__T_flags";
		case DF_Type::unit_thought_type: return "unit_thought_type";
		case DF_Type::unit_unk_138: return "unit_unk_138";
		case DF_Type::unit_wound: return "unit_wound";
		case DF_Type::unit_wound__T_flags: return "unit_wound__T_flags";
		case DF_Type::unit_wound__T_parts: return "unit_wound__T_parts";
		case DF_Type::units_other_id: return "units_other_id";
		case DF_Type::unk_scale_enum_type: return "unk_scale_enum_type";
		case DF_Type::vague_relationship_type: return "vague_relationship_type";
		case DF_Type::value_type: return "value_type";
		case DF_Type::vehicle: return "vehicle";
		case DF_Type::vermin: return "vermin";
		case DF_Type::vermin_flags: return "vermin_flags";
		case DF_Type::viewscreen: return "viewscreen";
		case DF_Type::viewscreen_adopt_regionst: return "viewscreen_adopt_regionst";
		case DF_Type::viewscreen_adventure_logst: return "viewscreen_adventure_logst";
		case DF_Type::viewscreen_adventure_logst__T_info_mode: return "viewscreen_adventure_logst__T_info_mode";
		case DF_Type::viewscreen_adventure_logst__T_mode: return "viewscreen_adventure_logst__T_mode";
		case DF_Type::viewscreen_adventure_logst__T_unk_68: return "viewscreen_adventure_logst__T_unk_68";
		case DF_Type::viewscreen_announcelistst: return "viewscreen_announcelistst";
		case DF_Type::viewscreen_assign_display_itemst: return "viewscreen_assign_display_itemst";
		case DF_Type::viewscreen_assign_display_itemst__T_sel_column: return "viewscreen_assign_display_itemst__T_sel_column";
		case DF_Type::viewscreen_barterst: return "viewscreen_barterst";
		case DF_Type::viewscreen_buildinglistst: return "viewscreen_buildinglistst";
		case DF_Type::viewscreen_buildingst: return "viewscreen_buildingst";
		case DF_Type::viewscreen_choose_start_sitest: return "viewscreen_choose_start_sitest";
		case DF_Type::viewscreen_choose_start_sitest__T_finder: return "viewscreen_choose_start_sitest__T_finder";
		case DF_Type::viewscreen_choose_start_sitest__T_finder__T_finder_state: return "viewscreen_choose_start_sitest__T_finder__T_finder_state";
		case DF_Type::viewscreen_choose_start_sitest__T_page: return "viewscreen_choose_start_sitest__T_page";
		case DF_Type::viewscreen_civlistst: return "viewscreen_civlistst";
		case DF_Type::viewscreen_civlistst__T_artifact_details: return "viewscreen_civlistst__T_artifact_details";
		case DF_Type::viewscreen_civlistst__T_page: return "viewscreen_civlistst__T_page";
		case DF_Type::viewscreen_civlistst__T_rumors: return "viewscreen_civlistst__T_rumors";
		case DF_Type::viewscreen_civlistst__T_rumors__T_type: return "viewscreen_civlistst__T_rumors__T_type";
		case DF_Type::viewscreen_civlistst__T_unk_cache: return "viewscreen_civlistst__T_unk_cache";
		case DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp1: return "viewscreen_civlistst__T_unk_cache__T_tmp1";
		case DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp2: return "viewscreen_civlistst__T_unk_cache__T_tmp2";
		case DF_Type::viewscreen_counterintelligencest: return "viewscreen_counterintelligencest";
		case DF_Type::viewscreen_createquotast: return "viewscreen_createquotast";
		case DF_Type::viewscreen_customize_unitst: return "viewscreen_customize_unitst";
		case DF_Type::viewscreen_dungeon_monsterstatusst: return "viewscreen_dungeon_monsterstatusst";
		case DF_Type::viewscreen_dungeon_wrestlest: return "viewscreen_dungeon_wrestlest";
		case DF_Type::viewscreen_dungeon_wrestlest__T_unk1: return "viewscreen_dungeon_wrestlest__T_unk1";
		case DF_Type::viewscreen_dungeonmodest: return "viewscreen_dungeonmodest";
		case DF_Type::viewscreen_dwarfmodest: return "viewscreen_dwarfmodest";
		case DF_Type::viewscreen_entityst: return "viewscreen_entityst";
		case DF_Type::viewscreen_export_graphical_mapst: return "viewscreen_export_graphical_mapst";
		case DF_Type::viewscreen_export_graphical_mapst__T_rgb_buffer: return "viewscreen_export_graphical_mapst__T_rgb_buffer";
		case DF_Type::viewscreen_export_regionst: return "viewscreen_export_regionst";
		case DF_Type::viewscreen_export_regionst__T_unk1: return "viewscreen_export_regionst__T_unk1";
		case DF_Type::viewscreen_game_cleanerst: return "viewscreen_game_cleanerst";
		case DF_Type::viewscreen_game_cleanerst__T_state: return "viewscreen_game_cleanerst__T_state";
		case DF_Type::viewscreen_image_creator_mode: return "viewscreen_image_creator_mode";
		case DF_Type::viewscreen_image_creatorst: return "viewscreen_image_creatorst";
		case DF_Type::viewscreen_image_creatorst__T_artifacts: return "viewscreen_image_creatorst__T_artifacts";
		case DF_Type::viewscreen_image_creatorst__T_entities: return "viewscreen_image_creatorst__T_entities";
		case DF_Type::viewscreen_image_creatorst__T_histfigs: return "viewscreen_image_creatorst__T_histfigs";
		case DF_Type::viewscreen_image_creatorst__T_objects: return "viewscreen_image_creatorst__T_objects";
		case DF_Type::viewscreen_image_creatorst__T_plants: return "viewscreen_image_creatorst__T_plants";
		case DF_Type::viewscreen_image_creatorst__T_relationships: return "viewscreen_image_creatorst__T_relationships";
		case DF_Type::viewscreen_image_creatorst__T_shapes: return "viewscreen_image_creatorst__T_shapes";
		case DF_Type::viewscreen_image_creatorst__T_sites: return "viewscreen_image_creatorst__T_sites";
		case DF_Type::viewscreen_image_creatorst__T_trees: return "viewscreen_image_creatorst__T_trees";
		case DF_Type::viewscreen_itemst: return "viewscreen_itemst";
		case DF_Type::viewscreen_joblistst: return "viewscreen_joblistst";
		case DF_Type::viewscreen_jobmanagementst: return "viewscreen_jobmanagementst";
		case DF_Type::viewscreen_jobst: return "viewscreen_jobst";
		case DF_Type::viewscreen_justicest: return "viewscreen_justicest";
		case DF_Type::viewscreen_justicest__T_cur_column: return "viewscreen_justicest__T_cur_column";
		case DF_Type::viewscreen_justicest__T_interrogate_status: return "viewscreen_justicest__T_interrogate_status";
		case DF_Type::viewscreen_kitchenpref_page: return "viewscreen_kitchenpref_page";
		case DF_Type::viewscreen_kitchenprefst: return "viewscreen_kitchenprefst";
		case DF_Type::viewscreen_layer: return "viewscreen_layer";
		case DF_Type::viewscreen_layer_arena_creaturest: return "viewscreen_layer_arena_creaturest";
		case DF_Type::viewscreen_layer_assigntradest: return "viewscreen_layer_assigntradest";
		case DF_Type::viewscreen_layer_choose_language_namest: return "viewscreen_layer_choose_language_namest";
		case DF_Type::viewscreen_layer_choose_language_namest__T_current_component: return "viewscreen_layer_choose_language_namest__T_current_component";
		case DF_Type::viewscreen_layer_currencyst: return "viewscreen_layer_currencyst";
		case DF_Type::viewscreen_layer_export_play_mapst: return "viewscreen_layer_export_play_mapst";
		case DF_Type::viewscreen_layer_militaryst: return "viewscreen_layer_militaryst";
		case DF_Type::viewscreen_layer_militaryst__T_ammo: return "viewscreen_layer_militaryst__T_ammo";
		case DF_Type::viewscreen_layer_militaryst__T_ammo__T_add_item: return "viewscreen_layer_militaryst__T_ammo__T_add_item";
		case DF_Type::viewscreen_layer_militaryst__T_ammo__T_material: return "viewscreen_layer_militaryst__T_ammo__T_material";
		case DF_Type::viewscreen_layer_militaryst__T_equip: return "viewscreen_layer_militaryst__T_equip";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_add_item: return "viewscreen_layer_militaryst__T_equip__T_add_item";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_assigned: return "viewscreen_layer_militaryst__T_equip__T_assigned";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_color: return "viewscreen_layer_militaryst__T_equip__T_color";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode: return "viewscreen_layer_militaryst__T_equip__T_edit_mode";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_material: return "viewscreen_layer_militaryst__T_equip__T_material";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_mode: return "viewscreen_layer_militaryst__T_equip__T_mode";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_uniform: return "viewscreen_layer_militaryst__T_equip__T_uniform";
		case DF_Type::viewscreen_layer_militaryst__T_page: return "viewscreen_layer_militaryst__T_page";
		case DF_Type::viewscreen_layer_militaryst__T_positions: return "viewscreen_layer_militaryst__T_positions";
		case DF_Type::viewscreen_layer_militaryst__T_squad_members: return "viewscreen_layer_militaryst__T_squad_members";
		case DF_Type::viewscreen_layer_militaryst__T_squads: return "viewscreen_layer_militaryst__T_squads";
		case DF_Type::viewscreen_layer_musicsoundst: return "viewscreen_layer_musicsoundst";
		case DF_Type::viewscreen_layer_noblelistst: return "viewscreen_layer_noblelistst";
		case DF_Type::viewscreen_layer_noblelistst__T_candidates: return "viewscreen_layer_noblelistst__T_candidates";
		case DF_Type::viewscreen_layer_noblelistst__T_info: return "viewscreen_layer_noblelistst__T_info";
		case DF_Type::viewscreen_layer_noblelistst__T_mode: return "viewscreen_layer_noblelistst__T_mode";
		case DF_Type::viewscreen_layer_overall_healthst: return "viewscreen_layer_overall_healthst";
		case DF_Type::viewscreen_layer_reactionst: return "viewscreen_layer_reactionst";
		case DF_Type::viewscreen_layer_squad_schedulest: return "viewscreen_layer_squad_schedulest";
		case DF_Type::viewscreen_layer_stockpilest: return "viewscreen_layer_stockpilest";
		case DF_Type::viewscreen_layer_stone_restrictionst: return "viewscreen_layer_stone_restrictionst";
		case DF_Type::viewscreen_layer_unit_actionst: return "viewscreen_layer_unit_actionst";
		case DF_Type::viewscreen_layer_unit_healthst: return "viewscreen_layer_unit_healthst";
		case DF_Type::viewscreen_layer_unit_relationshipst: return "viewscreen_layer_unit_relationshipst";
		case DF_Type::viewscreen_layer_world_gen_param_presetst: return "viewscreen_layer_world_gen_param_presetst";
		case DF_Type::viewscreen_layer_world_gen_paramst: return "viewscreen_layer_world_gen_paramst";
		case DF_Type::viewscreen_layer_world_gen_paramst__T_unk1: return "viewscreen_layer_world_gen_paramst__T_unk1";
		case DF_Type::viewscreen_legendsst: return "viewscreen_legendsst";
		case DF_Type::viewscreen_legendsst__T_anon_7: return "viewscreen_legendsst__T_anon_7";
		case DF_Type::viewscreen_legendsst__T_anon_7__T_anon_3: return "viewscreen_legendsst__T_anon_7__T_anon_3";
		case DF_Type::viewscreen_legendsst__T_cur_page: return "viewscreen_legendsst__T_cur_page";
		case DF_Type::viewscreen_loadgamest: return "viewscreen_loadgamest";
		case DF_Type::viewscreen_loadgamest__T_cur_step: return "viewscreen_loadgamest__T_cur_step";
		case DF_Type::viewscreen_locationsst: return "viewscreen_locationsst";
		case DF_Type::viewscreen_locationsst__T_in_edit: return "viewscreen_locationsst__T_in_edit";
		case DF_Type::viewscreen_locationsst__T_menu: return "viewscreen_locationsst__T_menu";
		case DF_Type::viewscreen_meetingst: return "viewscreen_meetingst";
		case DF_Type::viewscreen_movieplayerst: return "viewscreen_movieplayerst";
		case DF_Type::viewscreen_new_regionst: return "viewscreen_new_regionst";
		case DF_Type::viewscreen_new_regionst__T_worldgen_presets: return "viewscreen_new_regionst__T_worldgen_presets";
		case DF_Type::viewscreen_noblest: return "viewscreen_noblest";
		case DF_Type::viewscreen_optionst: return "viewscreen_optionst";
		case DF_Type::viewscreen_optionst__T_options: return "viewscreen_optionst__T_options";
		case DF_Type::viewscreen_overallstatusst: return "viewscreen_overallstatusst";
		case DF_Type::viewscreen_overallstatusst__T_visible_pages: return "viewscreen_overallstatusst__T_visible_pages";
		case DF_Type::viewscreen_petitionsst: return "viewscreen_petitionsst";
		case DF_Type::viewscreen_petst: return "viewscreen_petst";
		case DF_Type::viewscreen_petst__T_animal: return "viewscreen_petst__T_animal";
		case DF_Type::viewscreen_petst__T_mode: return "viewscreen_petst__T_mode";
		case DF_Type::viewscreen_petst__T_trainer_mode: return "viewscreen_petst__T_trainer_mode";
		case DF_Type::viewscreen_pricest: return "viewscreen_pricest";
		case DF_Type::viewscreen_reportlistst: return "viewscreen_reportlistst";
		case DF_Type::viewscreen_requestagreementst: return "viewscreen_requestagreementst";
		case DF_Type::viewscreen_savegamest: return "viewscreen_savegamest";
		case DF_Type::viewscreen_selectitemst: return "viewscreen_selectitemst";
		case DF_Type::viewscreen_setupadventurest: return "viewscreen_setupadventurest";
		case DF_Type::viewscreen_setupadventurest__T_page: return "viewscreen_setupadventurest__T_page";
		case DF_Type::viewscreen_setupadventurest__T_races_info: return "viewscreen_setupadventurest__T_races_info";
		case DF_Type::viewscreen_setupadventurest__T_status: return "viewscreen_setupadventurest__T_status";
		case DF_Type::viewscreen_setupdwarfgamest: return "viewscreen_setupdwarfgamest";
		case DF_Type::viewscreen_setupdwarfgamest__T_animals: return "viewscreen_setupdwarfgamest__T_animals";
		case DF_Type::viewscreen_setupdwarfgamest__T_choice_types: return "viewscreen_setupdwarfgamest__T_choice_types";
		case DF_Type::viewscreen_setupdwarfgamest__T_mode: return "viewscreen_setupdwarfgamest__T_mode";
		case DF_Type::viewscreen_setupdwarfgamest__T_unk_v43: return "viewscreen_setupdwarfgamest__T_unk_v43";
		case DF_Type::viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9: return "viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9";
		case DF_Type::viewscreen_storesst: return "viewscreen_storesst";
		case DF_Type::viewscreen_textviewerst: return "viewscreen_textviewerst";
		case DF_Type::viewscreen_textviewerst__T_formatted_text: return "viewscreen_textviewerst__T_formatted_text";
		case DF_Type::viewscreen_textviewerst__T_formatted_text__T_flags: return "viewscreen_textviewerst__T_formatted_text__T_flags";
		case DF_Type::viewscreen_titlest: return "viewscreen_titlest";
		case DF_Type::viewscreen_titlest__T_menu_line_id: return "viewscreen_titlest__T_menu_line_id";
		case DF_Type::viewscreen_titlest__T_sel_subpage: return "viewscreen_titlest__T_sel_subpage";
		case DF_Type::viewscreen_titlest__T_start_savegames: return "viewscreen_titlest__T_start_savegames";
		case DF_Type::viewscreen_topicmeeting_fill_land_holder_positionsst: return "viewscreen_topicmeeting_fill_land_holder_positionsst";
		case DF_Type::viewscreen_topicmeeting_takerequestsst: return "viewscreen_topicmeeting_takerequestsst";
		case DF_Type::viewscreen_topicmeetingst: return "viewscreen_topicmeetingst";
		case DF_Type::viewscreen_tradeagreementst: return "viewscreen_tradeagreementst";
		case DF_Type::viewscreen_tradegoodsst: return "viewscreen_tradegoodsst";
		case DF_Type::viewscreen_tradelistst: return "viewscreen_tradelistst";
		case DF_Type::viewscreen_treasurelistst: return "viewscreen_treasurelistst";
		case DF_Type::viewscreen_unitlist_page: return "viewscreen_unitlist_page";
		case DF_Type::viewscreen_unitlistst: return "viewscreen_unitlistst";
		case DF_Type::viewscreen_unitst: return "viewscreen_unitst";
		case DF_Type::viewscreen_update_regionst: return "viewscreen_update_regionst";
		case DF_Type::viewscreen_wagesst: return "viewscreen_wagesst";
		case DF_Type::viewscreen_workquota_conditionst: return "viewscreen_workquota_conditionst";
		case DF_Type::viewscreen_workquota_conditionst__T_mode: return "viewscreen_workquota_conditionst__T_mode";
		case DF_Type::viewscreen_workquota_conditionst__T_traits: return "viewscreen_workquota_conditionst__T_traits";
		case DF_Type::viewscreen_workquota_conditionst__T_traits__T_flags: return "viewscreen_workquota_conditionst__T_traits__T_flags";
		case DF_Type::viewscreen_workquota_detailsst: return "viewscreen_workquota_detailsst";
		case DF_Type::viewscreen_workshop_profilest: return "viewscreen_workshop_profilest";
		case DF_Type::viewscreen_workshop_profilest__T_tab: return "viewscreen_workshop_profilest__T_tab";
		case DF_Type::weapon_attack: return "weapon_attack";
		case DF_Type::weapon_attack__T_flags: return "weapon_attack__T_flags";
		case DF_Type::weapon_flags: return "weapon_flags";
		case DF_Type::weather_type: return "weather_type";
		case DF_Type::web_cluster: return "web_cluster";
		case DF_Type::whereabouts_type: return "whereabouts_type";
		case DF_Type::widget_menu: return "widget_menu";
		case DF_Type::widget_textbox: return "widget_textbox";
		case DF_Type::workshop_profile: return "workshop_profile";
		case DF_Type::workshop_type: return "workshop_type";
		case DF_Type::world: return "world";
		case DF_Type::world__T_activities: return "world__T_activities";
		case DF_Type::world__T_agreements: return "world__T_agreements";
		case DF_Type::world__T_area_grasses: return "world__T_area_grasses";
		case DF_Type::world__T_area_grasses__T_layer_grasses: return "world__T_area_grasses__T_layer_grasses";
		case DF_Type::world__T_arena_settings: return "world__T_arena_settings";
		case DF_Type::world__T_arena_spawn: return "world__T_arena_spawn";
		case DF_Type::world__T_arena_spawn__T_equipment: return "world__T_arena_spawn__T_equipment";
		case DF_Type::world__T_arena_spawn__T_item_types: return "world__T_arena_spawn__T_item_types";
		case DF_Type::world__T_arena_spawn__T_tame: return "world__T_arena_spawn__T_tame";
		case DF_Type::world__T_armies: return "world__T_armies";
		case DF_Type::world__T_army_controllers: return "world__T_army_controllers";
		case DF_Type::world__T_army_tracking_info: return "world__T_army_tracking_info";
		case DF_Type::world__T_artifacts: return "world__T_artifacts";
		case DF_Type::world__T_belief_systems: return "world__T_belief_systems";
		case DF_Type::world__T_crimes: return "world__T_crimes";
		case DF_Type::world__T_cultural_identities: return "world__T_cultural_identities";
		case DF_Type::world__T_cur_savegame: return "world__T_cur_savegame";
		case DF_Type::world__T_dance_forms: return "world__T_dance_forms";
		case DF_Type::world__T_divination_sets: return "world__T_divination_sets";
		case DF_Type::world__T_enemy_status_cache: return "world__T_enemy_status_cache";
		case DF_Type::world__T_entities: return "world__T_entities";
		case DF_Type::world__T_features: return "world__T_features";
		case DF_Type::world__T_flow_engine: return "world__T_flow_engine";
		case DF_Type::world__T_flow_guides: return "world__T_flow_guides";
		case DF_Type::world__T_formations: return "world__T_formations";
		case DF_Type::world__T_identities: return "world__T_identities";
		case DF_Type::world__T_image_sets: return "world__T_image_sets";
		case DF_Type::world__T_incidents: return "world__T_incidents";
		case DF_Type::world__T_interaction_instances: return "world__T_interaction_instances";
		case DF_Type::world__T_items: return "world__T_items";
		case DF_Type::world__T_languages: return "world__T_languages";
		case DF_Type::world__T_map: return "world__T_map";
		case DF_Type::world__T_map_extras: return "world__T_map_extras";
		case DF_Type::world__T_math: return "world__T_math";
		case DF_Type::world__T_math__T_approx: return "world__T_math__T_approx";
		case DF_Type::world__T_musical_forms: return "world__T_musical_forms";
		case DF_Type::world__T_nemesis: return "world__T_nemesis";
		case DF_Type::world__T_occupations: return "world__T_occupations";
		case DF_Type::world__T_pathfinder: return "world__T_pathfinder";
		case DF_Type::world__T_pathfinder__T_boundary_heap: return "world__T_pathfinder__T_boundary_heap";
		case DF_Type::world__T_plants: return "world__T_plants";
		case DF_Type::world__T_poetic_forms: return "world__T_poetic_forms";
		case DF_Type::world__T_profession_skills: return "world__T_profession_skills";
		case DF_Type::world__T_rhythms: return "world__T_rhythms";
		case DF_Type::world__T_scales: return "world__T_scales";
		case DF_Type::world__T_schedules: return "world__T_schedules";
		case DF_Type::world__T_squads: return "world__T_squads";
		case DF_Type::world__T_status: return "world__T_status";
		case DF_Type::world__T_status__T_flags: return "world__T_status__T_flags";
		case DF_Type::world__T_status__T_slots: return "world__T_status__T_slots";
		case DF_Type::world__T_status__T_slots__T_flags: return "world__T_status__T_slots__T_flags";
		case DF_Type::world__T_stockpile: return "world__T_stockpile";
		case DF_Type::world__T_stockpile__T_simple1: return "world__T_stockpile__T_simple1";
		case DF_Type::world__T_stockpile__T_simple2: return "world__T_stockpile__T_simple2";
		case DF_Type::world__T_stockpile__T_simple3: return "world__T_stockpile__T_simple3";
		case DF_Type::world__T_units: return "world__T_units";
		case DF_Type::world__T_unk_131ec0: return "world__T_unk_131ec0";
		case DF_Type::world__T_unk_131ef0: return "world__T_unk_131ef0";
		case DF_Type::world__T_unk_131ef0__T_claims: return "world__T_unk_131ef0__T_claims";
		case DF_Type::world__T_unk_19325c: return "world__T_unk_19325c";
		case DF_Type::world__T_unk_19325c__T_anon_1: return "world__T_unk_19325c__T_anon_1";
		case DF_Type::world__T_unk_19325c__T_anon_2: return "world__T_unk_19325c__T_anon_2";
		case DF_Type::world__T_unk_19325c__T_anon_3: return "world__T_unk_19325c__T_anon_3";
		case DF_Type::world__T_unk_26c678: return "world__T_unk_26c678";
		case DF_Type::world__T_unk_v40_6: return "world__T_unk_v40_6";
		case DF_Type::world__T_vehicles: return "world__T_vehicles";
		case DF_Type::world__T_vermin: return "world__T_vermin";
		case DF_Type::world__T_worldgen: return "world__T_worldgen";
		case DF_Type::world__T_worldgen__T_worldgen_parms: return "world__T_worldgen__T_worldgen_parms";
		case DF_Type::world__T_worldgen_coord_buf: return "world__T_worldgen_coord_buf";
		case DF_Type::world__T_worldgen_status: return "world__T_worldgen_status";
		case DF_Type::world__T_written_contents: return "world__T_written_contents";
		case DF_Type::world_construction: return "world_construction";
		case DF_Type::world_construction_bridgest: return "world_construction_bridgest";
		case DF_Type::world_construction_roadst: return "world_construction_roadst";
		case DF_Type::world_construction_square: return "world_construction_square";
		case DF_Type::world_construction_square_bridgest: return "world_construction_square_bridgest";
		case DF_Type::world_construction_square_roadst: return "world_construction_square_roadst";
		case DF_Type::world_construction_square_tunnelst: return "world_construction_square_tunnelst";
		case DF_Type::world_construction_square_wallst: return "world_construction_square_wallst";
		case DF_Type::world_construction_tunnelst: return "world_construction_tunnelst";
		case DF_Type::world_construction_type: return "world_construction_type";
		case DF_Type::world_construction_wallst: return "world_construction_wallst";
		case DF_Type::world_dat_summary: return "world_dat_summary";
		case DF_Type::world_data: return "world_data";
		case DF_Type::world_data__T_constructions: return "world_data__T_constructions";
		case DF_Type::world_data__T_feature_map: return "world_data__T_feature_map";
		case DF_Type::world_data__T_feature_map__T_features: return "world_data__T_feature_map__T_features";
		case DF_Type::world_data__T_flip_latitude: return "world_data__T_flip_latitude";
		case DF_Type::world_data__T_mountain_peaks: return "world_data__T_mountain_peaks";
		case DF_Type::world_data__T_unk_274: return "world_data__T_unk_274";
		case DF_Type::world_data__T_unk_274__T_unk_10: return "world_data__T_unk_274__T_unk_10";
		case DF_Type::world_data__T_unk_482f8: return "world_data__T_unk_482f8";
		case DF_Type::world_data__T_unk_b4: return "world_data__T_unk_b4";
		case DF_Type::world_gen_param_basest: return "world_gen_param_basest";
		case DF_Type::world_gen_param_charst: return "world_gen_param_charst";
		case DF_Type::world_gen_param_memberst: return "world_gen_param_memberst";
		case DF_Type::world_gen_param_seedst: return "world_gen_param_seedst";
		case DF_Type::world_gen_param_valuest: return "world_gen_param_valuest";
		case DF_Type::world_geo_biome: return "world_geo_biome";
		case DF_Type::world_geo_layer: return "world_geo_layer";
		case DF_Type::world_history: return "world_history";
		case DF_Type::world_history__T_event_collections: return "world_history__T_event_collections";
		case DF_Type::world_history__T_intrigues: return "world_history__T_intrigues";
		case DF_Type::world_history__T_intrigues__T_anon_1: return "world_history__T_intrigues__T_anon_1";
		case DF_Type::world_landmass: return "world_landmass";
		case DF_Type::world_object_data: return "world_object_data";
		case DF_Type::world_object_data__T_offloaded_buildings: return "world_object_data__T_offloaded_buildings";
		case DF_Type::world_object_data__T_offloaded_items: return "world_object_data__T_offloaded_items";
		case DF_Type::world_object_data__T_unk_94: return "world_object_data__T_unk_94";
		case DF_Type::world_population: return "world_population";
		case DF_Type::world_population___union5: return "world_population___union5";
		case DF_Type::world_population_ref: return "world_population_ref";
		case DF_Type::world_population_type: return "world_population_type";
		case DF_Type::world_raws: return "world_raws";
		case DF_Type::world_raws__T_bodyglosses: return "world_raws__T_bodyglosses";
		case DF_Type::world_raws__T_buildings: return "world_raws__T_buildings";
		case DF_Type::world_raws__T_descriptors: return "world_raws__T_descriptors";
		case DF_Type::world_raws__T_effects: return "world_raws__T_effects";
		case DF_Type::world_raws__T_itemdefs: return "world_raws__T_itemdefs";
		case DF_Type::world_raws__T_language: return "world_raws__T_language";
		case DF_Type::world_raws__T_plants: return "world_raws__T_plants";
		case DF_Type::world_raws__T_reactions: return "world_raws__T_reactions";
		case DF_Type::world_raws__T_syndromes: return "world_raws__T_syndromes";
		case DF_Type::world_region: return "world_region";
		case DF_Type::world_region_details: return "world_region_details";
		case DF_Type::world_region_details__T_edges: return "world_region_details__T_edges";
		case DF_Type::world_region_details__T_other_features: return "world_region_details__T_other_features";
		case DF_Type::world_region_details__T_rivers_horizontal: return "world_region_details__T_rivers_horizontal";
		case DF_Type::world_region_details__T_rivers_vertical: return "world_region_details__T_rivers_vertical";
		case DF_Type::world_region_feature: return "world_region_feature";
		case DF_Type::world_region_type: return "world_region_type";
		case DF_Type::world_river: return "world_river";
		case DF_Type::world_site: return "world_site";
		case DF_Type::world_site__T_subtype_info: return "world_site__T_subtype_info";
		case DF_Type::world_site__T_unk_1: return "world_site__T_unk_1";
		case DF_Type::world_site__T_unk_118: return "world_site__T_unk_118";
		case DF_Type::world_site__T_unk_13c: return "world_site__T_unk_13c";
		case DF_Type::world_site__T_unk_188: return "world_site__T_unk_188";
		case DF_Type::world_site__T_unk_188__T_unk1: return "world_site__T_unk_188__T_unk1";
		case DF_Type::world_site__T_unk_1__T_units: return "world_site__T_unk_1__T_units";
		case DF_Type::world_site__T_unk_21c: return "world_site__T_unk_21c";
		case DF_Type::world_site__T_unk_v40_2: return "world_site__T_unk_v40_2";
		case DF_Type::world_site__T_unk_v40_4a: return "world_site__T_unk_v40_4a";
		case DF_Type::world_site__T_unk_v40_4b: return "world_site__T_unk_v40_4b";
		case DF_Type::world_site__T_unk_v40_4c: return "world_site__T_unk_v40_4c";
		case DF_Type::world_site__T_unk_v40_4d: return "world_site__T_unk_v40_4d";
		case DF_Type::world_site__T_unk_v40_4d__T_anon_1: return "world_site__T_unk_v40_4d__T_anon_1";
		case DF_Type::world_site__T_unk_v43_2: return "world_site__T_unk_v43_2";
		case DF_Type::world_site__T_unk_v47_1: return "world_site__T_unk_v47_1";
		case DF_Type::world_site__T_unk_v47_1__T_unk_1: return "world_site__T_unk_v47_1__T_unk_1";
		case DF_Type::world_site_flags: return "world_site_flags";
		case DF_Type::world_site_inhabitant: return "world_site_inhabitant";
		case DF_Type::world_site_realization: return "world_site_realization";
		case DF_Type::world_site_realization__T_areas: return "world_site_realization__T_areas";
		case DF_Type::world_site_realization__T_areas__T_type: return "world_site_realization__T_areas__T_type";
		case DF_Type::world_site_realization__T_building_map: return "world_site_realization__T_building_map";
		case DF_Type::world_site_realization__T_river_map: return "world_site_realization__T_river_map";
		case DF_Type::world_site_realization__T_unk_193bc: return "world_site_realization__T_unk_193bc";
		case DF_Type::world_site_realization__T_unk_193bc__T_unk_8: return "world_site_realization__T_unk_193bc__T_unk_8";
		case DF_Type::world_site_realization__T_unk_55e8: return "world_site_realization__T_unk_55e8";
		case DF_Type::world_site_realization__T_unk_55e8__T_unk_v40_2: return "world_site_realization__T_unk_55e8__T_unk_v40_2";
		case DF_Type::world_site_type: return "world_site_type";
		case DF_Type::world_site_unk130: return "world_site_unk130";
		case DF_Type::world_site_unk130__T_unk_4: return "world_site_unk130__T_unk_4";
		case DF_Type::world_underground_region: return "world_underground_region";
		case DF_Type::world_underground_region__T_type: return "world_underground_region__T_type";
		case DF_Type::world_unk26c678_unk38: return "world_unk26c678_unk38";
		case DF_Type::world_unk_20: return "world_unk_20";
		case DF_Type::world_unk_20__T_anon_7: return "world_unk_20__T_anon_7";
		case DF_Type::world_unk_6c: return "world_unk_6c";
		case DF_Type::world_unk_a8: return "world_unk_a8";
		case DF_Type::world_unk_b4: return "world_unk_b4";
		case DF_Type::world_unk_c0: return "world_unk_c0";
		case DF_Type::world_unk_c0__T_anon_7: return "world_unk_c0__T_anon_7";
		case DF_Type::worldgen_range_type: return "worldgen_range_type";
		case DF_Type::worldgen_region_type: return "worldgen_region_type";
		case DF_Type::wound_curse_info: return "wound_curse_info";
		case DF_Type::wound_curse_info__T_timing: return "wound_curse_info__T_timing";
		case DF_Type::wound_damage_flags1: return "wound_damage_flags1";
		case DF_Type::wound_damage_flags2: return "wound_damage_flags2";
		case DF_Type::wound_effect_type: return "wound_effect_type";
		case DF_Type::written_content: return "written_content";
		case DF_Type::written_content_style: return "written_content_style";
		case DF_Type::written_content_type: return "written_content_type";
		case DF_Type::z_level_flags: return "z_level_flags";
		case DF_Type::zoom_commands: return "zoom_commands";
	}
	return "";
}
}

