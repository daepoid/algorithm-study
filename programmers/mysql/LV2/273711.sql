 SELECT ITEM_ID, ITEM_NAME, RARITY
 FROM ITEM_INFO
 WHERE ITEM_ID IN (
     SELECT IT.ITEM_ID
     FROM ITEM_INFO AS II JOIN ITEM_TREE AS IT ON II.ITEM_ID = IT.PARENT_ITEM_ID
     WHERE II.RARITY = "RARE")
ORDER BY ITEM_ID DESC