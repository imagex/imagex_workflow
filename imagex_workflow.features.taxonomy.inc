<?php
/**
 * @file
 * imagex_workflow.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function imagex_workflow_taxonomy_default_vocabularies() {
  $taxonomy = array(
    'workbench_section' => array(
      'name' => 'Workbench Section',
      'machine_name' => 'workbench_section',
      'description' => 'Taxonomy terms associated with editorial workflow permissions.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );

  features_alter_code('taxonomy', $taxonomy);

  return $taxonomy;
}
