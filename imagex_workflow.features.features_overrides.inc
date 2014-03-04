<?php
/**
 * @file
 * imagex_workflow.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function imagex_workflow_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: views_view
  $overrides["views_view.admin_views_node.display|default|display_options|filters|state"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_node.display|default|display_options|query|options|slave"]["DELETED"] = TRUE;
  $overrides["views_view.admin_views_node.display|page_1"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:3:{s:8:"defaults";a:2:{s:13:"filter_groups";b:0;s:7:"filters";b:0;}s:7:"filters";a:1:{s:5:"state";a:5:{s:2:"id";s:5:"state";s:5:"table";s:33:"workbench_moderation_node_history";s:5:"field";s:5:"state";s:7:"exposed";b:1;s:6:"expose";a:5:{s:11:"operator_id";s:8:"state_op";s:5:"label";s:5:"State";s:8:"operator";s:8:"state_op";s:10:"identifier";s:5:"state";s:14:"remember_roles";a:7:{i:2;s:1:"2";i:1;i:0;i:7;i:0;i:6;i:0;i:4;i:0;i:5;i:0;i:3;i:0;}}}}s:4:"path";s:13:"admin/content";}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:6:"page_1";s:13:"display_title";s:4:"Page";s:14:"display_plugin";s:4:"page";s:8:"position";i:0;}');
  $overrides["views_view.admin_views_node.display|system_1|display_options|enabled"] = FALSE;

  features_alter_code('features_overrides', $overrides);

  return $overrides;
}
