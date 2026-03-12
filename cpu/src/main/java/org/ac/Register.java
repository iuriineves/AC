package org.ac;

/**
 * Class that models a CPU general-purpose register, a fast access memory used to store data to be supplied
 * to instruction execution units, such as the ALU.
 */
public class Register {

    /**
     * Size of the general-purpose registers, by default.
     */
    public static final int GP_REGISTER_SIZE = 8;

    /**
     * The bit representation of the register's contents
     */
    final boolean[] bits;

    /**
     * Create a register with a given size
     */
    public Register(int size) {
        this.bits = new boolean[size];
    }

    /**
     * Create a register with the CPU's default register size
     */
    public Register() {
        this(GP_REGISTER_SIZE);
    }

    public int size() {
        return this.bits.length;
    };

    private boolean bool(int integer) {
        return integer % 2 == 1;
    }

    public static int integer(boolean bool) {
        if (bool) return 1; else return 0;
    }

    private String str(boolean bool) {
        return integer(bool) + "";
    }

    /**
     *  Sets the bit at position index to value.
     */
    public void setBit(int index, boolean value) {
        if (index >= 0 && index < this.size()) {
            this.bits[index] = value;
        } else throw new IndexOutOfBoundsException();
    }

    /**
     * Returns the value of the bit at position index.
     */
    public boolean getBit(int index) {
        boolean bit;
        if (index >= 0 && index < this.size()) {
            bit = this.bits[index];
        } else throw new IndexOutOfBoundsException();
        return bit;
    }

    /**
     * Stores an integer using an N-bit two’s complement representation.
     */
    public void set(int value) {
        if (value < 0) value += 256;
        int i = 1;
        while (value >= 0 && i <= this.size()) {
            setBit(size() - i++, bool(value));
            value /= 2;
        }
    }

    /**
     * Interprets the register contents as an unsigned integer.
     */
    public int getUnsignedInt() {
        int u_int = 0;
        for (int i = 0; i < size(); i++) {
            boolean bit = getBit(i);
           if (bit) u_int += Math.pow(2, this.size() - (i + 1));
        }
        return u_int;
    }

    /**
     *  Interprets the register contents as a signed integer in two’s complement.
     */
    public int getInt() {
        int s_int = 0;
        for (int i = 1; i < size(); i++) {
            boolean bit = getBit(i);
            if (getBit(0)) bit = !bit;
            if (bit) s_int += Math.pow(2, this.size() - (i + 1));
        }
        if (getBit(0)) {
            s_int = (s_int + 1) * -1;
        }
        return s_int;
    }

    /**
     * Returns a string containing the register contents organized in groups of 4 bits separated by spaces (e.g., 1111 1110).
     */
    @Override
    public String toString() {
        String string = "";
        for (int i = 0; i < this.size(); i++) {
            boolean bit = getBit(i);
            string += str(bit);
            if ((i+1) % 4 == 0) {
                string += " ";
            }
        }
        return string.trim();
    }
}
