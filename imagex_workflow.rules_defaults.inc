<?php
/**
 * @file
 * imagex_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function imagex_workflow_default_rules_configuration() {
  $items = array();
  $items['rules_imagex_workflow_draft_to_needs_review'] = entity_import('rules_config', '{ "rules_imagex_workflow_draft_to_needs_review" : {
      "LABEL" : "imagex_workflow_draft_to_needs_review",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "workbench" ],
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "draft" } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "6" : "6" } },
            "subject" : "[site:name] Moderation: [node:title]",
            "message" : "Hello, \\r\\n\\r\\nA new item is ready for moderation, and can be found under the \\u0027Needs Review\\u0027 tab of Workbench Moderation.\\r\\n\\r\\n[node:url]\\r\\n\\r\\n* You are receiving this as a member of the role: Content Moderator.",
            "from" : "[site:email]"
          }
        }
      ]
    }
  }');
  $items['rules_imagex_workflow_needs_review_to_draft'] = entity_import('rules_config', '{ "rules_imagex_workflow_needs_review_to_draft" : {
      "LABEL" : "imagex_workflow_needs_review_to_draft",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "Subject:   [site:name] Not Ready: [node:title] ",
            "message" : "Hello ,\\r\\n\\r\\nYour submission:  [node:title] has been reverted to Draft, and can be viewed at [node:url].  Please review revision notes for more information, and next steps.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_imagex_workflow_needs_review_to_published'] = entity_import('rules_config', '{ "rules_imagex_workflow_needs_review_to_published" : {
      "LABEL" : "imagex_workflow_needs_review_to_published",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "workbench" ],
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : " [site:name] Published: [node:title] ",
            "message" : "Hello ,\\r\\n\\r\\nYour submission:  [node:title] has been published, and can be viewed at [node:url].  \\r\\n",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_imagex_workflow_published_to_needs_review'] = entity_import('rules_config', '{ "rules_imagex_workflow_published_to_needs_review" : {
      "LABEL" : "imagex_workflow_published_to_needs_review",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "workbench" ],
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]\\r\\n",
            "subject" : " [site:name]  Reverted to \\u2018Needs Review\\u2019: [node:title] ",
            "message" : "Hello ,\\r\\n\\r\\nYour submission:  [node:title] has been reverted to \\u0027Needs Review\\u0027, and can be viewed at [node:url].  Please review revision notes for more information and next steps.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
