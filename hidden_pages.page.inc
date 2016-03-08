<?php

/**
 * @file
 * This function checks URL argument. Checked siteapikey and node id page type.
 */

/**
 * This function displayed node.
 */
function page_show() {

  // Check URL arg(0) should be page_json.
  if (arg(0) == 'page_json') {
    $siteapikey = variable_get('siteapikey', 'No API Key yet');

    // Check if arg 1 is match with Site API Key and arg 2(nid) is numeric.
    if ($siteapikey == arg(1) && is_numeric(arg(2))) {
      $node = node_load(arg(2));

      // Check if valid node id exists and Node Type is Page.
      if (!empty($node) && $node->type == 'page') {
        drupal_set_title(t('Hidden node: @title', array('@title' => $node->title)));
        $output = node_show($node, 0);
        return $output;
      }
      else {
        drupal_set_title(t('Hidden Node: @title', array('@title' => 'access denied')));
        return (t('Please use valid Node id or node type'));
      }
    }
    else {

      // If site APIkey is not matched then user will get access denied massage.
      drupal_set_title(t('Hidden Node: @title', array('@title' => 'access denied')));
      return (t('You are not authorized to access this page.'));
    }
  }
}
