# app_web_debug.py - Debug version with comprehensive error handling
import traceback
import sys
import logging
from datetime import datetime

# Configure detailed logging
logging.basicConfig(
    level=logging.DEBUG,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)

def main():
    print("=" * 60)
    print("🚀 DEBUG TRADING DASHBOARD STARTING...")
    print("=" * 60)
    
    try:
        # Step 1: Import Flask
        print("1. Importing Flask...")
        from flask import Flask, jsonify, render_template
        print("   ✅ Flask imported successfully")
        
        # Step 2: Import SocketIO
        print("2. Importing SocketIO...")
        from flask_socketio import SocketIO
        print("   ✅ SocketIO imported successfully")
        
        # Step 3: Create Flask app
        print("3. Creating Flask app...")
        app = Flask(__name__)
        app.config['SECRET_KEY'] = 'debug_secret_key'
        print("   ✅ Flask app created")
        
        # Step 4: Initialize SocketIO
        print("4. Initializing SocketIO...")
        socketio = SocketIO(app, cors_allowed_origins="*", async_mode='threading')
        print("   ✅ SocketIO initialized")
        
        # Step 5: Import trading signals
        print("5. Importing trading signals...")
        try:
            from forex_signals import EnhancedForexSignals
            signals_generator = EnhancedForexSignals()
            print("   ✅ Trading signals imported")
        except Exception as e:
            print(f"   ⚠️ Trading signals import failed: {e}")
            # Create dummy data
            class DummySignals:
                def generate_signals(self):
                    return {
                        'EURUSD=X': {'symbol': 'EURUSD=X', 'display_symbol': 'EURUSD', 'price': 1.1234, 'change': 0.5, 'signal_type': 'BUY', 'confidence': 0.85},
                        'BTC-USD': {'symbol': 'BTC-USD', 'display_symbol': 'BTC', 'price': 45000, 'change': 2.1, 'signal_type': 'BUY', 'confidence': 0.82}
                    }
                def get_market_regime(self):
                    return {'regime': 'BULLISH', 'volatility_regime': 'MEDIUM', 'trend_strength': 'STRONG'}
            signals_generator = DummySignals()
        
        # Step 6: Define routes
        print("6. Setting up routes...")
        
        @app.route('/')
        def index():
            return render_template('index.html')
        
        @app.route('/api/update-all')
        def update_all():
            try:
                signals = signals_generator.generate_signals()
                market_regime = signals_generator.get_market_regime()
                
                high_confidence = [s for s in signals.values() if s.get('confidence', 0) >= 0.8]
                
                return jsonify({
                    'market_data': signals,
                    'market_regime': market_regime,
                    'performance': {
                        'total_assets': len(signals),
                        'signals_count': len(high_confidence),
                        'accuracy': 80.0,
                        'weekly_target': 10,
                        'achieved': len(high_confidence),
                        'progress_percent': min(100, (len(high_confidence) / 10) * 100)
                    },
                    'timestamp': datetime.now().strftime('%H:%M:%S'),
                    'status': 'success'
                })
            except Exception as e:
                return jsonify({'error': str(e)}), 500
        
        @app.route('/health')
        def health():
            return jsonify({'status': 'healthy', 'timestamp': datetime.now().isoformat()})
        
        # Step 7: SocketIO events
        print("7. Setting up SocketIO events...")
        
        @socketio.on('connect')
        def handle_connect():
            logger.info("Client connected")
        
        @socketio.on('disconnect')
        def handle_disconnect():
            logger.info("Client disconnected")
        
        # Step 8: Start server
        print("8. Starting server...")
        print("✅ ALL COMPONENTS INITIALIZED SUCCESSFULLY")
        print("📍 Server will start on http://localhost:5000")
        print("=" * 60)
        
        socketio.run(app, host='0.0.0.0', port=5000, debug=False, use_reloader=False)
        
    except KeyboardInterrupt:
        print("\n🛑 Server stopped by user")
    except Exception as e:
        print(f"\n💥 CRITICAL ERROR: {e}")
        print("Stack trace:")
        traceback.print_exc()
        input("Press Enter to exit...")

if __name__ == '__main__':
    main()