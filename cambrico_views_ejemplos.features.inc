<?php
/**
 * @file
 * cambrico_views_ejemplos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cambrico_views_ejemplos_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cambrico_views_ejemplos_node_info() {
  $items = array(
    'lugar' => array(
      'name' => t('Lugar'),
      'base' => 'node_content',
      'description' => t('Registro de todos los lugares con información relacionada'),
      'has_title' => '1',
      'title_label' => t('Nombre'),
      'help' => '',
    ),
  );
  return $items;
}
