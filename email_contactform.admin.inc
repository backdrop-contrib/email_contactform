<?php
/**
 * @file
 * Administrative interface for On The Web module.
 */

/**
 * Settings form.
 */
function email_contactform_admin_settings() {
  $form['hourly_threshold'] = array('#type' => 'select',
    '#title' => t('Hourly threshold for Email contact forms'),
    '#options' => backdrop_map_assoc(array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50)),
    '#default_value' => config_get('email_contactform.settings', 'hourly_threshold'),
    '#description' => t('The maximum number of contact form submissions that can sent each hour.'),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submit handler for email_contactform_admin_settings().
 */
function email_contactform_admin_settings_submit(&$form, &$form_state) {
  config_set('email_contactform.settings', 'hourly_threshold', $form_state['values']['hourly_threshold']);
  backdrop_set_message(t('The configuration options have been saved.'));
}
