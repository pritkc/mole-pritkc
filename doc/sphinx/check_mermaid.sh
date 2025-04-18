#!/bin/bash

# Script to verify Mermaid CLI installation

echo "Checking Mermaid CLI installation..."

# Check if mmdc is directly available
if command -v mmdc &> /dev/null; then
    echo "✅ mmdc is installed and available in PATH"
    echo "Version information:"
    mmdc --version
    exit 0
fi

# Check if npx is available and can run mmdc
if command -v npx &> /dev/null; then
    echo "🔍 mmdc not found directly, checking if it can be run via npx..."
    
    if npx --no-install mmdc --version &> /dev/null; then
        echo "✅ mmdc is available through npx"
        echo "Version information:"
        npx --no-install mmdc --version
        exit 0
    else
        echo "❌ mmdc is not available through npx without installation"
        
        # Try to install mermaid-cli temporarily and run it
        echo "🔄 Attempting to run mmdc with automatic installation..."
        if npx @mermaid-js/mermaid-cli --version &> /dev/null; then
            echo "✅ mermaid-cli can be used via 'npx @mermaid-js/mermaid-cli'"
            echo "Version information:"
            npx @mermaid-js/mermaid-cli --version
            echo "💡 To use in your build process, either:"
            echo "   - Install globally: npm install -g @mermaid-js/mermaid-cli"
            echo "   - Use 'npx @mermaid-js/mermaid-cli' command in your scripts"
            exit 0
        fi
    fi
fi

# If we got here, installation is needed
echo "❌ Mermaid CLI not found. To install it:"
echo ""
echo "1. Make sure Node.js and npm are installed:"
echo "   - Linux: sudo apt install nodejs npm"
echo "   - macOS: brew install node"
echo ""
echo "2. Install Mermaid CLI globally:"
echo "   npm install -g @mermaid-js/mermaid-cli"
echo ""
echo "3. Verify installation with:"
echo "   mmdc --version"
echo ""
echo "Alternatively, you can use npx without installing globally:"
echo "npx @mermaid-js/mermaid-cli --version"
exit 1 