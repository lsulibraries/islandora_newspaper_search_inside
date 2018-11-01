<?php
/**
 * @file
 * Returns the form of the resulted pages which got hit by the searched string
 */

/**
 * Implements hook_form().
 */
function islandora_newspaper_search_inside_results_form($form, &$form_state) {
  $params = drupal_get_query_parameters();
  $n = array();
  $n = count($params);
  $search = $params[$n-1];
  unset($params[$n-1]);
  $n = count($params);
  $form['results'] = array(
    '#type' => 'markup',
    '#markup' => "<div class='isandora_solr_search_result'>
                    <div class='islandora_solr_search_result_inner'>
                      <div>You have searched for the string '$search'</div>
                      <div>$n results found in OCR Datastream</div>
                    </div>
                  </div>",
  );
    foreach ($params as $pid) {
      $obj = islandora_object_load($pid);
      $path = '/islandora/object/' . $obj->id;
      $ocr_view = '/islandora/object/' . $obj->id . '/datastream/OCR/view';
      $tn_link = '/islandora/object/' . $obj->id . '/datastream/TN/view';
      $path_link = "<a href='$path'><img src='$tn_link' alt='$obj->label'></img></a>";
      $ocr_link = "<a href='$ocr_view'>View OCR</a>";
      $obj_link = "<a href='$path'>$obj->label</a>";
      $form[$obj->id] = array(
        '#type' => 'markup',
        '#markup' => "<div class='isandora_solr_search_result'>
                        <div class = 'islandora-solr-search-result clear-block even'>
                          <div class='islandora_solr_search_result_inner'>
                            <div>$obj_link</div>
                            <div>$ocr_link</div>
                            <div>$path_link</div>
                            </div>
                          </div>
                        </div>",
      );
    }
  return $form;
}
