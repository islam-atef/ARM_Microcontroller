/**
  * @brief  Set the specific FLASH error flag.
  * @retval None
  */
static void FLASH_SetErrorCode(void)
{ 
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR) != RESET)
  {
   pFlash.ErrorCode |= HAL_FLASH_ERROR_WRP;
   
   /* Clear FLASH write protection error pending bit */
   __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_WRPERR);
  }
  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGAERR) != RESET)
  {
   pFlash.ErrorCode |= HAL_FLASH_ERROR_PGA;
   
   /* Clear FLASH Programming alignment error pending bit */
   __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_PGAERR);
  }
  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGPERR) != RESET)
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_PGP;
    
    /* Clear FLASH Programming parallelism error pending bit */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_PGPERR);
  }
  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGSERR) != RESET)
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_PGS;
    
    /* Clear FLASH Programming sequence error pending bit */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_PGSERR);
  }
#if defined(FLASH_SR_RDERR) 
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_RDERR) != RESET)
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_RD;
    
    /* Clear FLASH Proprietary readout protection error pending bit */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_RDERR);
  }
#endif /* FLASH_SR_RDERR */  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_OPERR) != RESET)
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_OPERATION;
    
    /* Clear FLASH Operation error pending bit */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPERR);
  }
}