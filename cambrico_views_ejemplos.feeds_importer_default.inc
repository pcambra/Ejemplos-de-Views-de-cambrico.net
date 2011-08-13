<?php
/**
 * @file
 * cambrico_views_ejemplos.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function cambrico_views_ejemplos_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'importador_lugar';
  $feeds_importer->config = array(
    'name' => 'Importador de Lugar',
    'description' => 'Importador para lugares',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'lugar',
        'expire' => '-1',
        'author' => '1',
        'mappings' => array(
          0 => array(
            'source' => 'nombre',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'descripcion',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'nombre',
            'target' => 'guid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'imagen',
            'target' => 'field_lugar_imagenes',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'habitantes',
            'target' => 'field_lugar_habitantes',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'web',
            'target' => 'field_lugar_web',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'pais',
            'target' => 'field_lugar_pais',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['importador_lugar'] = $feeds_importer;

  return $export;
}
