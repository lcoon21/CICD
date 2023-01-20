#!/bin/bash

TELEGRAM_BOT_TOKEN="5852373783:AAGZWG2fffqe2_GDo-vfB6MF9lf_9n6HDDw"
CHAT_ID="-882644584"
TIME=10
URL="https://api.telegram.org/bot5852373783:AAGZWG2fffqe2_GDo-vfB6MF9lf_9n6HDDw/sendMessage"

if grep -q success status; then
    STATUS="Success"
else
    STATUS="Failed"
fi

TEXT="$1 Status: $STATUS %0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

curl -s --max-time $TIME -d "chat_id=-882644584&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
