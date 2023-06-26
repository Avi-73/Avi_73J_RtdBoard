#include "icm20948_handler.h"

#include "../infrastructure/spicreatehandler.h"
#include "../interfaces/database/icm20948_handler.h"

std::shared_ptr<ICM20948HandlerDATABASE> NewICM20948HandlerDATABASE()
{
    std::shared_ptr<ICM> targetICM20948 = std::make_shared<ICM>();
    std::shared_ptr<ICM20948HandlerDATABASE> targetICM20948HandlerDATABASE = std::make_shared<ICM20948HandlerDATABASE>();
    targetICM20948HandlerDATABASE->icm20948 = targetICM20948;
    return targetICM20948HandlerDATABASE;
}

void ICM20948HandlerDATABASE::begin(std::shared_ptr<SPICREATE::SPICreate> targetSPI, int cs, uint32_t freq)
{
    icm20948->begin(targetSPI.get(), cs, freq);
}

uint8_t ICM20948HandlerDATABASE::WhoAmI()
{
    return icm20948->WhoAmI();
}

void ICM20948HandlerDATABASE::Get(int16_t *rx, uint8_t *rx_buf)
{
    icm20948->Get(rx, rx_buf);
}
