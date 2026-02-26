package org.ac;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

/**
 * Test suite for class Register
 */
public class RegisterTest extends Asserts {

    @Test
    public void setAndGetBit() {
        boolean[] bits = { true, true, false, true, true, false, true, false  };

        var register = new Register();
        for (int i = 0; i < bits.length; i++) {
            register.setBit(i, bits[i]);
            assertEquals(register.getBit(i), bits[i]);
        }
    }

    @Test
    public void set() {
        var register = new Register();
        assertSet(register, 0, "0000 0000");
        assertSet(register, 3, "0000 0011");
        assertSet(register, 255, "1111 1111");
        assertSet(register, 127, "0111 1111");

        assertSet(register, -1, "1111 1111");
        assertSet(register, -127, "1000 0001");
        assertSet(register, -128, "1000 0000");
    }

    @Test
    public void getUnsignedInt() {
        var register = new Register();
        assertGetUnsignedInt(register, 3);
        assertGetUnsignedInt(register, 127);
        assertGetUnsignedInt(register, 255);
        assertGetUnsignedInt(register, -1, 255);
    }

    @Test
    public void getInt() {
        var register = new Register();
        assertGetInt(register, 3);
        assertGetInt(register, 127);
        assertGetInt(register, 255, -1);
        assertGetInt(register, -1);
        assertGetInt(register, -127);
        assertGetInt(register, -128);
        assertGetInt(register, -129, 127);
    }
}
