#if defined(__MK64FX512__) || defined(__MK66FX1M0__)

#include "../../inc/MarlinConfig.h"

#if ENABLED(EEPROM_SETTINGS)

#include "../persistent_store_api.h"
#include <avr/eeprom.h>

bool PersistentStore::access_start() { return true; }
bool PersistentStore::access_finish() { return true; }

bool PersistentStore::write_data(int &pos, const uint8_t *value, size_t size, uint16_t *crc) {
  while (size--) {
    uint8_t * const p = (uint8_t * const)pos;
    uint8_t v = *value;
    // EEPROM has only ~100,000 write cycles,
    // so only write bytes that have changed!
    if (v != eeprom_read_byte(p)) {
      eeprom_write_byte(p, v);
      if (eeprom_read_byte(p) != v) {
        SERIAL_ECHO_START();
        SERIAL_ECHOLNPGM(MSG_ERR_EEPROM_WRITE);
        return true;
      }
    }
    crc16(crc, &v, 1);
    pos++;
    value++;
  };
  return false;
}

bool PersistentStore::read_data(int &pos, uint8_t* value, size_t size, uint16_t *crc, const bool writing/*=true*/) {
  do {
    uint8_t c = eeprom_read_byte((unsigned char*)pos);
    if (writing) *value = c;
    crc16(crc, &c, 1);
    pos++;
    value++;
  } while (--size);
  return false;
}

bool PersistentStore::write_data(const int pos, uint8_t* value, size_t size) {
  int data_pos = pos;
  uint16_t crc = 0;
  return write_data(data_pos, value, size, &crc);
}

bool PersistentStore::read_data(const int pos, uint8_t* value, size_t size) {
  int data_pos = pos;
  uint16_t crc = 0;
  return read_data(data_pos, value, size, &crc);
}

const size_t PersistentStore::capacity() {
  return E2END + 1;
}

#endif // EEPROM_SETTINGS
#endif // __MK64FX512__ || __MK66FX1M0__